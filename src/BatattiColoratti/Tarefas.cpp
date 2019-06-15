#include "Movimentacao.h"
#include "Configuracao.h"
#include "SeguidorDeLinha.h"
#include "Localizacao.h"
#include "Tarefas.h"
#include "Encoder.h"

void Tarefas::ex1() {
  anda(30);
  gira_sentido_horario(12);
  anda(30);
  gira_sentido_horario(12);
  para();
}

void Tarefas::ex2() {
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(9);
  anda(42);
  gira_sentido_horario(9);
  para();
}

void Tarefas::ex3() {
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(6);
  para();
}

void Tarefas::ex4() {
  gira_sentido_horario(12);
  delay(1000);
  gira_sentido_horario(6);
}

void Tarefas::AlinhaComLampada()
{
  int LIMIAR_ALTO = 512;
  int LIMIAR_BAIXO = 512;
  Localizacao localizar(DIFERENTIAL_SENSOR_PIN);
  localizar.begin();
  encoderMotorDireita.ZeraVoltas();
  GiraHorario();
  int sinal = 0;
  int timesChangedHigh = 0;
  int timesChangedLow = 0;
  int voltasAteHigh = 0;
  int voltasAteLow = 0;
  int voltasDadas = 0;
  do
  {
    sinal = int(localizar.RetornaSinal());
    voltasDadas = encoderMotorDireita.RetornaVolta();
    if (sinal > LIMIAR_ALTO)
    {
      LIMIAR_ALTO = sinal;
      timesChangedHigh++; 
      voltasAteHigh = voltasDadas;
    }
    else if (sinal < LIMIAR_BAIXO)
    {
      LIMIAR_BAIXO = sinal;
      timesChangedLow++;
      voltasAteLow = voltasDadas;
    }
    delay(1);
  } while (encoderMotorDireita.RetornaVolta() < VOLTAS_EM_360);
  para();
  delay(1000);
  encoderMotorDireita.ZeraVoltas();
  voltasDadas = 0;
  GiraHorario();
  if (timesChangedHigh > timesChangedLow)
  {
    while (voltasDadas < voltasAteHigh)
    {
      voltasDadas = encoderMotorDireita.RetornaVolta();
    }
  }
  else
  {
    while (voltasDadas < voltasAteLow)
    {
      voltasDadas = encoderMotorDireita.RetornaVolta();
    }
  }
  para();
}

void Tarefas::PercorreLinha(int dist){
  anda(dist);
  gira_sentido_horario(12);
  anda(dist);
  gira_sentido_horario(12);
  para();
}

void Tarefas::PercorreQuadrado(int dist){
  anda(dist);
  gira_sentido_horario(6);
  anda(dist);
  gira_sentido_horario(6);
  anda(dist);
  gira_sentido_horario(6);
  anda(dist);
  gira_sentido_horario(6);
  para();
}

void Tarefas::PercorreTriangulo(int dist){
  anda(dist);
  gira_sentido_horario(6);
  anda(dist);
  gira_sentido_horario(9);
  anda(int(dist*1.4));
  gira_sentido_horario(9);
  para();
}

void Tarefas::ExploraAmbiente(){
  SeguidorDeLinha::Seguir(analogRead(LEFT_LINE_SENSOR_PIN), analogRead(RIGHT_LINE_SENSOR_PIN));

}