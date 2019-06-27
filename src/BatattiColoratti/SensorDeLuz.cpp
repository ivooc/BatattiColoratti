#include "SensorDeLuz.h"
#include "Arduino.h"
#include "Configuracao.h"

int INTENSIDADE_LUZ_AMBIENTE = 0;

void DetectaCorEmSerial(){
  String virg = " , ";
  
  Serial.flush();  

  // Acende os LEDs e mede os valores para cada cor e iluminação ambiente
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  delay(100);
  int environmentBrightness = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    HIGH);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  delay(100);
  int redReflected  = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   HIGH);
  delay(100);
  int blueReflected = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  HIGH);
  digitalWrite(BLUE_PIN,   LOW);
  delay(100);
  int greenReflected  = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  //delay(1000);
 
  // Subtrai a iluminação ambiente dos valores das cores
   int redOutput = redReflected - environmentBrightness;
  int greenOutput = greenReflected -  environmentBrightness;
  int blueOutput = blueReflected -  environmentBrightness;


 Serial.println(
   environmentBrightness + virg +
   redOutput + virg +
   blueOutput + virg +
   greenOutput + virg 

   );

  // Algoritmo que calcula a cor
  if(blueOutput > redOutput && blueOutput > greenOutput){
    if(blueOutput*0.7 > redOutput && blueOutput*0.7 > greenOutput){

        Serial.println("BLUE");
      
    }else{

      Serial.println("BLACK");
    }
     
  }else if(greenOutput > redOutput && greenOutput > blueOutput){

    Serial.println("GREEN");
  }else if(redOutput*0.55 > greenOutput){ //PARAMETRO RED YELLOW

    Serial.println("RED");

  }else if(redOutput*0.6 < blueOutput){ // PARAMETRO RED BLACK
      
    Serial.println("BLACK");
  }else {

    Serial.println("YELLOW");
  }
  
  delay(300);
  
}

bool DetectaObjeto(){

  int LUZ_ATUAL = analogRead(LDR_PIN);
  return (INTENSIDADE_LUZ_AMBIENTE - LUZ_ATUAL > THRESHOLD_OBSTACULO_DE_LUZ);
  //return (LUZ_ATUAL > THRESHOLD_OBSTACULO_DE_LUZ);
}

char DetectaCor(){

  // Acende os LEDs e mede os valores para cada cor e iluminação ambiente
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  delay(100);
  int environmentBrightness = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    HIGH);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  delay(100);
  int redReflected  = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   HIGH);
  delay(100);
  int blueReflected = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  HIGH);
  digitalWrite(BLUE_PIN,   LOW);
  delay(100);
  int greenReflected  = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  //delay(100);

  // Subtrai a iluminação ambiente dos valores das cores
   int redOutput = redReflected - environmentBrightness;
  int greenOutput = greenReflected -  environmentBrightness;
  int blueOutput = blueReflected -  environmentBrightness;
//ta

  // Algoritmo que calcula a cor
  if(blueOutput > redOutput && blueOutput > greenOutput){
    if(blueOutput*0.7 > redOutput && blueOutput*0.7 > greenOutput){

      return blue;
      
    }else{

      return black;
    }

  }else if(greenOutput > redOutput && greenOutput > blueOutput){
    return green;
  }else if(redOutput*0.55 > greenOutput){ //PARAMETRO RED YELLOW
    return red;
  }else if(redOutput*0.6 < blueOutput){ // PARAMETRO RED BLACK
    return black;
  }else {
    return yellow;
  }
  
}

void SENSORDELUZ_SETUP(){
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  INTENSIDADE_LUZ_AMBIENTE = analogRead(LDR_PIN);
  // initialize serial communication with computer:
  //digitalWrite(RED_PIN, HIGH);
  //digitalWrite(GREEN_PIN, HIGH);
  //digitalWrite(BLUE_PIN, HIGH);

}

bool AconteceuLargada()
{
  return digitalRead(LARGADA_PINO)==HIGH;
}
