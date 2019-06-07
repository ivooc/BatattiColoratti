#ifndef __LOCALIZACAO_TP3___
#define __LOCALIZACAO_TP3___

class Localizacao {
    int Pino;
    static const int numReadings = 20;
    int total;
    int readIndex = 0;
    int readings[numReadings];
public:
    Localizacao(int pino);
    int RetornaSinal();
    bool EstaAlinhado();
};

#endif