#ifndef __MAQUINAESTADOS_H_
#define __MAQUINAESTADOS_H_

enum Estados
{
    INICIO,
    LOCALIZA,
    GIRA180,
    SEGUELINHA,
    OLHACOR,
    GIRABASE,
    ANDARETO,
    RECUA,
    GIRA60,
    GIRAMENOS60,
    RETORNABASE,
    RECUABASE,
    FIM
};

Estados Inicio();

Estados Localiza();

Estados Gira180();

Estados SegueLinha();

// IMPLEMENTAR CORES 
Estados OlhaCor();

Estados GiraBase();

Estados RetornaBase();

Estados RecuaBase();

Estados Recua();

Estados Gira60();

Estados GiraMenos60();

Estados AndaReto();

Estados MaquinaDeEstados(Estados estadoAtual, float tempo);

#endif