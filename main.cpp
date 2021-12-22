#include "Almacen.h"
#include "iostream"
#include "stdlib.h"
#include "fstream"

using namespace std;

//Constantes de archivos almacenadores
const string almacen_text = "textiles.dat";
const string almacen_electrodomesticos = "electrodomesticos.dat";
const string almacen_alimentos = "alimentos.dat";
void main_menu();
void sub_menu_a();
void sub_menu_b();
void sub_menu_c();
void sub_menu_d();
void function_a();
void function_b();
void function_c();

void main_menu()
{
    cout << "You are at main menu." << endl;

    while(true)
    {
        cout << "Bienvenido al almacen rosca izquierda:" << endl<<"Que desea hacer";
        cout << "1 -> Adicionar nuevos productos al almacen" << endl;
        cout << "2 -> Extraer productos del almacen" << endl;
        cout << "3 -> Listar productos" << endl;
        cout << "4 -> Eliminar producto de tipo alimento"<<endl;


        int option;

        cin >> option;
        switch(option)
        {
            case 1:
                sub_menu_a();
                break;
            case 2:
                sub_menu_b();
                break;
            case 3:
                sub_menu_c();
                break;
            case 4:
                sub_menu_d();
                break;
            default:
                cout << "Por favor inserte un numero entre 1 y 4." << endl;
                break;
        }
    }
}

void sub_menu_a()
{
    cout << "You are at sub menu A." << endl;

    while(true)
    {
        cout << "Select one of the following options:" << endl;
        cout << "1 -> Function A" << endl;
        cout << "2 -> Function B" << endl;
        cout << "3 -> Back to main menu" << endl;


        int option;

        cin >> option;
        switch(option)
        {
            case 1:
                function_a();
                break;
            case 2:
                function_b();
                break;
            case 3:
                main_menu();
                break;
            default:
                cout << "Please insert an integer between 1 and 3." << endl;
                break;
        }
    }
}

void sub_menu_b() {
    cout << "You are at sub menu B." << endl;

    while (true) {
        cout << "Select one of the following options:" << endl;
        cout << "1 -> Function C" << endl;
        cout << "2 -> Back to main menu" << endl;


        int option;

        cin >> option;
        switch (option) {
            case 1:
                function_c();
                break;
            case 2:
                main_menu();
                break;
            default:
                cout << "Please insert an integer between 1 and 2." << endl;
                break;
        }
    }
}
int main(){
    return 0;
}