#include "Encoder.h"
#include "Configuracao.h"
#include "Arduino.h"

float Encoder::RetornaRPM()
{
	unsigned long int tempoAtual = millis();
	unsigned long int deltaTempo  = float(tempoAtual - this->TempoDesdeUltimoConsumo); 
	float  deltaRotacoes = this->CalculoVoltas(this->Voltas - this->VoltasDuranteUltimoConsumo);
	this->VoltasDuranteUltimoConsumo = this->Voltas;
	this->TempoDesdeUltimoConsumo = tempoAtual;
	return deltaRotacoes*60000.0/88.0/float(deltaTempo); // 60000   88 // 1916.92
}

float Encoder::CalculoVoltas(int v)
{
	return float(v)/float(NUMERO_DE_INTERRUPCOES_POR_VOLTA);
}

Encoder::Encoder(int pino):Pino(pino)
{
	TempoDesdeUltimoConsumo = millis();
}
