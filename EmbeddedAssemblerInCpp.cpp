// EmbeddedAssembler.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;


int main(){
	int x;
	int a;
	int m;
	int resultado = 0;
	cout << "ingrese el valor de \"x\" para el cual se calculara el valor de arctan(x/a): ";
	cin >> x;
	cout << "ingrese el valor del divisor \"a\" para el cual se calculara el valor de arctan(x/a): ";
	cin >> a;
	cout << "ingrese el numero de terminos \"m\" que se usaran para calcular la serie: ";
	cin >> m;

	_asm {/*aquí irá todo el código ensamblador*/}

	cout << "el valor de arctan(" << x << "/" << a << ") "<< "es: " << resultado;

	getchar();
}
