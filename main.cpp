#include <iostream>
#include <stdlib.h>
#include <algorithm> //Libreria para convertir contenido de cadenas a mayusculas
#include <cstdlib>   // rand, srand
#include <ctime>     // time

using namespace std;

// Variables globales
int intento = 1;
bool adivino = false;

// Funciones externas
void comparar_cadenas(string buscado, string ingresado)
{
    int tope = buscado.length();
    bool encontrado = false;
    int lc = 0; // letras correctas
    int pc = 0; // posiciones correctas
    int ic = 0;
    if (tope == ingresado.length())
    {
        if (buscado == ingresado)
        {
            cout << "Correcto!" << endl;
            adivino = true;
        }
        else
        {
            for (int i=0; i<tope; i++)
            {
                encontrado = false;
                for (int j=0; j<tope; j++)
                {
                    if (ingresado[i] == buscado[j])
                    {
                        if (i==j)
                            pc++;
                        else
                            lc++;
                        encontrado = true;
                    }
                }
                if (encontrado == false)
                    ic++;
            }
            if (pc>0)
                cout << "Tienes " << pc << " letra(s) correcta(s) en la posicion correcta" << endl;
            if (lc>0)
                cout << "Tienes " << lc << " letra(s) correcta(s) en posicion incorrecta" << endl;
            if (ic>0)
                cout << "Tienes " << ic << " letra(s) incorrecta(s)" << endl;
            intento++;
        }
    }
    else
    {
        cout << "Debe ingresar " << buscado.length() << " letras" << endl;
        intento++;
    }
}

char obtener_random() {
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char s = alphanum[rand() % (sizeof(alphanum) - 1)];
    return s;
}

// Principal
int main()
{
    string opc;
    do
    {
        string combinacion="", respuesta="";
        srand(time(NULL));
        for (int i=0; i<3; i++)
            combinacion += obtener_random();
        adivino = false;
        intento = 1;
        do
        {
            system("CLS");
            cout << "Letras a adivinar: " << combinacion << "\t\t<--- Esto no lo ve el usuario" <<endl;
            cout << "\nBienvenidos a adivina las letras!";
            cout << "\t\tIntento " << intento << " de 10" << endl;
            cout << "\nTu ultimo intento fue: " << respuesta << "\n\n";
            cout << "Ingresa las 3 letras correctas:" << endl;
            cin >> respuesta;
            transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);
            cout << endl;
            comparar_cadenas(combinacion, respuesta);
            system("pause");
        }while(adivino == false && intento <= 10);
        system("CLS");
        if (adivino)
            cout << "Lo has logrado :)\nFelicitaciones!" << endl;
        else
            cout << "Lo siento tus intentos se han acabado :(" << endl;
        cout << endl << "Deseas continuar jugando? (s/n)" << endl;
        cin >> opc;
    }while(opc != "n" && opc!= "N");
    cout << "Vuelve pronto ;)" << endl;
    return 0;
}
