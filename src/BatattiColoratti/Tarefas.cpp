#include "Movimentacao.h"
#include "Configuracao.h"
#include "SeguidorDeLinha.h"
#include "Localizacao.h"
#include "Tarefas.h"
#include "Encoder.h"
#include "Menu.h"

int SegueLinhaFlag = 0;

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
  //encoderMotorDireita.ZeraVoltas();
  GiraHorario();
  unsigned long tempoSetPoint = millis();
  int sinal = 0;
  int timesChangedHigh = 0;
  int timesChangedLow = 0;
  //int voltasAteHigh = 0;
  //int voltasAteLow = 0;
  //int voltasDadas = 0;
  unsigned long tempoAteHigh = 0;
  unsigned long tempoAteLow = 0;
  unsigned long tempoPassado = 0;
  do
  {
    sinal = int(localizar.RetornaSinal());
    //voltasDadas = encoderMotorDireita.RetornaVolta();
    tempoPassado = millis() - tempoSetPoint;
    //lcd.setCursor(0, 0);
    //lcd.print(voltasDadas);
    //lcd.setCursor(8, 0);
    //lcd.print(encoderMotorEsquerda.RetornaVolta());
    if (sinal > LIMIAR_ALTO)
    {
      LIMIAR_ALTO = sinal;
      timesChangedHigh++; 
      //voltasAteHigh = voltasDadas;
      tempoAteHigh = tempoPassado;
    }
    else if (sinal < LIMIAR_BAIXO)
    {
      LIMIAR_BAIXO = sinal;
      timesChangedLow++;
      //voltasAteLow = voltasDadas;
      tempoAteLow = tempoPassado;
    }
    delay(1);
  } while (millis() - tempoSetPoint < TEMPO_PARA_360/*encoderMotorDireita.RetornaVolta() < VOLTAS_EM_360*/);
  para();
  delay(1000);
  //encoderMotorDireita.ZeraVoltas();
  //voltasDadas = 0;
  GiraHorario();
  tempoSetPoint = millis();
  if (timesChangedHigh > timesChangedLow)
  {
    while (millis() - tempoSetPoint < tempoAteHigh/*voltasDadas < voltasAteHigh*/)
    {
      //voltasDadas = encoderMotorDireita.RetornaVolta();
      delay(5);
    }
  }
  else
  {
    while (millis() - tempoSetPoint < tempoAteLow/*voltasDadas < voltasAteLow*/)
    {
      //voltasDadas = encoderMotorDireita.RetornaVolta();
      delay(5);
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

int Tarefas::SegueLinha(int flagAnterior){
      int readFlag = SeguidorDeLinha::Seguir(analogRead(LEFT_LINE_SENSOR_PIN), analogRead(RIGHT_LINE_SENSOR_PIN), flagAnterior);
      delay(100);
      return readFlag;
}

void Tarefas::SegueLinha(){
      int readFlag = SeguidorDeLinha::Seguir(analogRead(LEFT_LINE_SENSOR_PIN), analogRead(RIGHT_LINE_SENSOR_PIN), Tarefas::GetFlagLinha());
      delay(100);
      SetarFlagLinha(readFlag);
}

void Tarefas::SetarFlagLinha(int val)
{
  SegueLinhaFlag = val;
}

int Tarefas::GetFlagLinha()
{
  return SegueLinhaFlag;
}