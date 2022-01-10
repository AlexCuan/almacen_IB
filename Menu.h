#include "Almacen.h"
#include "Containers.h"
#include "iostream"
#include <fstream>
#include <cstdlib>
#include <string>
#include <ncurses.h>

using namespace std;

//Se crean de manera global las instancias de la clase container
TextilesContainer textiles_departament;
AppliancesContainer appliances_department;
FoodContainer food_department;

/*
 * Funcion para cargar archivos del fichero externo. Recorre el archivo linea a linea, guarda los elementos segun un orden
 * preestablecido en las variables declaradas y por cada iteracion crea en su respectivo container y en memoria un objeto
 * que tenga por atributos estos elementos
 */
void load_textiles() {
    ifstream in_Textiles("textiles.dat", ios::in);

    // Atributos de la clase textiles
    string _name;
    long _code;
    string _descpription;
    string _country;
    int _quantity;
    string _material;
    string _gender;
    string _size;

    // Lectura de un registro del archivo con el mismo formato guardado
    while (in_Textiles >> _name >> _code >> _descpription >> _country >> _quantity >> _material >> _gender
                       >> _size) {

        // Separacion de las palabras que tienen caracteres $ en sus espacios vacios
        _name = extend(_name);
        _descpription = extend(_descpription);
        _country = extend(_country);
        _material = extend(_material);
        _gender = extend(_gender);
        _size = extend(_size);

        //Creacion dinamica de objetos al leerlos del archivo
        textiles_departament.add(new TextilesRegister(_name, _code, _descpription, _country,
                                                      _quantity, _material, _gender, _size));
    }

    cout << "Archivo cargado con exito\n";
}

void load_appliances() {
    ifstream in_appliances("appliances.dat", ios::in);

    string _name;
    long _code;
    string _description;
    string _country;
    int _quantity;
    int _warranty;
    int _voltage;
    bool _manual;

    while (in_appliances >> _name >> _code >> _description >> _country >> _quantity >> _warranty >> _voltage
                         >> _manual) {

        _name = extend(_name);
        _description = extend(_description);
        _country = extend(_country);

        appliances_department.add(new ApplianceRegister(_name, _code,
                                                        _description, _country, _quantity, _warranty, _voltage,
                                                        _manual));
    }

}

void load_food() {
    ifstream in_food("food.dat", ios::in);

    string _name;
    long _code;
    string _description;
    string _country;
    int _quantity;
    string _classification;
    string _employee;
    long _stowage_code;
    string _day;
    string _month;
    string _year;

    while (in_food >> _name >> _code >> _description >> _country >> _quantity >> _classification
                   >> _day >> _month >> _year >> _employee >> _stowage_code) {

        _name = extend(_name);
        _description = extend(_description);
        _country = extend(_country);
        _classification = extend(_classification);
        _day = extend(_day);
        _month = extend(_month);
        _year = extend(_year);
        _employee = extend(_employee);
        food_department.add(new FoodRegister(_name, _code,
                                             _description, _country, _quantity, _classification, _day, _month,
                                             _year, _employee, _stowage_code));
    }
}

//Centralizar las 3 funciones de cargar archivos
void load_info() {
    load_textiles();
    load_appliances();
    load_food();
}

/*
 * Predeclaracion de menus y submenus para poder llamarlos entre si debajo
 */
void main_menu();

void sub_menu_a();

void sub_menu_b();

void sub_menu_c();


/*
 * Funcion que añade objetos tipo RegistroTextiles. Se declaran las variables analogas a los atributos, se capturan los
 * datos con getline(para leer la linea entera, con espacios incluidos) y se crea dinamicamente un objeto en memoria y
 * se añade al container correspondiente
 */
void add_textiles() {
    clean_console();

    string name;
    long code;
    string description;
    string country;
    int quantity;
    string material;
    string gender;
    string size;

    cout << "Introduzca el nombre del producto: ";
    getline(cin, name, '\n');

    cout << "Introduzca el codigo del producto: ";
    code = validateInput_int(code);
    cin.ignore();

    cout << "Introduzca la descripcion del producto: ";
    getline(cin, description, '\n');

    cout << "Introduzca el pais de origen del producto: ";
    getline(cin, country, '\n');

    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    quantity = validateInput_int(quantity);
    cin.ignore();

    cout << "Introduzca el material: ";
    getline(cin, material, '\n');

    cout << "Introduzca el sexo: ";
    getline(cin, gender, '\n');

    cout << "Introduzca la talla: ";
    getline(cin, size, '\n');

    //En vez de declarar una variable y pasarla al metodo, se pasa como argumento la creacion del objeto
    textiles_departament.add(
            new TextilesRegister(str_to_lower(name), code, str_to_lower(description), str_to_lower(country), quantity,
                                 str_to_lower(material), str_to_lower(gender),
                                 str_to_lower(size)));

}

void add_appliances() {
    clean_console();

    string name;
    long code;
    string description;
    string country;
    int quantity;
    int warranty;
    int voltage;
    bool manual;
    string temp;

    cout << "Introduzca el nombre del producto: ";
    getline(cin, name, '\n');

    cout << "Introduzca el codigo del producto: ";
    code = validateInput_int(code);
    cin.ignore();

    cout << "Introduzca la descripcion del producto: ";
    getline(cin, description, '\n');

    cout << "Introduzca el pais de origen del producto: ";
    getline(cin, country, '\n');

    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    quantity = validateInput_int(quantity);
    cin.ignore();

    cout << "Introduzca el tiempo de garantia (en meses): ";
    warranty = validateInput_int(warranty);
    cin.ignore();

    cout << "Introduzca el voltaje: ";
    voltage = validateInput_int(voltage);
    cin.ignore();

    cout << "Tiene manual ?: ";
    getline(cin, temp, '\n');
    if (temp == "si") {
        manual = true;
    } else {
        manual = false;
    }

    appliances_department.add(
            new ApplianceRegister(str_to_lower(name), code, str_to_lower(description), str_to_lower(country),
                                  quantity, warranty, voltage, manual));

}

void add_food() {
    clean_console();

    string name;
    long code;
    string description;
    string country;
    int quantity;
    string classification;
    string day;
    string month;
    string year;

    cout << "Introduzca el nombre del producto: ";
    getline(cin, name);

    cout << "Introduzca el codigo del producto: ";
    code = validateInput_int(code);
    cin.ignore();

    cout << "Introduzca la descripcion del producto: ";
    getline(cin, description, '\n');

    cout << "Introduzca el pais de origen del producto: ";
    getline(cin, country, '\n');

    cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
    quantity = validateInput_int(quantity);
    cin.ignore();

    cout << "Introduzca la clasificacion : ";
    getline(cin, classification, '\n');

    cout << "Introduzca la fecha de vencimiento: " << endl;

    cout << "Introduzca el dia: ";
    // getline(cin, _day, '\n');
    day = visoi(day);
    cout << "Introduzca el mes: ";
    //getline(cin, _month, '\n');
    month = visoi(month);

    cout << "Introduzca el anio: ";
    //getline(cin, _year, '\n');
    year = visoi(year);

    food_department.add(
            new FoodRegister(str_to_lower(name), code, str_to_lower(description), str_to_lower(country),
                             quantity, str_to_lower(classification), day, month, year));
}

/*
 * Extraer elementos de un contenedor. Se hace una busqueda por nombre que retorna el indice y dependiendo del resultado
 * que indica existencia se procede o no a extraer el producto
 */
void extract_textiles() {
    clean_console();

    string product_name;
    int quantity;

    cout << "Introduzca el nombre del producto a extraer: ";
    cin.ignore();
    getline(cin, product_name);
    product_name = str_to_lower(product_name);

    int index = textiles_departament.find_index(product_name);

    if (index != -1) {
        cout << "Hay " << textiles_departament.in_memory_warehouse[index]->quantity << " de " << product_name
             << " en el almacen" << endl;

        cout << "Introduzca la cantidad a extraer: ";
        quantity = validateInput_int(quantity);

        textiles_departament.extract(index, quantity);
        cout << "Operacion realizada con exito. Queda " << textiles_departament.in_memory_warehouse[index]->quantity
             << " de " << product_name << " en el almacen" << endl;
        cin.ignore();
        pause();


    } else {
        cout << "Producto no encontrado\n";
        pause();
    }

}

void extract_appliances() {
    clean_console();

    string product_name;
    int quantity;

    cout << "Introduzca el nombre del producto a extraer: ";
    cin.ignore();
    getline(cin, product_name, '\n');
    product_name = str_to_lower(product_name);

    int index = appliances_department.find_index(product_name);

    if (index != -1) {
        cout << "Hay " << appliances_department.in_memory_warehouse[index]->quantity << " de " << product_name
             << " en el almacen" << endl;

        cout << "Introduzca la cantidad a extraer: ";
        quantity = validateInput_int(quantity);

        appliances_department.extract(index, quantity);
        cout << "Operacion realizada con exito. Queda " << food_department.in_memory_warehouse[index]->quantity
             << " de "
             << product_name << " en el almacen" << endl;
        cin.ignore();
        pause();
    } else {
        cout << "Producto no encontrado\n";
        pause();
    }
}

void extract_food() {
    clean_console();

    string product_name;
    int quantity;

    cout << "Introduzca el nombre del producto a extraer: ";
    cin.ignore();
    getline(cin, product_name, '\n');

    product_name = str_to_lower(product_name);

    int index = food_department.find_index(product_name);

    if (index != -1) {
        cout << "Hay " << food_department.in_memory_warehouse[index]->quantity << " de " << product_name
             << " en el almacen" << endl;

        cout << "Introduzca la cantidad a extraer: ";
        quantity = validateInput_int(quantity);

        food_department.extract(index, quantity);
        cout << "Operacion realizada con exito. Queda " << food_department.in_memory_warehouse[index]->quantity
             << " de " << product_name << " en el almacen" << endl;
        cin.ignore();
        pause();
    } else {
        cout << "Producto no encontrado\n";
        pause();
    }
}

/*
 * Funcion hibrida. Dependiendo del flujo del primer argumento escribe en consola o en el archivo
 */
void list_textiles() {
    clean_console();

    textiles_departament.list(cout, COUT);
    cin.ignore();
    pause();

}

void list_appliances() {
    clean_console();

    appliances_department.list(cout, COUT);
    cin.ignore();
    pause();
}

void list_food() {
    clean_console();

    food_department.list(cout, COUT);
    cin.ignore();
    pause();
}

/*
 * Añadir datos predeterminados para trabajar de manera mas comoda
 */
void add_dummies() {
    textiles_departament.add(
            new TextilesRegister(str_to_lower("Pullover"), 3456, str_to_lower("Descripcion con espacios"),
                                 str_to_lower("Cuba"), 333, str_to_lower("algodon suave"), str_to_lower("Masculino"),
                                 str_to_lower("Large")));
    textiles_departament.add(
            new TextilesRegister(str_to_lower("camisa"), 5874, str_to_lower("Descripcion"), str_to_lower("España"), 213,
                                 str_to_lower(
                                         str_to_lower("poliester")),
                                 str_to_lower("M"),
                                 str_to_lower("L")));
    textiles_departament.add(
            new TextilesRegister(str_to_lower("pantalon"), 2634, str_to_lower("Descripcion"), str_to_lower("Rusia"),
                                 234,
                                 str_to_lower("mezclilla"),
                                 str_to_lower("M"),
                                 str_to_lower("L")));
    textiles_departament.add(new TextilesRegister(str_to_lower("gorra"), 7846, str_to_lower("Descripcion"),
                                                  str_to_lower("India"), 875,
                                                  str_to_lower("rare"),
                                                  str_to_lower("M"),
                                                  str_to_lower("L")));
    textiles_departament.add(new TextilesRegister(str_to_lower("blusa"), 2345, str_to_lower("Descripcion"),
                                                  str_to_lower("Vietnam"), 235,
                                                  str_to_lower("hilo"),
                                                  str_to_lower("M"),
                                                  str_to_lower("L")));

    appliances_department.add(new ApplianceRegister(str_to_lower("refrigerador"), 2345, str_to_lower("Hielitosbrr"),
                                                    str_to_lower("China"), 34, 12, 220, true));
    appliances_department.add(new ApplianceRegister(str_to_lower("freezer"), 5746, str_to_lower("Hielitosbrr"),
                                                    str_to_lower("Rusia"), 34, 16, 110, false));
    appliances_department.add(new ApplianceRegister(str_to_lower("microwave"), 4257, str_to_lower("Calienteuff"),
                                                    str_to_lower("Corea"), 34, 22, 220, true));
    appliances_department.add(new ApplianceRegister(str_to_lower("lavadora"), 3756, str_to_lower("Centrifugadoooo"),
                                                    str_to_lower("Taiwan"), 34, 28, 110, false));
    appliances_department.add(new ApplianceRegister(str_to_lower("arrocera"), 7682, str_to_lower("ArrozVietnamita"),
                                                    str_to_lower("Vietnam"), 34, 36, 220, true));

    food_department.add(
            new FoodRegister(str_to_lower("pan"), 1244, str_to_lower("pancito"), str_to_lower("Ecuador"), 23,
                             str_to_lower("Solido"), "10", "12", "2030"));
    food_department.add(new FoodRegister(str_to_lower("refresco"), 4565, str_to_lower("refresquito"),
                                         str_to_lower("Bolivia"), 42,
                                         str_to_lower("Liquido"), "10", "12", "2020"));
    food_department.add(
            new FoodRegister(str_to_lower("pelly"), 3467, str_to_lower("pellycito"), str_to_lower("Peru"), 86,
                             str_to_lower("Solido"), "10", "12", "2030"));
    food_department.add(new FoodRegister(str_to_lower("ron"), 6575, str_to_lower("pancito"), str_to_lower("Chile"), 73,
                                         str_to_lower("Liquido"), "10", "12", "2030"));
    food_department.add(
            new FoodRegister(str_to_lower("puerco"), 1693, str_to_lower("pancito"), str_to_lower("Oriente"), 74,
                             str_to_lower("Solido"), "10", "12", "2030"));
}

//Guardar elementos en un archivo pasandoles como primer parametro el nombre del flujo relacionado con el fichero
void save_to_file() {
    ofstream out_Textiles("textiles.dat", ios::out);
    ofstream out_appliances("appliances.dat", ios::out);
    ofstream out_food("food.dat", ios::out);

    textiles_departament.list(out_Textiles, ARCH);
    appliances_department.list(out_appliances, ARCH);
    food_department.list(out_food, ARCH);
}


//Menus
void main_menu() {
    bool terminar = false;

    while (!terminar) {
        clean_console();

        cout << "Bienvenido al almacen Rosca Izquierda:" << endl << "Que desea hacer?: " << endl;
        cout << "1 -> Adicionar nuevos productos al almacen" << endl;
        cout << "2 -> Extraer productos del almacen" << endl;
        cout << "3 -> Listar productos" << endl;
        cout << "4 -> Salir" << endl;


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
                save_to_file();
                terminar = true;
                break;
            case 5:
                add_dummies();
                break;
            default:
                cout << "Por favor inserte un numero entre 1 y 4." << endl;
                break;
        }
    }
}

void sub_menu_a() {


    while (true) {
        clean_console();

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
        clean_console();

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
        clean_console();

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
