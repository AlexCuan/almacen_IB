#include "Almacen.h"
#include "iostream"
#include "stdlib.h"
#include <cstdlib>
#include "fstream"

using namespace std;


void main_menu();

void sub_menu_a();

void limpiar_consola(){
    system("clear");
}
/*void sub_menu_b();
void sub_menu_c();
void sub_menu_d();*/
void add_textiles(){
    limpiar_consola();
    RegistroTextiles textil("Pullover",3456,"Descripcion","Cuba",333,"algodon",'M','L');
    ofstream salida("textiles.dat", ios::app);
    if (!salida){
        cout<<"No se pudo crear el archivo";
    }
    salida << textil.descripcion<<'\n';
    salida.close();

};

void add_appliances(){
    limpiar_consola();
    RegistroElectrodomesticos electrodomestico;
    electrodomestico.add_register();

};

void add_food(){
    limpiar_consola();
    RegistroAlimentos alimento;
    alimento.add_register();
};

void main_menu() {
    limpiar_consola();
    cout << "You are at main menu." << endl;

    while (true) {
        cout << "Bienvenido al almacen rosca izquierda:" << endl << "Que desea hacer"<<endl;
        cout << "1 -> Adicionar nuevos productos al almacen" << endl;
        cout << "2 -> Extraer productos del almacen" << endl;
        cout << "3 -> Listar productos" << endl;
        cout << "4 -> Eliminar producto de tipo alimento" << endl;


        int option;

        cin >> option;
        switch (option) {
            case 1:
                sub_menu_a();
                break;
                /*case 2:
                    sub_menu_b();
                    break;
                case 3:
                    sub_menu_c();
                    break;
                case 4:
                    sub_menu_d();
                    break;*/
            default:
                cout << "Por favor inserte un numero entre 1 y 4." << endl;
                break;
        }
    }
}

void sub_menu_a() {
    limpiar_consola();
    cout << "You are at sub menu A." << endl;

    while (true) {
        cout << "Seleccione la clasificacion del producto que desea adicionar:" << endl;
        cout << "1 -> Textil" << endl;
        cout << "2 -> Electrodomestico" << endl;
        cout << "3 -> Alimenticio" << endl;
        cout << "4 -> Menu principal" << endl;


        int option;

        cin >> option;
        switch (option) {
            case 1:
                add_textiles();
                break;
            case 2:
                add_appliances();
                break;
            case 3:
                add_food();
                break;
            case 4:
                main_menu();
                break;
            default:
                cout << "Please insert an integer between 1 and 3." << endl;
                break;
        }
    }
}

/*void sub_menu_b() {
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
}*/



int main() {
    main_menu();
    return 0;
}