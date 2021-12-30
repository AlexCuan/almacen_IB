#include "Almacen.h"
#include "Containers.h"
#include "iostream"
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

//RegistroTextiles textiles("Pullover",3456,"Descripcion","Cuba",333,"algodon",'M','L');


ContainerTextiles textiles_departament;
ContainerElectrodomesticos appliances_department;
ContainerAlimentos food_department;

fstream inOut_Textiles("textiles.txt", ios::out);

fstream inOut_appliances("appliances.dat", ios::out);
fstream inOut_food("food.dat", ios::out);

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

    if (!is_file_empty(inOut_Textiles)) {
        while (!inOut_Textiles.eof()) {
            // lectura de un registro del archivo
            inOut_Textiles >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _material >> _sexo
                           >> _talla;


            textiles_departament.add(new RegistroTextiles(_nombre, _codigo, _descripcion, _paisOrigen,
                                                          _cantidad, _material, _sexo, _talla));

            //  con esto en teoria debe quedar todos los elemetos del archivo de textiles
            //  cargados en el arreglo de la clase Container textiles
        }
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

    if(!is_file_empty(inOut_appliances)){
        while (!inOut_appliances.eof()) {
            inOut_appliances >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _tiempo >> _voltaje
                             >> _manual;
            appliances_department.add(new RegistroElectrodomesticos(_nombre, _codigo,
                                                                    _descripcion, _paisOrigen, _cantidad, _tiempo, _voltaje,
                                                                    _manual));
        }}

}

void cargar_food() {
    string _nombre;
    long _codigo;
    string _descripcion;
    string _paisOrigen;
    int _cantidad;
    string _clasificacion;
    string _empleado;
    long _codigoEstiba;
    string _day;
    string _month;
    string _year;
    if (!is_file_empty(inOut_food)){
        while (!inOut_food.eof()) {
            inOut_food >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _clasificacion >> _empleado
                       >> _codigoEstiba;

            food_department.add(new RegistroAlimentos(_nombre, _codigo,
                                                      _descripcion, _paisOrigen, _cantidad, _clasificacion, _day, _month,
                                                      _year, _empleado, _codigoEstiba));
        }
    }

}

void load_info() {
    cargarTextiles();
    cargar_electrodomesticos();
    cargar_food();
}

void main_menu();

void sub_menu_a();

void sub_menu_b();

void sub_menu_c();

void sub_menu_d();


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
    cin>>nombre;
    cout << "Introduzca el codigo del producto: ";
    codigo = validateInput_int(codigo);
    cin.ignore();
    cout << "Introduzca la descripcion del producto: ";
    getline(cin, descripcion, '\n');
    cout << "Introduzca el pais de origen del producto: ";
    cin.ignore();
    cin >> paisOrigen;
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cantidad = validateInput_int(cantidad);
    cout << "Introduzca el material: ";
    cin >> material;
    cin.ignore();
    cout << "Introduzca el sexo: ";
    sexo = cin.get();
    cout << "Introduzca la talla: ";
    cin.ignore();
    talla = cin.get();

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
    cin>>nombre;
    cout << "Introduzca el codigo del producto: ";
    cin.ignore();
    codigo = validateInput_int(codigo);
    cin.ignore();
    cout << "Introduzca la descripcion del producto: ";
    getline(cin, descripcion);
    cin.ignore();
    cout << "Introduzca el pais de origen del producto: ";
    cin >> paisOrigen;
    cin.ignore();
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cantidad = validateInput_int(cantidad);
    cin.ignore();
    cout << "Introduzca el tiempo: ";
    tiempo = validateInput_int(tiempo);
    cin.ignore();
    cout << "Introduzca el voltaje: ";
    voltaje = validateInput_int(voltaje);
    cin.ignore();
    cout << "Tiene manual ?: ";
    cin >> temp;
    cin.ignore();
    if (temp == "si") {
        manual = true;
    } else {
        manual = false;
    }

    appliances_department.add(new RegistroElectrodomesticos(nombre, codigo, descripcion, paisOrigen, cantidad, tiempo, voltaje, manual));

}

void add_food() {
    limpiar_consola();

    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;
    string clasificacion;
    string _day;
    string _month;
    string _year;

    cout << "Introduzca el nombre del producto: ";
    cin>>nombre;
    cout << "Introduzca el codigo del producto: ";
    codigo = validateInput_int(codigo);
   // cin.ignore();
    cout << "Introduzca la descripcion del producto: ";
    getline(cin, descripcion, '\n');
    //cin.ignore();
    cout << "Introduzca el pais de origen del producto: ";
    cin >> paisOrigen;
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cantidad = validateInput_int(cantidad);
    //cin.ignore();
    cout << "Introduzca la clasificacion : ";
    cin >> clasificacion;
   // cin.ignore();
    cout << "Introduzca la fecha de vencimiento: " << endl;
    cout << "Introduzca el dia: ";
    cin >> _day;
    cout << "Introduzca el mes: ";
    cin >> _month;
    cout << "Introduzca el anio: ";
    cin >> _year;

    food_department.add(
            new RegistroAlimentos(nombre, codigo, descripcion, paisOrigen, cantidad, clasificacion, _day, _month, _year));
}

void extract_textiles() {
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout << "Introduzca el nombre del producto a extraer: ";
    cin >> nombre_producto;

    int indice = textiles_departament.find_index(nombre_producto);

    cout << "Hay " << textiles_departament.in_memory_warehouse[indice]->cantidad << " de " << nombre_producto
         << " en el almacen" << endl;

    cout << "Introduzca la cantidad a extraer: ";
    cantidad = validateInput_int(cantidad);

    textiles_departament.extract(indice, cantidad);
    cout << "Operacion realizada con exito. Queda " << textiles_departament.in_memory_warehouse[indice]->cantidad
         << " de " << nombre_producto << " en el almacen" << endl;
}

void extract_appliances() {
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout << "Introduzca el nombre del producto a extraer: ";
    cin >> nombre_producto;

    int indice = appliances_department.find_index(nombre_producto);

    cout << "Hay " << appliances_department.in_memory_warehouse[indice]->cantidad << " de " << nombre_producto
         << " en el almacen" << endl;

    cout << "Introduzca la cantidad a extraer: ";
    cantidad = validateInput_int(cantidad);

    appliances_department.extract(indice, cantidad);
    cout << "Operacion realizada con exito. Queda " << food_department.in_memory_warehouse[indice]->cantidad << " de "
         << nombre_producto << " en el almacen" << endl;
}

void extract_food() {
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout << "Introduzca el nombre del producto a extraer: ";
    cin >> nombre_producto;

    int indice = food_department.find_index(nombre_producto);

    cout << "Hay " << food_department.in_memory_warehouse[indice]->cantidad << " de " << nombre_producto
         << " en el almacen" << endl;

    cout << "Introduzca la cantidad a extraer: ";
    cantidad = validateInput_int(cantidad);

    food_department.extract(indice, cantidad);
    cout << "Operacion realizada con exito. Queda " << food_department.in_memory_warehouse[indice]->cantidad << " de "
         << nombre_producto << " en el almacen" << endl;
}

void list_textiles() {

    limpiar_consola();
    textiles_departament.list(cout);
    int a;
    cin >> a;
    //getchar();
    // system("pause");

}

void list_appliances() {
    limpiar_consola();
    appliances_department.list(cout);
}

void list_food() {
    limpiar_consola();
    food_department.list(cout);
}

void add_dummies() {
    textiles_departament.add(new RegistroTextiles("Pullover", 3456, "Descripcion", "Cuba", 333, "algodon", 'M', 'L'));
    textiles_departament.add(new RegistroTextiles("Camisa", 5874, "Descripcion", "España", 213, "poliester", 'M', 'L'));
    textiles_departament.add(
            new RegistroTextiles("Pantalon", 2634, "Descripcion", "Rusia", 234, "mezclilla", 'M', 'L'));
    textiles_departament.add(new RegistroTextiles("Gorra", 7846, "Descripcion", "India", 875, "rare", 'F', 'L'));
    textiles_departament.add(new RegistroTextiles("Blusa", 2345, "Descripcion", "Vietnam", 235, "hilo", 'F', 'L'));

    appliances_department.add(new RegistroElectrodomesticos("Refrigerador", 2345, "Hielitosbrr", "China", 34, 12, 220, true));
    appliances_department.add(new RegistroElectrodomesticos("Freezer", 5746, "Hielitosbrr", "Rusia", 34, 16, 110, false));
    appliances_department.add(new RegistroElectrodomesticos("Microwave", 4257, "Calienteuff", "Corea", 34, 22, 220, true));
    appliances_department.add(new RegistroElectrodomesticos("Lavadora", 3756, "Centrifugadoooo", "Taiwan", 34, 28, 110, false));
    appliances_department.add(new RegistroElectrodomesticos("Arrocera", 7682, "ArrozVietnamita", "Vietnam", 34, 36, 220, true));

    food_department.add(new RegistroAlimentos("Pan", 1244, "pancito", "Ecuador", 23, "Solido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("Refresco", 4565, "refresquito", "Bolivia", 42, "Liquido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("Pelly", 3467, "pellycito", "Peru", 86, "Solido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("Ron", 6575, "pancito", "Chile", 73, "Liquido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("Puerco", 1693, "pancito", "Oriente", 74, "Solido", "10", "12", "30"));
}

void save_to_file() {
    //textiles_departament.list(inOut_Textiles);
    //appliances_department.list(inOut_appliances);
    food_department.list(cout);
}

void main_menu() {
    bool terminar = false;


    while (!terminar) {
        limpiar_consola();
        cout << "You are at main menu." << endl;

        cout << "Bienvenido al almacen rosca izquierda:" << endl << "Que desea hacer" << endl;
        cout << "1 -> Adicionar nuevos productos al almacen" << endl;
        cout << "2 -> Extraer productos del almacen" << endl;
        cout << "3 -> Listar productos" << endl;
        cout << "4 -> Añadir dummies" << endl;
        cout << "5 -> Guardar en archivo" << endl;
        cout << "6 -> Salir" << endl;


        int option;

        option = validateInput_int(option);
        switch (option) {
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
                add_dummies();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                terminar = true;
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

        option = validateInput_int(option);
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
        cout << "You are at sub_menu b." << endl;

        cout << "Seleccione la clasificacion del producto que desea extraer:" << endl;
        cout << "1 -> Textil" << endl;
        cout << "2 -> Electrodomestico" << endl;
        cout << "3 -> Alimenticio" << endl;
        cout << "4 -> Menu principal" << endl;

        int option;

        option = validateInput_int(option);

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

void sub_menu_c() {

    while (true) {
        limpiar_consola();
        cout << "You are at sub_menu c." << endl;

        cout << "Seleccione la clasificacion del producto que desea listar:" << endl;
        cout << "1 -> Textil" << endl;
        cout << "2 -> Electrodomestico" << endl;
        cout << "3 -> Alimenticio" << endl;
        cout << "4 -> Menu principal" << endl;

        int option;

        option = validateInput_int(option);

        switch (option) {
            case 1:
                list_textiles();
                break;
            case 2:
                list_appliances();
                break;
            case 3:
                list_food();
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


