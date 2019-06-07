#include "SeguidorDeLinha.h"
#include "Movimentacao.h"


void SeguidorDeLinha::Seguir (int esquerda, int direita){

	if(esquerda < LIMIAR_LINHA && direita < LIMIAR_LINHA){

		set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED); //SE OS DOIS ESTIVEREM DENTRO DA LINHA, O ROBO ANDARÁ PARA FRENTE
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);

	}else if(esquerda < LIMIAR_LINHA && direita > LIMIAR_LINHA){ // SE O LADO ESQUERDO ESTIVER FORA, O ROBO FARÁ UMA CURVA PARA DIREITA

		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED*TURNING_FACTOR);
		set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED*TURNING_FACTOR);
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);

	}else if (esquerda > LIMIAR_LINHA && direita < LIMIAR_LINHA){ //ANALOGO AO ANTERIOR, 

		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED*TURNING_FACTOR, DEFAULT_RIGHT_PWM_SPEED);
		set_speed(DEFAULT_LEFT_PWM_SPEED*TURNING_FACTOR, DEFAULT_RIGHT_PWM_SPEED);
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);

	}else { //SE OS 2 LADOS ESTIVEREM FORA DA LINHA O ROBO GIRA NO PRÓPRIO EIXO PROCURANDO UMA LINHA

		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, -DEFAULT_RIGHT_PWM_SPEED);
		LEFT_MOTOR->setSpeed(DEFAULT_LEFT_PWM_SPEED);
		RIGHT_MOTOR->run(RELEASE);
		RIGHT_MOTOR->setSpeed(DEFAULT_RIGHT_PWM_SPEED);
		RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
	}


}