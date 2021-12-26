#include "Almacen.h"
#include "Containers.h"
#include "iostream"
#include <fstream>
#include <stdlib.h>
#include <string>

//RegistroTextiles textiles("Pullover",3456,"Descripcion","Cuba",333,"algodon",'M','L');


ContainerTextiles textiles_departament;
ContainerElectrodomesticos appliances_department;
ContainerAlimentos food_department;

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
    char _sexo;
    char _talla;


    while (!inOut_Textiles.eof()) {
        // lectura de un registro del archivo
        inOut_Textiles >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _material >> _sexo >> _talla;


        textiles_departament.add(new RegistroTextiles(_nombre, _codigo, _descripcion, _paisOrigen,
        _cantidad, _material, _sexo, _talla));

        //  con esto en teoria debe quedar todos los elemetos del archivo de textiles
        //  cargados en el arreglo de la clase Container textiles
    }

}

void main_menu();

void sub_menu_a();
void sub_menu_b();

/*void sub_menu_b();
void sub_menu_c();
void sub_menu_d();*/

void add_textiles() {
    limpiar_consola();

    textiles_departament.add(new RegistroTextiles("Pullover", 3456, "Descripcion", "Cuba", 333, "algodon", 'M',
                                                   'L'));


}

void add_appliances() {
    limpiar_consola();
    appliances_department.add(new RegistroElectrodomesticos("Refrigerador",5555, "Refrigerador para hacer hielito","China", 356,1,220,true));

}

void add_food() {
    limpiar_consola();
    food_department.add(new RegistroAlimentos("Pan",2345,"Pan para comer","Uruguay", 34,"solido"));
}

void extract_textiles(){
    limpiar_consola();
    string nombre_producto;
    int cantidad = 1;
    cout<<"Introduzca el nombre del producto a extraer: ";
    cin>>nombre_producto;

    int indice = textiles_departament.find_index(nombre_producto);

    cout<<"Hay "<<textiles_departament.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;

    cout<<"Introduzca la cantidad a extraer: ";
    cin >>cantidad;

    textiles_departament.extract(indice, cantidad);
    cout<<textiles_departament.in_memory_warehouse[indice]->cantidad;
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
                case 2:
                    sub_menu_b();
                    break;
//                case 3:
//                    sub_menu_c();
//                    break;
//                case 4:
//                    sub_menu_d();
//                    break;*/
            default:
                cout << "Por favor inserte un numero entre 1 y 4." << endl;
                break;
        }
    }
}

void sub_menu_a() {


    while (true) {
        limpiar_consola();

        cout << "You are at sub menu A." << endl;

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
                cout << "Please insert an integer between 1 and 4." << endl;
                break;
        }
    }
}

void sub_menu_b() {

    cout << "You are at sub menu B." << endl;

    while (true) {
        cout << "Seleccione la clasificacion del producto que desea extraer:" << endl;
        cout << "1 -> Textil" << endl;
        cout << "2 -> Electrodomestico" << endl;
        cout << "3 -> Alimenticio" << endl;
        cout << "4 -> Menu principal" << endl;

        int option;

        cin >> option;

        switch (option) {
            case 1:
                extract_textiles();
            break;
//            case 2:
//                extract_appliances();
//            break;
//            case 3:
//                extract_food();
//            break;
//            case 4:
//                main_menu();
//            break;
            default:
                cout << "Please insert an integer between 1 and 4." << endl;
            break;
        }
    }
}