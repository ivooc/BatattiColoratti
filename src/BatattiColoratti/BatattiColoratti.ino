#include "Movimentacao.h"
#include "Configuracao.h"
#include "Encoder.h"
#include <LiquidCrystal.h>
#include "Arduino.h"
#include "Tarefas.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int cont = 0;
double rightVelocityOutput=0;
double leftVelocityOutput=0;

enum states {
  MAIN_1,
  MAIN_2,
  MAIN_3,
  LOC_1,
  LOC_2,
  LOC_3
};

states menu_state = MAIN_1;

int read_LCD_buttons() {
  int adc_key_in = analogRead(0);      // read the value from the sensor
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;

  return btnNONE;  // when all others fail, return this...
}


void rightMotorInterruptHandler()
{
  encoderMotorDireita.IncrementaVoltas();
}

void leftMotorInterruptHandler()
{
  encoderMotorEsquerda.IncrementaVoltas();
}

int state = 0;

// int read_LCD_buttons() {
//   int adc_key_in = analogRead(0);      // read the value from the sensor
//   if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result

//   if (adc_key_in < 50)   return btnRIGHT;
//   if (adc_key_in < 195)  return btnUP;
//   if (adc_key_in < 380)  return btnDOWN;
//   if (adc_key_in < 555)  return btnLEFT;
//   if (adc_key_in < 790)  return btnSELECT;

//   return btnNONE;  // when all others fail, return this...
// }

//unsigned long tempoAntes = 0;

void task(){
  Tarefas::ExploraAmbiente();
  delay(10);
}

void setup(){
  
  lcd.begin(16, 2);  
  /**/

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
  SETUP_MOVIMENTACAO();
  LEFT_MOTOR->setSpeed(DEFAULT_LEFT_PWM_SPEED);
  RIGHT_MOTOR->setSpeed(DEFAULT_RIGHT_PWM_SPEED);

  //Tarefas::ExploraAmbiente();
  //Tarefas::ProcuraMaximo();
  //tempoAntes = millis();
} 

void loop()
{
  Menu();
}


void Menu(){
  int button = 5;
  button = read_LCD_buttons();
  switch(menu_state){
    case MAIN_1:
      lcd.setCursor(0,0);
      lcd.print("Menu de Tarefas ");
      lcd.setCursor(0,1);
      lcd.print("1-L. 2-ID  3-M  ");
      if (button == btnRIGHT){
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      else if (button == btnDOWN){
        menu_state = LOC_1;
        delay(btnDELAY);
      }
      break;
    case MAIN_2:
      lcd.setCursor(0,0);
      lcd.print("Menu de Tarefas ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-ID. 3-M  ");
      if (button == btnRIGHT){
        menu_state = MAIN_3;
        delay(btnDELAY);
      }        
      else if (button == btnLEFT){
        menu_state = MAIN_1;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Id cor em exec. ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //MostraNoLCDCorDetectada();
        delay(1000);
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      break;
    case MAIN_3:
      lcd.setCursor(0,0);
      lcd.print("Menu de Tarefas ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-ID  3-M. ");
      if (button == btnLEFT){
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Multi em exec.  ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //ExploraAmbiente();
        menu_state = MAIN_3;
        delay(btnDELAY);
      }
      break;
    case LOC_1:
      lcd.setCursor(0,0);
      lcd.print("Locomocao       ");
      lcd.setCursor(0,1);
      lcd.print("1-L. 2-TR  3-Q  ");
      if (button == btnRIGHT){
        menu_state = LOC_2;
        delay(btnDELAY);
      }
      else if (button == btnUP){
        menu_state = MAIN_1;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Linha em exec.  ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        Tarefas::PercorreLinha(10);
        menu_state = LOC_1;
        delay(btnDELAY);
      }
      break;
    case LOC_2:
      lcd.setCursor(0,0);
      lcd.print("Locomocao       ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-TR. 3-Q  ");
      if (button == btnRIGHT){
        menu_state = LOC_3;
        delay(btnDELAY);
      }
      else if (button == btnLEFT){
        menu_state = LOC_1;
        delay(btnDELAY);
      }
      else if (button == btnUP){
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Triang. em exec.");
        lcd.setCursor(0,1);
        lcd.print("                ");
        Tarefas::PercorreTriangulo(10);
        menu_state = LOC_2;
        delay(btnDELAY);
      }
      break;
    case LOC_3:
      lcd.setCursor(0,0);
      lcd.print("Locomocao       ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-TR  3-Q. ");
      if (button == btnLEFT){
        menu_state = LOC_2;
        delay(btnDELAY);
      }
      else if (button == btnUP){
        menu_state = MAIN_3;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        int dist = selecionaDistancia();
        lcd.setCursor(0,0);
        lcd.print("Quadr. em exec. ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        Tarefas::PercorreQuadrado(dist);
        menu_state = LOC_3;
        delay(btnDELAY);
      }
      break;
  }
}



int selecionaDistancia()
{
  int dist = 0 ;
  while(true){
    int button = read_LCD_buttons();
    lcd.setCursor(0,0);
    lcd.print("Escolhe Dist");
    lcd.setCursor(0,1);
    lcd.print(dist);
    if (button == btnSELECT){
      return dist;
    }
    if(button == btnUP){
    
      dist+=1;
    }
    else if(button == btnDOWN){
      dist-=1;
    }
    delay(300);
  }
}