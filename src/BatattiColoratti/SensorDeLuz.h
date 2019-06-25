#ifndef __LIGHT_SENSOR__
#define __LIGHT_SENSOR__

void DetectaCorEmSerial();

bool DetectaObjeto();

bool AconteceuLargada();

char DetectaCor();

void SENSORDELUZ_SETUP();

#endif

// INICIO RASCUNHO
/*int flagVermelho=0;
setpoint = millis();
if(flagVermelho==0){

  while((millis() - setpoint) < 10000){
  if (DetectaObjeto())
    break;
  frente();
}
}


if(DetectaCor()=="AZUL"){

  gira(6); //90 graus
  flagVermelho=0;
}else if(DetectaCor()=="VERDE"){

  gira(18); //270 graus -> 90 pra esquerda -> ALTERAR PARA ESQUERDA
  flagVermelho=0;
  
}else if(DetectaCor()=="AMARELO"){

  gira(12) //180 graus
  flagVermelho=0;
  
}else if(DetectaCor()=="VERMELHO"){

  gira(24); //360 graus
  while(DetectaObjeto()==0){
    }
    flagVermelho=1; //flag vermelho evita que o bloco ande antes de realizar a detecção do próximo bloco
  
}


if(DetectaCor()*/
