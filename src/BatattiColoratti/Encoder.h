#ifndef __ENCODER__ROBOTICA_TP__
#define __ENCODER__ROBOTICA_TP__
/*

https://forum.arduino.cc/index.php?topic=41713.msg303026#msg303026

Class member functions that appear to take no arguments actually 
do take an invisible argument called this.  
The value of this is the instance of the object you're referring to.  
You can't attachInterrupt() to a class member function directly.  
You might be able to do it if the member function is static, 
but my approach is to have a global variable that is the instance, 
and the global service routine knows how to use the global variable.

*/
class Encoder
{

	int const Pino;
	unsigned long int Voltas = 0;
	unsigned long int VoltasDuranteUltimoConsumo = 0;
	unsigned long int TempoDesdeUltimoConsumo;
	public:

	Encoder(const int pino);

	void IncrementaVoltas() { Voltas++; };

	void operator++() { Voltas++; } 

	float RetornaRPM();

	void  ZeraVoltas()  { Voltas = 0; } 

	static float CalculoRPMdeVoltas(int);

	int RetornaVolta(){return Voltas;}

	float CalculoVoltas(int v);
};



#endif
