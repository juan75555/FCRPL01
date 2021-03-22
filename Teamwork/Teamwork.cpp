#include <iostream>
//#include <bitset>
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);
char cadena[10];
unsigned int num1;
unsigned int num2;

int main()
{
    cout << "Introduce la cadena: ";
    cin >> cadena;
    cout << cadena << endl;

    cout << "Introduce el num1: ";
    cin >> num1;
    cout << num1 << endl;

    cout << "Introduce el num2: ";
    cin >> num2;
    cout << num2 << endl;

    //bitset<32> bs1(toBinary(num1));
    //cout << "binary:  " << bs1 << endl;
    //bitset<32> bs2(num1);
    //cout << "binary:  " << bs2 << endl;
    //
    //bitset<32> bs3(toBinary(num2));
    //cout << "binary:  " << bs3 << endl;
    //bitset<32> bs4(num2);
    //cout << "binary:  " << bs4 << endl;

    //return EXIT_SUCCESS;
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
    controlString(cadena);
    cout << ControlWithMask(num1,num2) << endl;
    cout << endl;
    return 0;
}
void controlString(char* cadena) {
    if (strcmp(cadena, "2dBkF998Y") == 0) {
        cout << "Acceso Permitido" << endl;
    }
    else {
        cout << "Acceso Denegado" << endl;
        exit(1);
    }
    if (strlen(cadena) < 10 && cadena[0] == cadena[9]) {
        cout << "Acceso Permitido" << endl;
    }
    else {
        cout << "Hubo un fallo" << endl;
        exit(1);
    }
}

int ControlWithMask(unsigned int num1,unsigned int num2) 
{
    cout << "Introduce el num1: ";
    cin >> num1;
    cout << num1 << endl;

    cout << "Introduce el num2: ";
    cin >> num2;
    cout << num2 << endl;

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
//string toBinary(int n)
//{
//    string r;
//    while (n != 0) {
//        r += (n % 2 == 0 ? "0" : "1");
//        n /= 2;
//    }
//    return r;
//}
