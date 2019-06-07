#ifndef __LOCALIZACAO_TP3___
#define __LOCALIZACAO_TP3___

class Localizacao {
    int Pin;
    const int numReadings;
    int total;
    int readIndex = 0;
    int* readings = 0;
public:
    Localizacao(const int pin, const int numreadings = 20);
    float RetornaSinal();
    bool EstaAlinhado();
    ~Localizacao();
};

#endif