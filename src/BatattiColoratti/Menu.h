#ifndef _MENU_H_
#define _MENU_H_

#include <LiquidCrystal.h>
#include <WString.h>

extern LiquidCrystal lcd;

enum TelasMenu {
  INICIAL,
  CALIBRACAO,
  LARGADA
};

int read_LCD_buttons();

void lcdPrintLinhaCIMA(char);
void lcdPrintLinhaCIMA(int);
void lcdPrintLinhaCIMA(long);
void lcdPrintLinhaCIMA(String);

void lcdPrintLinhaBAIXO(char);
void lcdPrintLinhaBAIXO(int);
void lcdPrintLinhaBAIXO(long);
void lcdPrintLinhaBAIXO(String);

void lcdClearLinhaCIMA();

void lcdClearLinhaBAIXO();

void Menu();

#endif