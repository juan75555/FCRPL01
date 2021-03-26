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

int CheckInlineAsmAccess(bitset<32> bs6,int num6, const char* bs)
{
    if (num6 == 262144) {
        bs = "00000000000001000000000000000000";
        if (bs[19] == bs[18] && bs[18] != bs[13]) {
            cout << "Entrada correcta" << endl;
            return true;
        }
        else {
            cout << "Entrada incorrecta" << endl;
            return false;
            exit(1);
        }
    }
    if (num6 == 12288) {
        bs = "00000000000000000011000000000000";
        if (bs[19] == bs[18] && bs[18] != bs[13]) {
            cout << "Entrada correcta" << endl;
            return true;
        }
        else {
            cout << "Entrada incorrecta" << endl;
            return false;
            exit(1);
        }
    }
    else {
        if (bs6[12] == bs6[13] && bs6[13] != bs6[18]) {
            cout << "Entrada correcta" << endl;
            return true;
        }
        else {
            cout << "Entrada incorrecta" << endl;
            return false;
            exit(1);
        }
    }

  

//   /* __asm 
 
//    {
//        push        13h
//        lea         eax, [ebp - 54h]
//        push        eax
//        lea         ecx, [bs6]
//        call        std::bitset<32>::operator[] (04026F0h)
//        mov         dword ptr[ebp - 1Ch], eax
//        mov         ecx, dword ptr[ebp - 1Ch]
//        mov         dword ptr[ebp - 20h], ecx
//        mov         dword ptr[ebp - 4], 0
//        mov         edx, dword ptr[ebp - 14h]
//        or edx, 1
//        mov         dword ptr[ebp - 14h], edx
//        mov         ecx, dword ptr[ebp - 20h]
//        call        std::bitset<32>::reference::operator bool(0402740h)
//        movzx       esi, al
//        push        12h
//        lea         eax, [ebp - 4Ch]
//        push        eax
//        lea         ecx, [bs6]
//        call        std::bitset<32>::operator[] (04026F0h)
//        mov         dword ptr[ebp - 24h], eax
//        mov         ecx, dword ptr[ebp - 24h]
//        mov         dword ptr[ebp - 28h], ecx
//        mov         dword ptr[ebp - 4], 1
//        mov         edx, dword ptr[ebp - 14h]
//        or edx, 2
//        mov         dword ptr[ebp - 14h], edx
//        mov         ecx, dword ptr[ebp - 28h]
//        call        std::bitset<32>::reference::operator bool(0402740h)
//        movzx       eax, al
//        cmp         esi, eax
//        jne         CheckInlineAsmAccess + 0F9h(04010F9h)
//        push        13h
//        lea         ecx, [ebp - 44h]
//        push        ecx
//        lea         ecx, [bs6]
//        call        std::bitset<32>::operator[] (04026F0h)
//        mov         dword ptr[ebp - 2Ch], eax
//        mov         edx, dword ptr[ebp - 2Ch]
//        mov         dword ptr[ebp - 30h], edx
//        mov         dword ptr[ebp - 4], 2
//        mov         eax, dword ptr[ebp - 14h]
//        or eax, 4
//        mov         dword ptr[ebp - 14h], eax
//        mov         ecx, dword ptr[ebp - 30h]
//        call        std::bitset<32>::reference::operator bool(0402740h)
//        movzx       esi, al
//        push        0Dh
//        lea         ecx, [ebp - 3Ch]
//        push        ecx
//        lea         ecx, [bs6]
//        call        std::bitset<32>::operator[] (04026F0h)
//        mov         dword ptr[ebp - 34h], eax
//        mov         edx, dword ptr[ebp - 14h]
//        or edx, 8
//        mov         dword ptr[ebp - 14h], edx
//        mov         ecx, dword ptr[ebp - 34h]
//        call        std::bitset<32>::reference::operator bool(0402740h)
//        movzx       eax, al
//        cmp         esi, eax
//        je          CheckInlineAsmAccess + 0F9h(04010F9h)
//        mov         dword ptr[ebp - 18h], 1
//        jmp         CheckInlineAsmAccess + 100h(0401100h)
//        mov         dword ptr[ebp - 18h], 0
//        mov         cl, byte ptr[ebp - 18h]
//        mov         byte ptr[ebp - 0Dh], cl
//        mov         edx, dword ptr[ebp - 14h]
//        and edx, 8
//        je          CheckInlineAsmAccess + 11Ah(040111Ah)
//        and dword ptr[ebp - 14h], 0FFFFFFF7h
//        lea         ecx, [ebp - 3Ch]
//        call        std::bitset<32>::reference::~reference(0402630h)
//        mov         dword ptr[ebp - 4], 1
//        mov         eax, dword ptr[ebp - 14h]
//        and eax, 4
//        je          CheckInlineAsmAccess + 135h(0401135h)
//        and dword ptr[ebp - 14h], 0FFFFFFFBh
//        lea         ecx, [ebp - 44h]
//        call        std::bitset<32>::reference::~reference(0402630h)
//        mov         dword ptr[ebp - 4], 0
//        mov         ecx, dword ptr[ebp - 14h]
//        and ecx, 2
//        je          CheckInlineAsmAccess + 150h(0401150h)
//        and dword ptr[ebp - 14h], 0FFFFFFFDh
//        lea         ecx, [ebp - 4Ch]
//        call        std::bitset<32>::reference::~reference(0402630h)
//        mov         dword ptr[ebp - 4], 0FFFFFFFFh
//        mov         edx, dword ptr[ebp - 14h]
//        and edx, 1
//        je          CheckInlineAsmAccess + 16Bh(040116Bh)
//        and dword ptr[ebp - 14h], 0FFFFFFFEh
//        lea         ecx, [ebp - 54h]
//        call        std::bitset<32>::reference::~reference(0402630h)
//        movzx       eax, byte ptr[ebp - 0Dh]
//        test        eax, eax
//        je          CheckInlineAsmAccess + 196h(0401196h)
//        push        offset std::endl<char, std::char_traits<char> >(0401EB0h)
//        push        4063C0h
//        mov         ecx, dword ptr[__imp_std::cout(0406060h)]
//        push        ecx
//        call        std::operator<<<std::char_traits<char> > (0401460h)
//        add         esp, 8
//        mov         ecx, eax
//        call        dword ptr[__imp_std::basic_ostream<char, std::char_traits<char> >::operator<< (0406048h)]
//        jmp         CheckInlineAsmAccess + 1BFh(04011BFh)
//        push        offset std::endl<char, std::char_traits<char> >(0401EB0h)
//        push        4063D4h
//        mov         edx, dword ptr[__imp_std::cout(0406060h)]
//        push        edx
//        call        std::operator<<<std::char_traits<char> > (0401460h)
//        add         esp, 8
//        mov         ecx, eax
//        call        dword ptr[__imp_std::basic_ostream<char, std::char_traits<char> >::operator<< (0406048h)]
//        push        1
//        call        dword ptr[__imp__exit(0406144h)]
//    }*/
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
    const char* bs;

    cout << "Introduce una cadena: ";
    cin >> cadena;

    cout << "Introduce otra cadena: ";
    cin >> cadena2;

    cout << "Introduce el num1 (entero positivo): ";
    cin >> num1;

    cout << "Introduce el num2 (entero positivo): ";
    cin >> num2;

    cout << "Introduce el num3 (entero): ";
    cin >> num3;

    cout << "Introduce el num4 (entero): ";
    cin >> num4;

    cout << "Introduce el num5 (entero): ";
    cin >> num5;

    cout << "introduce el num6 (entero): ";
    cin >> num6;

    bitset<32> bs1(Decimal_Binario(num1));
    bitset<32> bs2(Decimal_Binario(num2));
    bitset<32> bs3(Decimal_Binario(num3));
    bitset<32> bs4(Decimal_Binario(num4));
    bitset<32> bs5(Decimal_Binario(num5));
    bitset<32> bs6(Decimal_Binario(num6));
    char x = bs2[4] + bs2[5] + bs2[6];


    Binario_Decimal(x,decimal);
    controlString(cadena,cadena2); 
    ControlWithMask(bs1,bs2,decimal);
    CheckAsmControl(bs3, bs4, bs5);
    CheckInlineAsmAccess(bs6, num6,bs);
    if (controlString != false  && ControlWithMask != false && CheckAsmControl != false && CheckInlineAsmAccess != false) 
       
    {
        cout << "Acceso permitido" << endl;
    }
    else {
        cout << "Acceso bloqueado" << endl;
    }
    cout << endl;
    return 0;
}
