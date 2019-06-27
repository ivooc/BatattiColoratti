#include "Menu.h"
#include "Configuracao.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

TelasMenu TelaMenu = INICIAL;

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

}