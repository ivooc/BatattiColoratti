#include "SeguidorDeLinha.h"
#include "Movimentacao.h"
#include "Configuracao.h"
#include "Menu.h"

int SeguidorDeLinha::Seguir (int esquerda, int direita, int flag){
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print(esquerda);
  lcd.setCursor(12, 1);
  lcd.print(direita);
	if(esquerda < LIMIAR_LINHA && direita < LIMIAR_LINHA){
    lcd.setCursor(0, 0);
    lcd.print("Reto");
		set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED); //SE OS DOIS ESTIVEREM DENTRO DA LINHA, O ROBO ANDARÁ PARA FRENTE
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
    LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
    return 0;

	}else if(esquerda < LIMIAR_LINHA && direita > LIMIAR_LINHA){ // SE O LADO ESQUERDO ESTIVER FORA, O ROBO FARÁ UMA CURVA PARA DIREITA
    lcd.setCursor(0, 0);
    lcd.print("Vira Direita");
		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED*TURNING_FACTOR);
		set_speed(DEFAULT_LEFT_PWM_SPEED, DEFAULT_RIGHT_PWM_SPEED*TURNING_FACTOR);
		RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
    LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
    return 2;

	}else if (esquerda > LIMIAR_LINHA && direita < LIMIAR_LINHA){ //ANALOGO AO ANTERIOR, 
    lcd.setCursor(0, 0);
    lcd.print("Vira Esquerda");
		//setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED*TURNING_FACTOR, DEFAULT_RIGHT_PWM_SPEED);
		set_speed(DEFAULT_LEFT_PWM_SPEED*TURNING_FACTOR, DEFAULT_RIGHT_PWM_SPEED);
		RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
    LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
    return 1;

	}else {
    
    if (flag == 1)
    {
    lcd.setCursor(0, 0);
    lcd.print("Reverse Esquerda");
      //setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, -DEFAULT_RIGHT_PWM_SPEED);
      GiraAntiHorarioComFator();
      return 1;
    }
    else
    {
    lcd.setCursor(0, 0);
    lcd.print("Reverse Direita");
      //setControledRPMSpeed(DEFAULT_LEFT_PWM_SPEED, -DEFAULT_RIGHT_PWM_SPEED);
      GiraHorarioComFator();
      return 2;
    }
		
	}


}
