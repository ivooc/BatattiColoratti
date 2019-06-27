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
} 

void loop()
{
  Menu();
}
