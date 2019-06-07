#ifndef __CONTROLADOR_PID_ROBOTICA__
#define __CONTROLADOR_PID_ROBOTICA__


class Controlador
{
    double Kp = 0;
    double Kd = 0;
    double Ki = 0;
    unsigned long TempoAnterior = 0;
    double SomatorioErro = 0;
    double ErroAnterior = 0;
    public:
    
    Controlador(double _Kp, double _Ki = 0 , double _Kd = 0);
    
    void Tunning(double _Kp, double _Ki = 0 , double _Kd = 0 );

    double LeiDeControle(double erro);


};



#endif
