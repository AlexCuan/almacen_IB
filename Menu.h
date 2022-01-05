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

fstream inOut_Textiles("textiles.dat", ios::out | ios::in);

fstream inOut_appliances("appliances.dat", ios::out | ios::in);
fstream inOut_food("food.dat", ios::out | ios::in);

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
    string _talla;

    while (!inOut_Textiles.eof()) {
        // lectura de un registro del archivo
        inOut_Textiles >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _material >> _sexo
                       >> _talla;
        // con esto se separan las palabras
        _nombre = extender(_nombre);
        _descripcion = extender(_descripcion);
        _paisOrigen = extender(_paisOrigen);
        _material = extender(_material);
        _sexo = extender(_sexo);
        _talla = extender(_talla);

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
        _nombre = extender(_nombre);
        _descripcion = extender(_descripcion);
        _paisOrigen = extender(_paisOrigen);

        appliances_department.add(new RegistroElectrodomesticos(_nombre, _codigo,
                                                                _descripcion, _paisOrigen, _cantidad, _tiempo, _voltaje,
                                                                _manual));
    }

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

    while (!inOut_food.eof()) {
        inOut_food >> _nombre >> _codigo >> _descripcion >> _paisOrigen >> _cantidad >> _clasificacion
                   >> _day >> _month >> _year >> _empleado >> _codigoEstiba;

        _nombre = extender(_nombre);
        _descripcion = extender(_descripcion);
        _paisOrigen = extender(_paisOrigen);
        _clasificacion = extender(_clasificacion);
        _day = extender(_day);
        _month = extender(_month);
        _year = extender(_year);
        _empleado = extender(_empleado);
        food_department.add(new RegistroAlimentos(_nombre, _codigo,
                                                  _descripcion, _paisOrigen, _cantidad, _clasificacion, _day, _month,
                                                  _year, _empleado, _codigoEstiba));
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


void add_textiles() {
    limpiar_consola();

    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;
    string material;
    string sexo;
    string talla;

    cout << "Introduzca el nombre del producto: ";
    getline(cin, nombre, '\n');
    cout << "Introduzca el codigo del producto: ";
    codigo = validateInput_int(codigo);
    cin.ignore();
    cout << "Introduzca la descripcion del producto: ";
    getline(cin, descripcion, '\n');
    cout << "Introduzca el pais de origen del producto: ";
    getline(cin, paisOrigen, '\n');
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cantidad = validateInput_int(cantidad);
    cin.ignore();
    cout << "Introduzca el material: ";
    getline(cin, material, '\n');
    cout << "Introduzca el sexo: ";
    getline(cin, sexo, '\n');
    cout << "Introduzca la talla: ";
    getline(cin, talla, '\n');


    textiles_departament.add(
            new RegistroTextiles(minusculas(nombre), codigo, minusculas(descripcion), minusculas(paisOrigen), cantidad,
                                 minusculas(material), minusculas(sexo),
                                 minusculas(talla)));

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
    getline(cin, nombre, '\n');
    cout << "Introduzca el codigo del producto: ";
    codigo = validateInput_int(codigo);
    cin.ignore();
    cout << "Introduzca la descripcion del producto: ";
    getline(cin, descripcion, '\n');
    cout << "Introduzca el pais de origen del producto: ";
    getline(cin, paisOrigen, '\n');
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
    getline(cin, temp, '\n');
    if (temp == "si") {
        manual = true;
    } else {
        manual = false;
    }

    appliances_department.add(
            new RegistroElectrodomesticos(minusculas(nombre), codigo, minusculas(descripcion), minusculas(paisOrigen),
                                          cantidad, tiempo, voltaje, manual));

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
    getline(cin, nombre);
    cout << "Introduzca el codigo del producto: ";
    codigo = validateInput_int(codigo);
    cin.ignore();
    cout << "Introduzca la descripcion del producto: ";
    getline(cin, descripcion, '\n');
    cout << "Introduzca el pais de origen del producto: ";
    getline(cin, paisOrigen, '\n');
    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    cantidad = validateInput_int(cantidad);
    cin.ignore();
    cout << "Introduzca la clasificacion : ";
    getline(cin, clasificacion, '\n');
    cout << "Introduzca la fecha de vencimiento: " << endl;
    cout << "Introduzca el dia: ";
    getline(cin, _day, '\n');
    cout << "Introduzca el mes: ";
    getline(cin, _month, '\n');
    cout << "Introduzca el anio: ";
    getline(cin, _year, '\n');

    food_department.add(
            new RegistroAlimentos(minusculas(nombre), codigo, minusculas(descripcion), minusculas(paisOrigen), cantidad,
                                  minusculas(clasificacion), _day, _month,
                                  _year));
}

void extract_textiles() {
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout << "Introduzca el nombre del producto a extraer: ";
   // cin.ignore();
    getline(cin, nombre_producto);
    nombre_producto = minusculas(nombre_producto);

    int indice = textiles_departament.find_index(nombre_producto);

    if (indice != -1) {
        cout << "Hay " << textiles_departament.in_memory_warehouse[indice]->cantidad << " de " << nombre_producto
             << " en el almacen" << endl;

        cout << "Introduzca la cantidad a extraer: ";
        cantidad = validateInput_int(cantidad);

        textiles_departament.extract(indice, cantidad);
        cout << "Operacion realizada con exito. Queda " << textiles_departament.in_memory_warehouse[indice]->cantidad
             << " de " << nombre_producto << " en el almacen" << endl;

    } else {
        cout << "Producto no encontrado\n";
        //int a;
        //cin >> a;
    }

}

void extract_appliances() {
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout << "Introduzca el nombre del producto a extraer: ";
    cin.ignore();
    getline(cin, nombre_producto, '\n');
    nombre_producto = minusculas(nombre_producto);

    int indice = appliances_department.find_index(nombre_producto);

    if (indice != -1) {
        cout << "Hay " << appliances_department.in_memory_warehouse[indice]->cantidad << " de " << nombre_producto
             << " en el almacen" << endl;

        cout << "Introduzca la cantidad a extraer: ";
        cantidad = validateInput_int(cantidad);

        appliances_department.extract(indice, cantidad);
        cout << "Operacion realizada con exito. Queda " << food_department.in_memory_warehouse[indice]->cantidad
             << " de "
             << nombre_producto << " en el almacen" << endl;
    } else {
        cout << "Producto no encontrado\n";
        int a;
        cin >> a;
    }
}

void extract_food() {
    limpiar_consola();
    string nombre_producto;
    int cantidad;
    cout << "Introduzca el nombre del producto a extraer: ";
    cin.ignore();
    getline(cin, nombre_producto, '\n');
    nombre_producto = minusculas(nombre_producto);
    int indice = food_department.find_index(nombre_producto);

    if (indice != -1) {
        cout << "Hay " << food_department.in_memory_warehouse[indice]->cantidad << " de " << nombre_producto
             << " en el almacen" << endl;

        cout << "Introduzca la cantidad a extraer: ";
        cantidad = validateInput_int(cantidad);

        food_department.extract(indice, cantidad);
        cout << "Operacion realizada con exito. Queda " << food_department.in_memory_warehouse[indice]->cantidad
             << " de "
             << nombre_producto << " en el almacen" << endl;
    } else {
        cout << "Producto no encontrado\n";
        int a;
        cin >> a;
    }
}

void list_textiles() {

    limpiar_consola();
    textiles_departament.list(cout, COUT);
    //int a;
   // cin >> a;
    //getchar();
    // system("pause");

}

void list_appliances() {
    limpiar_consola();
    appliances_department.list(cout, COUT);
    //int a;
    //cin >> a;
}

void list_food() {
    limpiar_consola();
    food_department.list(cout, COUT);
    //int a;
   // cin >> a;
}

void add_dummies() { // todo debe estar en minusculas
    textiles_departament.add(new RegistroTextiles(minusculas("Pullover con espacios"), 3456, minusculas("Descripcion con espacios"), minusculas("Cuba"), 333, minusculas("algodon suave"), minusculas("Masculino"), minusculas("Large")));
    textiles_departament.add(new RegistroTextiles("camisa", 5874, "Descripcion", "España", 213, "poliester", "M", "L"));
    textiles_departament.add(
            new RegistroTextiles("pantalon", 2634, "Descripcion", "Rusia", 234, "mezclilla", "M", "L"));
    textiles_departament.add(new RegistroTextiles("gorra", 7846, "Descripcion", "India", 875, "rare", "M", "L"));
    textiles_departament.add(new RegistroTextiles("blusa", 2345, "Descripcion", "Vietnam", 235, "hilo", "M", "L"));

    appliances_department.add(
            new RegistroElectrodomesticos("refrigerador", 2345, "Hielitosbrr", "China", 34, 12, 220, true));
    appliances_department.add(
            new RegistroElectrodomesticos("freezer", 5746, "Hielitosbrr", "Rusia", 34, 16, 110, false));
    appliances_department.add(
            new RegistroElectrodomesticos("microwave", 4257, "Calienteuff", "Corea", 34, 22, 220, true));
    appliances_department.add(
            new RegistroElectrodomesticos("lavadora", 3756, "Centrifugadoooo", "Taiwan", 34, 28, 110, false));
    appliances_department.add(
            new RegistroElectrodomesticos("arrocera", 7682, "ArrozVietnamita", "Vietnam", 34, 36, 220, true));

    food_department.add(new RegistroAlimentos("pan", 1244, "pancito", "Ecuador", 23, "Solido", "10", "12", "30"));
    food_department.add(
            new RegistroAlimentos("refresco", 4565, "refresquito", "Bolivia", 42, "Liquido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("pelly", 3467, "pellycito", "Peru", 86, "Solido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("ron", 6575, "pancito", "Chile", 73, "Liquido", "10", "12", "30"));
    food_department.add(new RegistroAlimentos("puerco", 1693, "pancito", "Oriente", 74, "Solido", "10", "12", "30"));
}

void save_to_file() {
    textiles_departament.list(inOut_Textiles, ARCH);
    appliances_department.list(inOut_appliances, ARCH);
    food_department.list(inOut_food, ARCH);
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
        cin.ignore();
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
/*estas funciones se encargaran de unir las palabras antes de guardar los registros en el ficheros para poder sacrlas con un cin*/
/*
void prepare_textiles_to_save(){
    for(int i = 0; i < textiles_departament.counter; i++){
        textiles_departament.in_memory_warehouse[i] ->nombre = contraer(
                textiles_departament.in_memory_warehouse[i]->nombre);
        textiles_departament.in_memory_warehouse[i] ->talla = contraer(
                textiles_departament.in_memory_warehouse[i]->talla);
        textiles_departament.in_memory_warehouse[i] ->material = contraer(
                textiles_departament.in_memory_warehouse[i]->material);
        textiles_departament.in_memory_warehouse[i] ->sexo = contraer(textiles_departament.in_memory_warehouse[i]->sexo);
        textiles_departament.in_memory_warehouse[i] ->paisOrigen = contraer(
                textiles_departament.in_memory_warehouse[i]->paisOrigen);
        textiles_departament.in_memory_warehouse[i] ->descripcion = contraer(
                textiles_departament.in_memory_warehouse[i]->descripcion);

    }

}
void prepare_appliances_to_save(){
    for(int i = 0; i < appliances_department.counter; i++){
        appliances_department.in_memory_warehouse[i] ->nombre = contraer(
                appliances_department.in_memory_warehouse[i]->nombre);
        appliances_department.in_memory_warehouse[i] ->descripcion = contraer(
                appliances_department.in_memory_warehouse[i]->descripcion);
        appliances_department.in_memory_warehouse[i] ->paisOrigen = contraer(
                appliances_department.in_memory_warehouse[i]->paisOrigen);


    }
}
void prepare_food_to_save(){
    for(int i = 0; i < food_department.counter; i++) {
        food_department.in_memory_warehouse[i] ->empleado = contraer(food_department.in_memory_warehouse[i] ->empleado);
        food_department.in_memory_warehouse[i] ->clasificacion = contraer(food_department.in_memory_warehouse[i] ->clasificacion);
        food_department.in_memory_warehouse[i] ->paisOrigen = contraer(food_department.in_memory_warehouse[i] ->paisOrigen);
        food_department.in_memory_warehouse[i] ->descripcion = contraer(food_department.in_memory_warehouse[i] ->descripcion);
        food_department.in_memory_warehouse[i] ->nombre = contraer(food_department.in_memory_warehouse[i] ->nombre);


    }
    }
*/