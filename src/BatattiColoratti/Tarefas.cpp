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

void Tarefas::ProcuraMaximo()
{

}