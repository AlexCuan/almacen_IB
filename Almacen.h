#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

//To-Do : Buscar libreria para formatear fecha y hacer Date clase padre
class Date {    //clase para almacenar la fecha
public:
    int day;
    int month;
    int year;

    Date(int _day, int _month, int _year) { //constructor de la clase
        day = _day;
        month = _month;
        year = _year;

    }

    void mostrarFecha() { //metodo para mostrar la fecha
        cout << day << "-" << month << "-" << year;
    }


};

class RegistroProducto {     // superclase prodcuto
public:
    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;

    RegistroProducto() {};

    RegistroProducto(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad) {
        nombre = _nombre;
        codigo = _codigo;
        descripcion = _descripcion;
        paisOrigen = _paisOrigen;
        cantidad = _cantidad;

    }

    virtual void add_register() {
        cout << "Introduzca el nombre del producto: ";
        cin >> this->nombre;
        cout << "Introduzca el codigo del producto: ";
        cin >> this->codigo;
        cout << "Introduzca la descripcion del producto: ";
        cin >> this->descripcion;
        cout << "Introduzca el pais de origen del producto: ";
        cin >> this->paisOrigen;
        cout << "Introduzca la cantidad de elementos que va a tener el producto: ";
        this->cantidad;
    };
    // virtual void eliminar();
    //virtual void imprimir();

};

class RegistroTextiles : public RegistroProducto {
public:
    string material;
    string sexo;
    char talla;

    RegistroTextiles() {};

    RegistroTextiles(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                     string _material, char _sexo, char _talla) : RegistroProducto(_nombre, _codigo, _descripcion,
                                                                                   _paisOrigen,
                                                                                   _cantidad) {
        material = _material;
        sexo = _sexo;
        talla = _talla;

    }

    void add_register() {
        RegistroProducto::add_register();
        cout << "Introduzca el material : ";
        cin >> this->material;
        cout << "Introduzca el sexo: ";
        cin >> this->sexo;
        cout << "Introduzca la talla: ";
        cin >> this->talla;

    }

    void imprimir(ostream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen
               << " " << cantidad << " " << material << " " << sexo << " " << talla << endl;
    }

};

class RegistroElectrodomesticos : public RegistroProducto {
public:
    int tiempo; //tiempo en meses
    int voltaje;
    bool manual;

    RegistroElectrodomesticos() {};

    RegistroElectrodomesticos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                              int _tiempo, int _voltaje, bool _manual) : RegistroProducto(_nombre, _codigo,
                                                                                          _descripcion, _paisOrigen,
                                                                                          _cantidad) {
        tiempo = _tiempo;
        voltaje = _voltaje;
        manual = _manual;
    }

    void imprimir(fstream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen
               << " " << cantidad << " " << tiempo << " " << voltaje << " ";

        salida << (manual == true) ? "Manual de usuario incluido\n" : "Sin manual de usuario\n";

    }

    void add_register() {
        RegistroProducto::add_register();
        string temp;
        cout << "Introduzca el tiempo: ";
        cin >> this->tiempo;
        cout << "Introduzca el voltaje: ";
        cin >> this->voltaje;
        cout << "Tiene manual ?: ";
        cin >> temp;
        if (temp == "si") {
            this->manual = true;
        } else {
            this->manual = false;
        }
    }
};

class RegistroAlimentos : public RegistroProducto { //, public Date
public:
    string clasificacion;
    string empleado;
    long codigoEstiba;
    bool eliminado;

    RegistroAlimentos() {};

    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen,
                      int _cantidad, //int _dia, int _mes, int _anio,
                      string _clasificacion, string _empleado, long _codigoEstiba, bool _eliminado) : RegistroProducto(
            _nombre, _codigo, _descripcion, _paisOrigen, _cantidad)
    //Date(_dia, _mes, _anio)
    {
        clasificacion = _clasificacion;
        empleado = _empleado; //To-Do : Reestructurar este atributo
        codigoEstiba = _codigoEstiba;
        eliminado = _eliminado;

    }

    void imprimir(fstream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen << " "
               << cantidad <</*<< day << " " << month << " " << year <<*/ " " << clasificacion << " " << empleado
               << " " << codigoEstiba << " " << endl;
    }

    void add_register() {
        RegistroProducto::add_register();
        string temp;
        cout << "Introduzca la clasificacion : ";
        cin >> this->clasificacion;
        cout << "Introduzca el empleado : ";
        cin >> this->empleado;
        cout << "Introduzca el codigo de estiba: ";
        cin >> this->codigoEstiba;
        cout << "Esta eliminado? : ";
        cin >> temp;
        if (temp == "si") {
            this->eliminado = true;
        } else {
            this->eliminado = false;
        }
    }
};



class ContainerTextiles {
public:
    int size_of_array = 4;
    int counter = 0;
    RegistroTextiles **in_memory_warehouse;

    ContainerTextiles() {
        in_memory_warehouse = new RegistroTextiles*[size_of_array];
    }

    void add(RegistroTextiles* new_entry)
    {
        if(counter == size_of_array)
        {
            cout << "Extending array..." << endl;

            size_of_array *= 2;
            RegistroTextiles** new_array = new RegistroTextiles*[size_of_array];

            for(int i = 0; i < size_of_array/2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete [] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }
        else
        {
            cout << "Added without extending." << endl;
        }

        in_memory_warehouse[counter] = new_entry;
        counter++;
    }
};

class ContainerElectrodomesticos {
public:
    int size_of_array;
    int counter;
    RegistroElectrodomesticos **in_memory_warehouse;

    ContainerElectrodomesticos(int size_of_array, int counter) {
        this->size_of_array = size_of_array;
        this->counter = counter;
        in_memory_warehouse = new RegistroElectrodomesticos*[size_of_array];
    }

};

class ContainerAlimentos {
public:
    int size_of_array;
    int counter;
    RegistroAlimentos **in_memory_warehouse;

    ContainerAlimentos(int size_of_array, int counter) {
        this->size_of_array = size_of_array;
        this->counter = counter;
        in_memory_warehouse = new RegistroAlimentos*[size_of_array];
    }

};
