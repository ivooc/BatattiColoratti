#include "Localizacao.h"
#include "Arduino.h"
//#include "Movimentacao.h"
#include "Configuracao.h"

Localizacao::Localizacao(const int pin, const int numreadings) : numReadings(numreadings)
{
    this->Pin = pin;
    this->readings = new int[numReadings];
    for (int i = 0; i < this->numReadings; i++) {
        this->readings[i] = 0;
    }
}

float Localizacao::RetornaSinal()
{
    this->total = this->total - readings[this->readIndex];
    int sig =  analogRead(this->Pino) - LIMIAR_DE_MODULARIZACAO;
    sig = (sig <= 0) ? -sig:sig;

    this->readings[this->readIndex] = sig;
    this->total = this->total + this->readings[this->readIndex];
    this->readIndex++;  
    if (this->readIndex >= this->numReadings) {
        this->readIndex = 0;
    }
    float value = float(this->total) / float(this->numReadings);
    return value;
}


bool Localizacao::EstaAlinhado()
{
    int sinalAnterior = 0;
    if (this->readIndex == 0)
    {
        sinalAnterior = readings[19];
    } 
    else
    {
        sinalAnterior = readings[this->readIndex -1];
    }
    
    if( this->RetornaSinal() < sinalAnterior)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

Localizacao::~Localizacao()
{
    delete[] this->readings;
    this->readings = NULL;
}
