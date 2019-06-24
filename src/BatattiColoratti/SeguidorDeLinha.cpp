#include "SeguidorDeLinha.h"
#include "Movimentacao.h"
#include "Configuracao.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd5(8, 9, 4, 5, 6, 7);

int SeguidorDeLinha::Seguir (int esquerda, int direita, int flag){
  lcd5.clear();
  lcd5.setCursor(0, 1);
  lcd5.print(flag);
  lcd5.setCursor(1, 0);
  lcd5.print(flag);
  Serial.println(flag);
	if(esquerda < LIMIAR_LINHA && direita < LIMIAR_LINHA){

    lcd5.setCursor(0, 0);
    lcd5.print("Reto");
		set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED); //SE OS DOIS ESTIVEREM DENTRO DA LINHA, O ROBO ANDARÁ PARA FRENTE
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
    LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
    return 0;

	}else if(esquerda < LIMIAR_LINHA && direita > LIMIAR_LINHA){ // SE O LADO ESQUERDO ESTIVER FORA, O ROBO FARÁ UMA CURVA PARA DIREITA
    lcd5.setCursor(0, 0);
    lcd5.print("Vira Direita");
		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED*TURNING_FACTOR);
		set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED*TURNING_FACTOR);
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
    LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
    return 2;

	}else if (esquerda > LIMIAR_LINHA && direita < LIMIAR_LINHA){ //ANALOGO AO ANTERIOR, 
    lcd5.setCursor(0, 0);
    lcd5.print("Vira Esquerda");
		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED*TURNING_FACTOR, DEFAULT_RIGHT_PWM_SPEED);
		set_speed(DEFAULT_LEFT_PWM_SPEED*TURNING_FACTOR, DEFAULT_RIGHT_PWM_SPEED);
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
    LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
    return 1;

	}else { //SE OS 2 LADOS ESTIVEREM FORA DA LINHA O ROBO GIRA NO PRÓPRIO EIXO PROCURANDO UMA LINHA
    
    if (flag == 1)
    {
    lcd5.setCursor(0, 0);
    lcd5.print("Reverse Esquerda");
      //setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, -DEFAULT_RIGHT_PWM_SPEED);
      GiraAntiHorario();
      return 1;
    }
    else
    {
    lcd5.setCursor(0, 0);
    lcd5.print("Reverse Direita");
      //setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, -DEFAULT_RIGHT_PWM_SPEED);
      GiraHorario();
      return 2;
    }
		
	}


}
