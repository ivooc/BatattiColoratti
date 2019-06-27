#include "Movimentacao.h"
#include "Configuracao.h"
#include "Localizacao.h"
#include "Encoder.h"
#include "Tarefas.h"
#include "SensorDeLuz.h"
#include "MaquinaDeEstados.h"
#include "Menu.h"


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
  lcdPrintLinhaCIMA("mission passed");
  lcdPrintLinhaBAIXO("respect+");
} 

void loop()
{
  /*int estadoAtual = LOCALIZA;
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

  }*/
}
