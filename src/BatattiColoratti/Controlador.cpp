#include "Controlador.h" 
#include "Configuracao.h"

double Controlador::LeiDeControle(double erro){

  unsigned long now=millis();
  

  double dt = (now - this->TempoAnterior);

  this->SomatorioErro += erro * dt; 
  double dErr = (erro - this->ErroAnterior);

  double output = this->Kp*erro + this->Ki*SomatorioErro + this->Kd*dErr;

  this->TempoAnterior=now;
  this->ErroAnterior=erro;

  return(output);
}


void Controlador::Tunning(double _Kp, double _Ki = 0 , double _Kd = 0 ){

  this->Kp = _Kp;
  this->Ki = _Ki;
  this->Kd = _Kd;
  
}

Controlador::Controlador(double _Kp, double _Ki = 0 , double _Kd = 0 ){

  this->Kp = _Kp;
  this->Ki = _Ki;
  this->Kd = _Kd;
  
}
