#include "Movimentacao.h"
#include "Configuracao.h"
#include "Localizacao.h"
#include "Encoder.h"
#include <LiquidCrystal.h>
//#include "Arduino.h"
#include "Tarefas.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int LIMIAR_ALTO = 512;
int LIMIAR_BAIXO = 512;
const int VOLTAS_EM_360 = 167;

int read_LCD_buttons() {
  int adc_key_in = analogRead(0);      // read the value from the sensor
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;

  return btnNONE;  // when all others fail, return this...
}

void rightMotorInterruptHandler()
{
  encoderMotorDireita.IncrementaVoltas();
}

void leftMotorInterruptHandler()
{
  encoderMotorEsquerda.IncrementaVoltas();
}

void task()
{
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.setCursor(2, 1);
  lcd.print(LIMIAR_ALTO);
  lcd.setCursor(8, 1);
  lcd.print("L:");
  lcd.setCursor(10, 1);
  lcd.print(LIMIAR_BAIXO);
  delay(3000);
  Localizacao localizar(DIFERENTIAL_SENSOR_PIN);
  localizar.begin();
  encoderMotorDireita.ZeraVoltas();
  GiraHorario();
  int sinal = 0;
  int timesChangedHigh = 0;
  int timesChangedLow = 0;
  int voltasAteHigh = 0;
  int voltasAteLow = 0;
  int voltasDadas = 0;
  do
  {
    sinal = int(localizar.RetornaSinal());
    voltasDadas = encoderMotorDireita.RetornaVolta();
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(voltasDadas);
    if (sinal > LIMIAR_ALTO)
    {
      LIMIAR_ALTO = sinal;
      lcd.setCursor(2, 1);
      lcd.print(LIMIAR_ALTO);
      timesChangedHigh++; 
      lcd.setCursor(6, 0);
      lcd.print(timesChangedHigh);
      voltasAteHigh = voltasDadas;
    }
    else if (sinal < LIMIAR_BAIXO)
    {
      LIMIAR_BAIXO = sinal;
      lcd.setCursor(10, 1);
      lcd.print(LIMIAR_BAIXO);
      timesChangedLow++;
      lcd.setCursor(9, 0);
      lcd.print(timesChangedHigh);
      voltasAteLow = voltasDadas;
    }
    delay(1);
  } while (encoderMotorDireita.RetornaVolta() < VOLTAS_EM_360);
  para();
  delay(3000);
  encoderMotorDireita.ZeraVoltas();
  voltasDadas = encoderMotorDireita.RetornaVolta();
  lcd.setCursor(0, 0);
  lcd.print(voltasDadas);
  lcd.print("                ");
  voltasDadas = 0;
  GiraHorario();
  if (timesChangedHigh > timesChangedLow)
  {
    while (voltasDadas < voltasAteHigh)
    {
      voltasDadas = encoderMotorDireita.RetornaVolta();
      lcd.setCursor(0, 0);
      lcd.print(voltasDadas);
    }
  }
  else
  {
    while (voltasDadas < voltasAteLow)
    {
      voltasDadas = encoderMotorDireita.RetornaVolta();
      lcd.setCursor(0, 0);
      lcd.print(voltasDadas);
    }
  }
  para();
}

Localizacao L(DIFERENTIAL_SENSOR_PIN);
int sinal = 0;
int voltasD = 0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
  SETUP_MOVIMENTACAO();
  LEFT_MOTOR->setSpeed(DEFAULT_LEFT_PWM_SPEED);
  RIGHT_MOTOR->setSpeed(DEFAULT_RIGHT_PWM_SPEED);
  L.begin();
} 

void loop()
{
  /*int button = read_LCD_buttons();
  if (button == btnRIGHT)
  {
    GiraHorario();
    do
    {
      sinal = int(L.RetornaSinal());
      lcd.setCursor(0, 0);
      lcd.print("    ");
      lcd.setCursor(0, 0);
      lcd.print(sinal);
      voltasD = encoderMotorDireita.RetornaVolta();
      lcd.setCursor(0, 1);
      lcd.print(voltasD);
      button = read_LCD_buttons();
    } while (button != btnLEFT);
    para();    
  }*/
  int button = read_LCD_buttons();
  if (button == btnRIGHT)
  {
    lcd.setCursor(0, 0);
    lcd.print("Exec. Alinh.    ");
    Serial.println("Executando Alinhamento...");
    task();
  }
  delay(10);
}
