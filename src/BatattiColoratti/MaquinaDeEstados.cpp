#include "Tarefas.h"
#include "Movimentacao.h"
#include "Configuracao.h"
#include "MaquinaDeEstados.h"

Estados Inicio(){
	if(start == 1){
		return LOCALIZA;
	}else 
	return INICIO;
}

Estados Localiza(){
	Tarefas::AlinhaComLampada();
	return GIRA180;
}

Estados Gira180(){
	gira_sentido_antihorario(12);
	return SEGUELINHA;
}

Estados SegueLinha(){
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
Estados OlhaCor(){
	if(black){
		return RECUA; 
	}else {
		return GIRABASE;
	}
}

Estados GiraBase(){
	Tarefas::AlinhaComLampada();
	return RETORNABASE;
}

Estados RetornaBase(){
	anda(30);
	return RECUABASE;
}

Estados RecuaBase(){
	anda_re(10);
	return GIRA180;
}

Estados Recua(){
	anda_re(10);
	return GIRA60;
}

Estados Gira60(){
	gira_sentido_horario(4);
	return AndaRETO;
}

Estados GiraMenos60(){
	gira_sentido_antihorario(4);
	return SegueLINHA;
}

Estados AndaReto(){
	anda(4);
	return GIRAMENOS60;
}

Estados MaquinaDeEstados(Estados estadoAtual, float tempo){
	Estados proximoEstado = estadoAtual;
	if(tempo >= 60000 || estadoAtual == FIM)
	{
		return FIM;
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
}

