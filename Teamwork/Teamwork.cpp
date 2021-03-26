#include <iostream>
#include <bitset>
using namespace std;
using std::cout; using std::endl;
using std::string; using std::bitset;
extern "C" bool IsValidAssembly(int a, int b, int c);

char controlString(char* cadena,char* cadena2) { 
    if (strcmp(cadena, "2dBkF998Y") == 0) {  
        cout << "Acceso Permitido" << endl;
        return true;
    }
    else {
        cout << "Acceso Denegado" << endl; 
        return false; 
        exit(1);
    }
    if (strlen(cadena2) <= 10 && cadena2[0] == cadena2[9]) { 
        cout << "Acceso Permitido" << endl; 
        return true;
    }                                       
    else {
        cout << "Hubo un fallo" << endl; 
        return false;
        exit(1);
    }
}

int ControlWithMask(bitset<32> bs1,bitset<32> bs2,int decimal) 
{                                                              
     if (bs1[5] == 0) {   
        cout << "Correcto" << endl; 
        return true;
     }
    else {
        cout << "Hubo algún fallo" << endl;
        return false;
        exit(1);
    }
    if (bs1[12] == bs2[10]) { 
        cout << "Correcto" << endl; 
        return true;
    }
    else {
        cout << "Hubo algún fallo" << endl; 
        return false;
        exit(1);
    }
    if (decimal == 3) { 
        cout << "Correcto" << endl; 
        return true;
    }
    else {
        cout << "Hubo algún fallo" << endl; 
        return false;
        exit(1);
    }
    return 0;
}

int CheckAsmControl(bitset<32> bs3,bitset<32> bs4,bitset<32> bs5) 
{
    int num180 = 10110100; 
    if ((bs4[0] == bs5[17]) && ((int)(bs3.to_ulong()) > num180)) 
    {                                                            
        cout << "Bien" << endl;
        return 1;
        return true;
    }
    else 
    {
        cout << "Mal" << endl; 
        return 0;
        return false;
    }
}

int CheckInlineAsmAccess(bitset<32> bs6) 
{
    if (bs6[14] == bs6[15] && bs6[15] != bs6[20]) { 
    cout << "Entrada correcta" << endl; 
    return true;
    }
else {
    cout << "Entrada incorrecta" << endl; 
    return false;
    exit(1);
} 
    return 0;
}

int Decimal_Binario(int n) 
{
    unsigned resto;
   unsigned int numBin = 0;
   unsigned int cont = 0 ;
   while (n > 0) {
       resto = n % 2;
       n = n / 2;
       numBin = numBin + resto * pow(10, cont);
       cont++;
   }
   return numBin;
}

int Binario_Decimal(int x,int decimal) { 
    int exp, digito;
    exp = 0;
    decimal = 0;
    while (((int)(x / 10)) != 0)
    {
        digito = (int)x % 10;
        decimal = decimal + digito * pow(2.0, exp);
        exp++;
        x = (int)(x / 10);
    }
    decimal = decimal + x * pow(2.0, exp);
    return decimal;
}


int main() 
{
    char cadena[10]; 
    char cadena2[10];
    unsigned int num1;
    unsigned int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int decimal;

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

    cout << "Introduce el num3 (entero): ";
    cin >> num3;
    cout << num3 << endl;

    cout << "Introduce el num4 (entero): ";
    cin >> num4;
    cout << num4 << endl;

    cout << "Introduce el num5 (entero): ";
    cin >> num5;
    cout << num5 << endl;
   
    cout << "introduce el num6 (entero): ";
    cin >> num6;
    cout << num6 << endl;

  bitset<32> bs1(Decimal_Binario(num1)); 
  bitset<32> bs2(Decimal_Binario(num2));
  bitset<32> bs3(Decimal_Binario(num3));
  bitset<32> bs4(Decimal_Binario(num4));
  bitset<32> bs5(Decimal_Binario(num5));
  bitset<32> bs6(Decimal_Binario(num6));
  char x = bs2[4]+bs2[5]+bs2[6];
    Binario_Decimal(x,decimal);
    controlString(cadena,cadena2); 
    ControlWithMask(bs1,bs2,decimal);
    CheckAsmControl(bs3, bs4, bs5);
    CheckInlineAsmAccess(bs6);

    if (controlString != false  && ControlWithMask != false && CheckAsmControl != false && CheckInlineAsmAccess != false) 
       
    {
        cout << "Acceso permitido" << endl;
    }
    cout << endl;
    return 0;
}
