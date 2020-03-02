#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(){
	double x;
	double a;
	double m;
	double resultado = 0;
	cout << "ingrese el valor de \"x\" para el cual se calculara el valor de arctan(x/a): ";
	cin >> x;
	cout << "ingrese el valor del divisor \"a\" para el cual se calculara el valor de arctan(x/a): ";
	cin >> a;
	cout << "ingrese el numero de terminos \"m\" que se usaran para calcular la serie: ";
	cin >> m;

	for (int i = 0; i <= m; i++)
	{
		resultado = resultado + ((pow(-1, i)) / ((2 * i) + 1)) *(pow((x / a), ((2*i)+1)));
	}

	_asm
	{
		/*aqui va todo el codigo ensamblador*/
	}

	cout << "el valor de arctan(" << x << "/" << a << ") "<< "es: " << resultado;

	getchar();
}
