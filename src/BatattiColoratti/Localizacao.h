#ifndef __LOCALIZACAO_TP3___
#define __LOCALIZACAO_TP3___

class Localizacao {
    int Pin;
    const int numReadings;
    int total = 0;
    int readIndex = 0;
    int* readings = 0;
public:
    Localizacao(const int pin, const int numreadings = 20);
    void begin();
    float RetornaSinal();
    bool EstaAlinhado();
    ~Localizacao();
};

#endif