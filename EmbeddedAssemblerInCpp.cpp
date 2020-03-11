
#include <iostream>
#include <string>
using namespace std;

int main() {
	long double x;
	long double a;
	long int m;

	cout << "ingrese el valor de \"x\" para el cual se calculara arctan(x/a): ";
	cin >> x;
	

	cout << "ingrese el valor del divisor \"a\" para el cual se calculara arctan(x/a): ";
	cin >> a;
	

	cout << "ingrese el numero de terminos \"m\" que se usaran para calcular la serie: ";
	cin >> m;
	
	cout << "x=" << x << "\n";
	cout << "a=" << a << "\n";
	cout << "m=" << m << "\n";

	long double pot = -1;
	long double res = 1;
	long double resultado = 0;
	long double cociente;
	long int tempint;

	_asm {
		finit
		fld x						//*
		fld a						//*Con la FPU se calcula el valor de (x/a)
		fdiv						//*
		fstp cociente
		fwait
		//inicio while 1
		mov eax, m					//*
		inc eax						//*While1 irá desde 0 hasta m, por lo tanto el límite tendrá que ser m+1
		mov m, eax					//*
		
		mov ecx, 0					//inicializamos el contador ecx para el primer while.
		while1:	
		cmp ecx, m					//while1 va desde 0 hasta m
		jge fin_while1
			
			mov eax, 2				//*
			mov ebx, ecx			//*Calculamos el valor de 2n+1 en el registro eax
			mul ebx					//*
			inc eax					//*

			mov edx, 1				//edx es el contador de while2, comienza en 1 y va hasta 2n+1
			fld cociente

			while2:
			cmp edx, eax			//el segundo while va desde 1 hasta 2n+1
				jge fin_while2

				fld cociente		//*
				fmul				//*multiplicamos (x/a) por sí misma 2n+1 veces
				inc edx				//incrementamos el contador de while2
				jmp while2
			fin_while2:
			//fin while 2
			fld pot					//*
			fchs					//*Se le cambia el signo a 1, equivalente a (-1)^n
			fst pot					//*

			mov tempint, ecx		//*
			fild tempint			//*
			mov tempint, 2			//*
			fild tempint			//*
			fmul					//*calculamos 2n+1
			mov tempint, 1			//*
			fild tempint			//*
			fadd					//*	
			fdiv					//*
			fmul					//*

			fld resultado			//*
			fadd					//* resultado += (x/a)*(-1)^n/(2n+1)
			fstp resultado			//*

			inc ecx					//incrementamos el contador de while1
			jmp while1
		fin_while1:
		//fin while 1
		fwait
	}

	cout << "arctan(" << x << "/" << a << ") = " << resultado << "rad" << "\n";

	system("pause");
}
