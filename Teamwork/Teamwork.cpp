#include <iostream>
#include <bitset>
using namespace std;
extern "C" bool IsValidAssembly(int a, int b, int c);

void controlString(char* cadena,char* cadena2) {
    if (strcmp(cadena, "2dBkF998Y") == 0) {
        cout << "Acceso Permitido" << endl;
    }
    else {
        cout << "Acceso Denegado" << endl;
        exit(1);
    }
    if (strlen(cadena2) <= 10 && cadena2[0] == cadena2[9]) {
        cout << "Acceso Permitido" << endl;
    }
    else {
        cout << "Hubo un fallo" << endl;
        exit(1);
    }
}

int ControlWithMask(std::bitset<32> bs1, std::bitset<32> bs2)
{
   /* __asm{

   }*/
    /* if (bs1[26] == 0) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Hubo algún fallo" << endl;
        exit(1);
    }
    if (bs1[19] == bs2[21]) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Hubo algún fallo" << endl;
        exit(1);
    }*/
    return 0;
}

int CheckInlineAsmAccess(std::bitset<32> bs6) 
{
    if (bs6[19] == bs6[18] && bs6[19] != bs6[13]) 
    {
        cout << "Entrada correcta" << endl;
    }
    else
    {
        cout << "Entrada incorrecta" << endl;
        exit(1);
    }
    
    
    return 0;
}

string toBinary(int n)
{
    string r;
    while (n != 0) {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}

int main()
{
    char cadena[10];
    char cadena2[10];
    unsigned int num1;
    unsigned int num2;
    int num6;
    //int a;
    //int b;
    //int c;
    cout << "Introduce una cadena: ";
    cin >> cadena;
    cout << cadena << endl;

    cout << "Introduce otra cadena: ";
    cin >> cadena2;
    cout << cadena2 << endl;

    cout << "Introduce el num1 (entero positivo): ";
    cin >> num1;
    cout << num1 << endl;

    cout << "Introduce el num2 (entero positivo): ";
    cin >> num2;
    cout << num2 << endl;

 /*   cout << "Introduce el num3 (entero): ";
    cin >> a;
    cout << a << endl;

    cout << "Introduce el num4 (entero): ";
    cin >> b;
    cout << b << endl;

    cout << "Introduce el num5 (entero): ";
    cin >> c;
    cout << c << endl;*/
    
    cout << "introduce el num6 (entero): ";
    cin >> num6;
    cout << num6 << endl;
  bitset<32> bs1(toBinary(num1));
  bitset<32> bs2(toBinary(num2));
  bitset<32> bs6(toBinary(num6));
  

    controlString(cadena,cadena2);
    ControlWithMask(bs1,bs2);
    CheckInlineAsmAccess(bs6);
    cout << endl;
    return 0;
}
//__asm {
//        //    if (binary[19] == binary[18] && binary[19] /= binary[13]){
//        //        cout << "Entrada correcta" << endl;
//        //    }
//        //    else {
//        //        cout << "Entrada incorrecta" << endl;
//        //        exit(1)
//        //    }
//        //}
