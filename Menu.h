#include "Almacen.h"
#include "Containers.h"
#include "iostream"
#include <fstream>
#include <stdlib.h>
#include <string>

ContainerTextiles textiles_departament;

fstream inOut_Textiles("textiles.dat", ios::out /*| ios::in*/);

// se declara aqui para poder acceder desde cualquier bloque
/* if(!salidaTextiles) {
        cerr << "No se pudo crear el archivo";
        exit(1);
    }*/ //da error no se xq


void cargarTextiles() { // funcion para cargar los datos del archivo

    // atributos de la clase textiles

    string _nombre;
    long _codigo;
    string _descripcion;
    string _paisOrigen;
    int _cantidad;
    string _material;
    string _sexo;
    char _talla;

    RegistroTextiles productoTextil;

    while (!inOut_Textiles.eof()) {
        // lectura de un registro del archivo
        inOut_Textiles >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _material >> _sexo >> _talla;

        /*esto debe implementarse en funciones (setter) en las clases RegistroTextiles etc, una
        para cada atributo*/

        productoTextil.nombre = _nombre;
        productoTextil.codigo = _codigo;
        productoTextil.descripcion = _descripcion;
        productoTextil.paisOrigen = _paisOrigen;
        productoTextil.cantidad = _cantidad;
        productoTextil.material = _material;
        productoTextil.sexo = _sexo;
        productoTextil.talla = _talla;


        textiles_departament.add(&productoTextil);

        //  con esto en teoria debe quedar todos los elemetos del archivo de textiles
        //  cargados en el arreglo de la clase Container textiles
    }

}

void main_menu();

void sub_menu_a();

void limpiar_consola() {
    system("clear");
}

/*void sub_menu_b();
void sub_menu_c();
void sub_menu_d();*/

void add_textiles() {
    limpiar_consola();
    //textiles.add_register();
    RegistroTextiles textiles("Pullover",3456,"Descripcion","Cuba",333,"algodon",'M','L');
    textiles_departament.add(&textiles);
    cout << textiles_departament.counter<<endl;

    //Aqui lo q debe ir es agregar los registror al arreglo de la clase contenedor textiles*/

}

void add_appliances() {
    /*  limpiar_consola();

      ofstream salidaAppliances("appliance.dat", ios::app);

      if (!salidaAppliances) {
          cout << "No se pudo crear el archivo";
      }

      RegistroElectrodomesticos electrodomestico;
      electrodomestico.add_register();*/

}

void add_food() {
    /*limpiar_consola();

    ofstream salidaAlimentos("alimentos.dat", ios::app);

    if (!salidaAlimentos) {
        cout << "No se pudo crear el archivo";
    }
    RegistroAlimentos alimento;
    alimento.add_register();    No lleva punto y coma eso es para las clases*/
}

void main_menu() {

    limpiar_consola();
    cout << "You are at main menu." << endl;

    while (true) {
        cout << "Bienvenido al almacen rosca izquierda:" << endl << "Que desea hacer" << endl;
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
 *
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