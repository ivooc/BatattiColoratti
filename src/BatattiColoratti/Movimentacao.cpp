#include "Movimentacao.h"
#include "Configuracao.h"
#include "Controlador.h" 
#include "Arduino.h"

// Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// static Adafruit_DCMotor *LEFT_MOTOR = AFMS.getMotor(LEFT_MOTOR_INPUT);
// static Adafruit_DCMotor *RIGHT_MOTOR = AFMS.getMotor(RIGHT_MOTOR_INPUT);  
// static Controlador controladorMotorDireita(1);  
// static Controlador controladorMotorEsquerda(1); 
// static Encoder encoderMotorEsquerda(LEFT_ENCODER_PIN); 
// static Encoder encoderMotorDireita(RIGHT_ENCODER_PIN);  


// void rightMotorInterruptHandler()
// {
//   encoderMotorDireita.IncrementaVoltas();
// }

// void leftMotorInterruptHandler()
// {
//   encoderMotorEsquerda.IncrementaVoltas();
// }

void SETUP_MOVIMENTACAO(){
  AFMS.begin();
  //set_speed();
  // attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  // attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
}


void para(){
  LEFT_MOTOR->run(RELEASE);
  RIGHT_MOTOR->run(RELEASE);
  delay(1);
}

void anda(int d)
{
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  delay(d);
}

void andaReComDelay()
{
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
}

void andaReComDelay(int d){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  d=d*TEMPO_ANDA;
  delay(d);
  para();
}

void gira_sentido_horario(double t){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  t=t*TEMPO_GIRA;
  delay(t);
  para();
}

void gira_sentido_antihorario(double t){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  t=t*TEMPO_GIRA;
  delay(t);
  para();
}

void set_speed(){
  set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED);
}

void set_speed(int left_speed, int right_speed ){
  LEFT_MOTOR->setSpeed(left_speed);
  RIGHT_MOTOR->setSpeed(right_speed);
}

void vira_esquerda(int d, int a){
  para();
  set_speed(DEFAULT_LEFT_LINEAR_SPEED*a,DEFAULT_RIGHT_LINEAR_SPEED);
  anda(d);
  set_speed(DEFAULT_LEFT_LINEAR_SPEED,DEFAULT_RIGHT_LINEAR_SPEED);

}

void vira_direita(int d, int a){
  para();
  set_speed(DEFAULT_LEFT_LINEAR_SPEED,DEFAULT_RIGHT_LINEAR_SPEED*a);
  anda(d);
  set_speed(DEFAULT_LEFT_LINEAR_SPEED,DEFAULT_RIGHT_LINEAR_SPEED);

}

double leftVelocityConstrainting(double desired)
{
  desired = desired > 255 ? 255: desired;
  return desired = desired > MIN_LEFT_VELOCITY  ? MIN_LEFT_VELOCITY  : desired;
}

double rightVelocityConstrainting(double desired)
{
  desired = desired > 255 ? 255: desired;
  return desired = desired > MIN_RIGHT_VELOCITY  ? MIN_RIGHT_VELOCITY  : desired;
}

void setControledRPMSpeed(int leftSpeed, int rightSpeed )
{

  int erroEsquerda = leftSpeed - encoderMotorDireita.RetornaRPM();
  int erroDireita = rightSpeed - encoderMotorDireita.RetornaRPM();
  int leftVelocityOutput  = controladorMotorEsquerda.LeiDeControle(erroEsquerda);
  int rightVelocityOutput = controladorMotorDireita.LeiDeControle(erroDireita);
  LEFT_MOTOR->setSpeed(leftVelocityConstrainting(leftVelocityOutput));
  RIGHT_MOTOR->setSpeed(rightVelocityConstrainting(rightVelocityOutput));
}

void setControledLinearSpeed(int leftSpeed, int rightSpeed ) // 1916.92 * 88.0 / 60000.0 
{

  int erroEsquerda = leftSpeed - encoderMotorDireita.RetornaRPM(); 
  int erroDireita = rightSpeed - encoderMotorDireita.RetornaRPM() ;
  int leftVelocityOutput  = controladorMotorEsquerda.LeiDeControle(erroEsquerda);
  int rightVelocityOutput = controladorMotorDireita.LeiDeControle(erroDireita);
  LEFT_MOTOR->setSpeed(leftVelocityConstrainting(leftVelocityOutput));
  RIGHT_MOTOR->setSpeed(rightVelocityConstrainting(rightVelocityOutput));
}
