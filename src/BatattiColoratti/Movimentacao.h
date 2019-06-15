#ifndef __COLORFUL_MOVIMENTACAO__
#define __COLORFUL_MOVIMENTACAO__


#include <Adafruit_MotorShield.h>
#include "Encoder.h"
#include "Configuracao.h"
#include "Controlador.h"

/* Move definitions to .cpp if you dont want instances to be available elsewhere*/
static Adafruit_MotorShield AFMS = Adafruit_MotorShield();
static Adafruit_DCMotor *LEFT_MOTOR  = AFMS.getMotor(LEFT_MOTOR_INPUT);
static Adafruit_DCMotor *RIGHT_MOTOR = AFMS.getMotor(RIGHT_MOTOR_INPUT);  
static Encoder encoderMotorEsquerda = new Encoder(LEFT_ENCODER_PIN);
static Encoder encoderMotorDireita  = new Encoder(RIGHT_ENCODER_PIN);
static Controlador controladorMotorDireita(1);  
static Controlador controladorMotorEsquerda(1); 

void SETUP_MOVIMENTACAO();

void para();

void anda(int d);

void andaReComDelay();

void GiraHorario();

void GiraAntiHorario();

void gira_sentido_horario(double t);

void anda_re(int d);

void gira_sentido_antihorario(double t);

void set_speed(int left_speed , int right_speed);

void set_speed();

void vira_esquerda(int d, int a); 

void vira_direita(int d, int a);

void setControledRPMSpeed(int , int);

void setControledLinearSpeed(int leftSpeed, int rightSpeed );


double rightVelocityConstrainting(double desired);


double leftVelocityConstrainting(double desired);

// void leftMotorInterruptHandler();

// void rightMotorInterruptHandler();

#endif 
