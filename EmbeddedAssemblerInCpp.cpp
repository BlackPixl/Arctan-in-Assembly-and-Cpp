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
	cout << "x=" << x << "\n";
	
	cout << "ingrese el valor del divisor \"a\" para el cual se calculara el valor de arctan(x/a): ";
	cin >> a;
	cout << "a=" << a << "\n";
	
	cout << "x/a=" << x / a << "\n";
	
	cout << "ingrese el numero de terminos \"m\" que se usaran para calcular la serie: ";
	cin >> m;
	cout << "m=" << m << "\n";
	
	double num = x / a;
	double res = 1;
	for (int i = 1; i <= m; i++)
	{
		res = -1 * res;
	}

	cout << "resultado de -1^m: " << res << "\n";

	res = 1;
	for (int i = 1; i <= ((2*m)+1); i++)
	{
		res = res * num;
	}


	cout << "resultado de (x/a)^(2m+1): " << res << "\n";

	cout << "resultado de 1/(2m+1): " << 1 / ((2 * m) + 1) << "\n";

	_asm
	{
		/*aqui va todo el codigo ensamblador*/
	}

	system("pause");
}
