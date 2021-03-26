#include <iostream>
#include <bitset>
using namespace std;
using std::cout; using std::endl;
using std::string; using std::bitset;
extern "C" bool IsValidAssembly(int a, int b, int c);

char controlString(char* cadena,char* cadena2) { //Esta es la primera función que recibe dos cadenas definidas en main()
    if (strcmp(cadena, "2dBkF998Y") == 0) {  //Este condicional imprime en la consola si la primera cadena es 2dBkF998Y
        cout << "Acceso Permitido" << endl;
        return true;
    }
    else {
        cout << "Acceso Denegado" << endl; //En caso contrario da como resultado un mensaje de Acceso Denegado y exit.
        return false; 
        exit(1);
    }
    if (strlen(cadena2) <= 10 && cadena2[0] == cadena2[9]) { //Este condicional comprueba si la longitud de la cadena 2 es <= que 10
        cout << "Acceso Permitido" << endl; //Ademas de comprobar si el elemento 0 (osea el primero) de la cadena2 es = al 9(el 10 en realidad).
        return true;
    }                                       //En caso afirmativo imprime Acceso Permitido y no nos echaría del programa.
    else {
        cout << "Hubo un fallo" << endl; //En caso contrario da como resultado un mensaje de Hubo un fallo y exit.
        return false;
        exit(1);
    }
}

int ControlWithMask(bitset<32> bs1,bitset<32> bs2,int decimal) //Esta función de tipo entero recibe dos numeros binarios de 32 bits ademas de un decimal.
{                                                              //Este número decimal serían los bits 5,6 y 7 del numero bs2 convertidos a decimal.
     if (bs1[5] == 0) {   //Este condicional comprueba si el bit 6 o la 5 posicion del numero 1 es igual a 0.
        cout << "Correcto" << endl; //En caso afirmativo imprime un mensaje de correcto en la pantalla.
        return true;
     }
    else {
        cout << "Hubo algún fallo" << endl; //En caso contrario imprime un mensaje de error y llama al exit.
        return false;
        exit(1);
    }
    if (bs1[12] == bs2[10]) { //Este condicional comprueba si la posición 12 o bit 13 del numero 1 es igual al bit 11 o posicion 10 del número 2.
        cout << "Correcto" << endl; //En caso afirmativo imprime un mensaje de correcto en la pantalla.
        return true;
    }
    else {
        cout << "Hubo algún fallo" << endl; //En caso contrario imprime un mensaje de error y llama al exit.
        return false;
        exit(1);
    }
    if (decimal == 3) { //Este condicional comprueba si las posiciones 5,6 y 7 del número 2 convertidas a decimal son igual a 3.
        cout << "Correcto" << endl; //En caso afirmativo imprime un mensaje de correcto en la pantalla.
        return true;
    }
    else {
        cout << "Hubo algún fallo" << endl; //En caso contrario imprime un mensaje de error y llama al exit.
        return false;
        exit(1);
    }
    return 0;
}

int CheckAsmControl(bitset<32> bs3,bitset<32> bs4,bitset<32> bs5) //Esta es la 3 función que recibe tres numeros binarios de 32 bits.
{
    int num180 = 10110100; //Declaramos num180 que es el 180 en binario.
    if ((bs3[0] == bs5[17]) && ((int)(bs3.to_ulong()) > num180)) //Este condicional comprueba si el bit 1 o posicion 0 del número 3 es igual del bit 18 o pos 17
    {                                                            //del numero binario5 ademas de cumplirse si y solo si se cumple que el numero 3 es mayor que 180.
        cout << "Bien" << endl; //En caso afirmativo imprime un mensaje de correcto en la pantalla.
        return 1;
        return true;
    }
    else 
    {
        cout << "Mal" << endl; //En caso contrario imprime un mensaje de error y llama al exit.
        return 0;
        return false;
    }
}

int CheckInlineAsmAccess(bitset<32> bs6, const char* bs) // Esta función de tipo entero recibe un número binario de 32 bits.
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
        if (bs6[14] == bs6[15] && bs6[15] != bs6[20]) { // Este condicional comprueba si el bit 13 del num6 es igual al 14 y si el bit 14 es igual al 19.
            cout << "Entrada correcta" << endl; //En caso afirmativo imprime un mensaje de correcto en la pantalla.
            return true;
        }
        else {
            cout << "Entrada incorrecta" << endl; //En caso contrario imprime un mensaje de error y llama al exit.
            return false;
            exit(1);
        } //Aqui esta __asm que es donde se implementa el ensamblador en linea el cual conseguimos al debuggear la función y acceder al desensamblado.
          //Lo tenemos comentado debido a que no funciona.

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

string Decimal_Binario(int n) //Esta función convierte los números enteros a números binarios.
{

    unsigned resto;
    unsigned int numBin = 0;
    unsigned int cont = 0;
    while (n > 0) {
        resto = n % 2;
        n = n / 2;
        numBin = numBin + resto * pow(10, cont);
        cont++;
    }
    return numBin;
}

int Binario_Decimal(int x,int decimal) { //Esta función convierte los números binarios a números decimales.
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


int main() //Esta es la parte principal del programa donde se ejecuta todo el codigo.
{
    char cadena[10]; //Aqui se declaran todas las variables que se usan.
    char cadena2[10];
    unsigned int num1;
    unsigned int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int decimal;
    const char* bs;
    cout << "Introduce una cadena: "; //Aqui se solicitan todas las variables necesarias.
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

  bitset<32> bs1(Decimal_Binario(num1)); //Aqui con la libreria bitset se convierten usando la función Decimal_Binario los numeros enteros a binarios de 32 bits.
  bitset<32> bs2(Decimal_Binario(num2));
  bitset<32> bs3(Decimal_Binario(num3));
  bitset<32> bs4(Decimal_Binario(num4));
  bitset<32> bs5(Decimal_Binario(num5));
  bitset<32> bs6(Decimal_Binario(num6));
  char x = bs2[4]+bs2[5]+bs2[6];

    Binario_Decimal(x,decimal);
    controlString(cadena,cadena2); //Aqui se hace llamada en main a la primera función que usa dos cadenas.
    ControlWithMask(bs1,bs2,decimal);//Aqui se hace llamada en main a la segunda función que usa dos num binarios y la conversion de tres bits de num2 a numero decimal.
    CheckAsmControl(bs3, bs4, bs5);//Aqui se hace llamada en main a la tercera función que usa tres números binarios.
    CheckInlineAsmAccess(bs6, num6, bs);//Aqui se hace llamada en main a la cuarta y ultima función que usa un número binario.

    if (controlString != false  && ControlWithMask != false && CheckAsmControl != false && CheckInlineAsmAccess != false) //Aqui se hace llamada a si las funciones retornaron o no falso.
        //En caso que no retornaran falso se imprime el mensaje de acceso permitido.
    {
        cout << "Acceso permitido" << endl;
    }
    else {
        cout << "Acceso bloqueado" << endl;
    }
    cout << endl;
    return 0;
}
