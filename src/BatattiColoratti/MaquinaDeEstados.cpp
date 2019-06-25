#include "Tarefas.h"
#include "Movimentacao.h"
#include "Configuracao.h"
#include "SensorDeLuz.h"
#include "MaquinaDeEstados.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd9(8, 9, 4, 5, 6, 7);

//int SegueLinha_flag = 0 ;
/*
int Inicio(){

	if(start == 1){

		return LOCALIZA;
	}else 

	return INICIO;
}
*/


int Localiza(){

	Tarefas::AlinhaComLampada();
	delay(1000);
	return GIRA180;
}

int Gira180(){

	gira_sentido_antihorario(12);

	return SEGUELINHA;
}


int SegueLinha(){
	lcd9.begin(16, 2);
	lcd9.setCursor(8, 1);
	if(DetectaObjeto()){
		lcd9.print("DETECTEI");
		para();
		return OLHACOR;
	}else {
		Tarefas::SegueLinha();		 
	}
	delay(10);
	return SEGUELINHA;
}

// IMPLEMENTAR CORES 
int OlhaCor(){


  	digitalWrite(RED_PIN, LOW);
  	digitalWrite(GREEN_PIN, LOW);
  	digitalWrite(BLUE_PIN, LOW);
  	delay(100);


	char cor = DetectaCor();

	digitalWrite(RED_PIN, HIGH);
  	digitalWrite(GREEN_PIN, HIGH);
  	digitalWrite(BLUE_PIN, HIGH);
  	delay(10);
	
	if(cor == black || cor == yellow){

		return RECUA; 
	}else {

		return GIRABASE;
	}

}


int GiraBase(){

	Tarefas::AlinhaComLampada();

	return RETORNABASE;
}


int RetornaBase(){

	anda(30);

	return RECUABASE;
}

int RecuaBase(){

	anda_re(10);

	return GIRA180;
}



int Recua(){

	anda_re(10);

	return GIRA60;
}

int Gira60(){

	gira_sentido_horario(4);

	return ANDARETO;
}

int GiraMenos60(){

	gira_sentido_antihorario(4);

	return SEGUELINHA;
}


int AndaReto(){


	anda(4);

	return GIRAMENOS60;
}

int MaquinaDeEstados(int estadoAtual){

  int proximoEstado;

	switch(estadoAtual) {

	//	case INICIO:
		//	proximoEstado = Inicio();
		//	break;
		case LOCALIZA:
			proximoEstado = Localiza();
			break; 
		case GIRA180:
			proximoEstado = Gira180();
			break;
		case SEGUELINHA:
			proximoEstado = SegueLinha();
			break;
		case GIRABASE:
			proximoEstado = GiraBase();
			break; 
		case RETORNABASE:
			proximoEstado = RetornaBase();
			break;
		case RECUABASE:
			proximoEstado = RecuaBase();
			break;
		case RECUA:
			proximoEstado = Recua();
			break; 
		case GIRA60:
			proximoEstado = Gira60();
			break;
		case ANDARETO:
			proximoEstado = AndaReto();
			break; 
		case GIRAMENOS60:
			proximoEstado = GiraMenos60();
			break;	
		case OLHACOR:
			proximoEstado = OlhaCor();
			break;			 


	}


return proximoEstado;

}
