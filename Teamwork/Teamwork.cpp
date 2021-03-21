#include <iostream>
#include <vector>
using namespace std;
//extern "C" bool IsValidAssembly(int a, int b, int c);
//vector<string>cadena(20);
char cadena[10];
int main()
{
	unsigned int num1;
    unsigned int num2;
	cout << "Introduce la cadena: ";
	cin >> cadena;
	cout << cadena << endl;

	cout << "Introduce el num1: ";
	cin >> num1;
	cout << num1 << endl;

	cout << "Introduce el num2: ";
	cin >> num2;
	cout << num2 << endl;
	
	int decimal1;
	short binario1[32];
    decimal1 = num1;

	for (int i = 0; i < 8; i++)
	{
		binario1[i] = decimal1 % 2;
		decimal1 /= 2;

	}

	for (int i = 7; i >= 0; i--)
	{
		cout << binario1[i];
	}
	cout << endl;
	return 0;
}
void ControlString(cadena)
	{
		if (strcmp(cadena) == "2dBkF998Y"); {
			cout << "Acceso Correcto" << endl;
		}
		else {
			cout << "Acceso Denegado" << endl;
			exit()
		}
		if else (strlen(cadena) < 10)& (cadena[0] == cadena[9]); {
			cout << "Acceso Correcto" << endl;
		}
	    else {
	        cout << "Hubo un fallo" << endl;
	        exit()
        }
}


//
//void ControlWithMask(int num1,int num2) {
//
//}

//int Decimal_Binario(int num1, int num2) {
//	int decimal1;
//	int decimal2;
//	short binario1[32];
//	short binario2[32];
//	decimal1 = num1;
//	decimal2 = num2;
//	for (int i = 0; i < 8; i++)
//	{
//		binario1[i] = decimal1 % 2;
//		decimal1 /= 2;
//		binario2[i] = decimal2 % 2;
//		decimal2 /= 2;
//	}
//
//	for (int i = 7; i >=0; i--)
//	{
//		cout << binario1[i];
//		cout << binario2[i];
//	}
//	cout << endl;
//	return 0;
//}
