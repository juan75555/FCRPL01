#include <iostream>
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);

void controlString(char* cadena) {
    if (strcmp(cadena, "2dBkF998Y") == 0) {
        cout << "Acceso Permitido" << endl;
    }
    else {
        cout << "Acceso Denegado" << endl;
        exit(1);
    }
    if (strlen(cadena) <= 10 && cadena[0] == cadena[9]) {
        cout << "Acceso Permitido" << endl;
    }
    else {
        cout << "Hubo un fallo" << endl;
        exit(1);
    }
}

int ControlWithMask(unsigned int num1,unsigned int num2) 
{

    int decimal1;
    int decimal2;
    short binario1[32];
    short binario2[32];
    decimal1 = num1;
    decimal2 = num2;

    for (int i = 0; i < 8; i++)
    {
        binario1[i] = decimal1 % 2;
        decimal1 /= 2;

    }
    for (int a = 0; a < 8; a++)
    {
        binario2[a] = decimal2 % 2;
        decimal2 /= 2;

    }
    for (int i = 7; i >= 0; i--)
    {
        cout << binario1[i];
    }
    for (int a = 7; a >= 0; a--)
    {
        cout << binario2[a];
    }
    if (binario1[26] == 0) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Hubo algún fallo" << endl;
        exit(1);
    }
    if (binario1[19] == binario2[21]) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Hubo algún fallo" << endl;
        exit(1);
    }
}

int CheckInlineAsmAccess() 
{
    __asm {

  }
}

int main()
{
    char cadena[10];
    unsigned int num1;
    unsigned int num2;
    int a;
    int b;
    int c;
    cout << "Introduce la cadena: ";
    cin >> cadena;
    cout << cadena << endl;

    cout << "Introduce el num1 (entero positivo): ";
    cin >> num1;
    cout << num1 << endl;

    cout << "Introduce el num2 (entero positivo): ";
    cin >> num2;
    cout << num2 << endl;

    cout << "Introduce el num3 (entero): ";
    cin >> a;
    cout << a << endl;

    cout << "Introduce el num4 (entero): ";
    cin >> b;
    cout << b << endl;

    cout << "Introduce el num5 (entero): ";
    cin >> c;
    cout << c << endl;

    controlString(cadena);
    ControlWithMask(num1, num2);
    cout << endl;
    return 0;
}
