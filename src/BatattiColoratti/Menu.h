#ifndef _MENU_H_
#define _MENU_H_

enum TelasMenu {
  INICIAL,
  CALIBRACAO,
  LARGADA
};

int read_LCD_buttons();

void Menu();

#endif