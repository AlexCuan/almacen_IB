#include "Almacen.h"
#include "Containers.h"
#include "iostream"
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace  std;

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
fstream inOut_appliances("appliances.dat", ios::out);
fstream inOut_food("food.dat", ios::out);


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
void cargar_electrodomesticos() {
    string _nombre;
    long _codigo;
    string _descripcion;
    string _paisOrigen;
    int _cantidad;
    int _tiempo;
    int _voltaje;
    bool _manual;

    while (!inOut_appliances.eof()) {
        inOut_appliances >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _tiempo >> _voltaje
                         >> _manual;
        appliances_department.add(new RegistroElectrodomesticos(_nombre, _codigo,
                                                                _descripcion, _paisOrigen, _cantidad, _tiempo, _voltaje,
                                                                _manual));
    }
}

void cargar_food(){
    string _nombre;
    long _codigo;
    string _descripcion;
    string _paisOrigen;
    int _cantidad;
    string _clasificacion;
    string _empleado;
    long _codigoEstiba;

    while(!inOut_food.eof()){
        inOut_food >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _clasificacion >> _empleado >> _codigoEstiba;

        food_department.add(new RegistroAlimentos(_nombre, _codigo,
                _descripcion, _paisOrigen, _cantidad, _clasificacion, _empleado, _codigoEstiba)); //flat por agregar al array
                //empleado y codigoEstba
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

    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;
    string material;
    char sexo;
    char talla;

    cout << "Introduzca el nombre del producto: ";
    cin >> nombre;
    cout << "Introduzca el codigo del producto: ";
    cin >> codigo;
    cout << "Introduzca la descripcion del producto: ";
    cin >> descripcion;
    cout << "Introduzca el pais de origen del producto: ";
    cin >> paisOrigen;
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cin>> cantidad;
    cout << "Introduzca el material: ";
    cin >> material;
    cout << "Introduzca el sexo: ";
    cin >> sexo;
    cout << "Introduzca la talla: ";
    cin >> talla;

    textiles_departament.add(new RegistroTextiles(nombre, codigo, descripcion, paisOrigen, cantidad, material, sexo,
                                                   talla));

}

void add_appliances() {
    limpiar_consola();

    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;
    int tiempo; //tiempo en meses
    int voltaje;
    bool manual;
    string temp;

    cout << "Introduzca el nombre del producto: ";
    cin >> nombre;
    cout << "Introduzca el codigo del producto: ";
    cin >> codigo;
    cout << "Introduzca la descripcion del producto: ";
    cin >> descripcion;
    cout << "Introduzca el pais de origen del producto: ";
    cin >> paisOrigen;
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cin>> cantidad;
    cout << "Introduzca el tiempo: ";
    cin >> tiempo;
    cout << "Introduzca el voltaje: ";
    cin >> voltaje;
    cout << "Tiene manual ?: ";
    cin >> temp;
    if (temp == "si") {
        manual = true;
    } else {
        manual = false;
    }

    appliances_department.add(new RegistroElectrodomesticos(nombre,codigo, descripcion,paisOrigen, cantidad,tiempo,voltaje,manual));

}

void add_food() {
    limpiar_consola();

    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;
    string clasificacion;

    cout << "Introduzca el nombre del producto: ";
    cin >> nombre;
    cout << "Introduzca el codigo del producto: ";
    cin >> codigo;
    cout << "Introduzca la descripcion del producto: ";
    cin >> descripcion;
    cout << "Introduzca el pais de origen del producto: ";
    cin >> paisOrigen;
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cin>> cantidad;
    cout << "Introduzca la clasificacion : ";
    cin>>clasificacion;

    food_department.add(new RegistroAlimentos("Pan",2345,"Pan para comer","Uruguay", 34,"solido"));
}

void extract_textiles(){
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout<<"Introduzca el nombre del producto a extraer: ";
    cin>>nombre_producto;

    int indice = textiles_departament.find_index(nombre_producto);

    cout<<"Hay "<<textiles_departament.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;

    cout<<"Introduzca la cantidad a extraer: ";
    cin >>cantidad;

    textiles_departament.extract(indice, cantidad);
    cout<<"Operacion realizada con exito. Queda "<<textiles_departament.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;
}

void extract_appliances(){
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout<<"Introduzca el nombre del producto a extraer: ";
    cin>>nombre_producto;

    int indice = appliances_department.find_index(nombre_producto);

    cout<<"Hay "<<appliances_department.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;

    cout<<"Introduzca la cantidad a extraer: ";
    cin >>cantidad;

    appliances_department.extract(indice, cantidad);
    cout<<"Operacion realizada con exito. Queda "<<food_department.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;
}

void extract_food(){
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout<<"Introduzca el nombre del producto a extraer: ";
    cin>>nombre_producto;

    int indice = food_department.find_index(nombre_producto);

    cout<<"Hay "<<food_department.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;

    cout<<"Introduzca la cantidad a extraer: ";
    cin >>cantidad;

    food_department.extract(indice, cantidad);
    cout<<"Operacion realizada con exito. Queda "<<food_department.in_memory_warehouse[indice]->cantidad<<" de "<<nombre_producto<<" en el almacen"<<endl;
}

void main_menu() {



    while (true) {
        limpiar_consola();
        cout << "You are at main menu." << endl;

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

    while (true) {
        limpiar_consola();
        cout << "You are at main menu." << endl;

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
            case 2:
                extract_appliances();
            break;
            case 3:
                extract_food();
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