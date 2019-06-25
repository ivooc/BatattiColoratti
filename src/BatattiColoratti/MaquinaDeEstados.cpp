#include "Tarefas.h"
#include "Movimentacao.h"
#include "Configuracao.h"

#define INICIO 1 
#define LOCALIZA 2
#define GIRA180 3 
#define SEGUELINHA 4
#define OLHACOR 5
#define GIRABASE 6
#define ANDARETO 7
#define RECUA 8 
#define GIRA60 9 
#define GIRAMENOS60 10  
#define RETORNABASE 11 
#define RECUABASE 12

int Inicio(){

	if(start == 1){

		return LOCALIZA;
	}else 

	return INICIO;
}

int Localiza(){

	Tarefas::AlinhaComLampada();

	return GIRA180;
}

int Gira180(){

	gira_sentido_antihorario(12);

	return SEGUELINHA;
}


int SegueLinha(){

	if(DetectaBloco()){
		para();
		return OLHACOR;
		// zerar variaveis globais de SegueLinha caso saia do estado SegueLinha!! 
	}else {

		Tarefas::SegueLinha();
	}

	return OLHACOR;
}

// IMPLEMENTAR CORES 
int OlhaCor(){

	if(black){

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

	return AndaRETO;
}

int GiraMenos60(){

	gira_sentido_antihorario(4);

	return SegueLINHA;
}


int AndaReto(){


	anda(4);

	return GIRAMENOS60;
}

int MaquinaDeEstados(int estadoAtual, float tempo){


	if(tempo > 60000){

		return -1;
	}
	switch(estadoAtual) {

		case INICIO:
			proximoEstado = Inicio();
			break;
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


	}


return proximoEstado;
