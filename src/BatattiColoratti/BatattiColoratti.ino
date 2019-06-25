#include "Movimentacao.h"
#include "Configuracao.h"
#include "Localizacao.h"
#include "Encoder.h"
#include <LiquidCrystal.h>
//#include "Arduino.h"
#include "Tarefas.h"
#include "SensorDeLuz.h"
#include "MaquinaDeEstados.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

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


void setup()
{
  
  lcd.begin(16, 2);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
  SENSORDELUZ_SETUP();
  SETUP_MOVIMENTACAO();
  LEFT_MOTOR->setSpeed(DEFAULT_LEFT_PWM_SPEED);
  RIGHT_MOTOR->setSpeed(DEFAULT_RIGHT_PWM_SPEED);
  

} 

void loop()
{
  int estadoAtual = LOCALIZA;
  int button = 5;
  button = read_LCD_buttons();
  lcd.setCursor(0, 0);
  lcd.print("Liguei");
  if (button == btnRIGHT)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aguardando Partida");
    int start = analogRead(LDR_LARGADA);
    while(start < 700){
      start = analogRead(LDR_LARGADA);
      Serial.println(start);
      }
  
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Luz detectada");
      double startTime = millis();
      double elapsedTime = 0;
      elapsedTime = millis() - startTime;
      while(elapsedTime<60000)
      {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print(estadoAtual);
        estadoAtual = MaquinaDeEstados(estadoAtual);  
        elapsedTime = millis() - startTime;
      }

      para();
   
    
  }
}


void testeLArgada()
{
  while(true){
    Serial.println(AconteceuLargada());
  }
}
