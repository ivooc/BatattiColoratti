#include "Menu.h"
#include "Configuracao.h"
#include "SensorDeLuz.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

TelasMenu TelaMenu = INICIAL_pg1;

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

void lcdPrintLinhaCIMA(char param) {
    lcd.setCursor(0, 0);
    lcd.print(param);
}
void lcdPrintLinhaCIMA(int param) {
    lcd.setCursor(0, 0);
    lcd.print(param);
}
void lcdPrintLinhaCIMA(long param) {
    lcd.setCursor(0, 0);
    lcd.print(param);
}
void lcdPrintLinhaCIMA(String param) {
    lcd.setCursor(0, 0);
    lcd.print(param);
}


void lcdPrintLinhaBAIXO(char param) {
    lcd.setCursor(0, 1);
    lcd.print(param);
}
void lcdPrintLinhaBAIXO(int param) {
    lcd.setCursor(0, 1);
    lcd.print(param);
}
void lcdPrintLinhaBAIXO(long param) {
    lcd.setCursor(0, 1);
    lcd.print(param);
}
void lcdPrintLinhaBAIXO(String param) {
    lcd.setCursor(0, 1);
    lcd.print(param);
}

void lcdClearLinhaCIMA() {
    lcd.setCursor(0, 0);
    lcd.print("                ");
}

void lcdClearLinhaBAIXO() {
    lcd.setCursor(0, 1);
    lcd.print("                ");
}


void Menu() {
    int button = 5;
    button = read_LCD_buttons();
    switch(TelaMenu) {
        case INICIAL_pg1:
            lcdPrintLinhaCIMA("Menu Inicial");
            lcd.setCursor(13, 0);
            lcd.print(TelaMenu);
            lcdPrintLinhaBAIXO("  1-Calibrar   >");
            if (button == btnRIGHT){
                TelaMenu = INICIAL_pg2;
                delay(btnDELAY);
            }
            else if (button == btnDOWN){
                TelaMenu = CALIBRACAO;
                delay(btnDELAY);
            }
            break;
        case INICIAL_pg2:
            lcdPrintLinhaCIMA("Menu Inicial");
            lcd.setCursor(13, 0);
            lcd.print(TelaMenu);
            lcdPrintLinhaBAIXO("< 2-Ag. Largada ");
            if (button == btnLEFT){
                TelaMenu = INICIAL_pg1;
                delay(btnDELAY);
            }
            else if (button == btnSELECT){
                TelaMenu = CALIBRACAO;
                delay(btnDELAY);
            }
            break;
        case CALIBRACAO:
            lcdPrintLinhaCIMA("Calibracao  ");
            lcd.setCursor(13, 0);
            lcd.print(TelaMenu);
            lcdPrintLinhaBAIXO("Press. Select  ^");
            if (button == btnUP){
                TelaMenu = INICIAL_pg1;
                delay(btnDELAY);
            }
            else if (button == btnSELECT){
                lcdClearLinhaBAIXO();
                lcdPrintLinhaBAIXO("Calibrando...");
                delay(1000);
                setIntensidadeLuzAmbiente();
                lcdClearLinhaCIMA();
                lcdPrintLinhaCIMA("Calibrado!");
                lcd.setCursor(11, 0);
                lcd.print(getIntensidadeLuzAmbiente());
                lcdClearLinhaBAIXO();
                lcdPrintLinhaBAIXO("Pronto partida");
                delay(3000);
                TelaMenu = INICIAL_pg2;
            }
            break;
        case LARGADA:
            break;
    }
}