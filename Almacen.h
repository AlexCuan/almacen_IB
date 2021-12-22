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
    RegistroProducto();
    RegistroProducto(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad) {
        nombre = _nombre;
        codigo = _codigo;
        descripcion = _descripcion;
        paisOrigen = _paisOrigen;
        cantidad = _cantidad;

    }

    virtual void add_register(){
        cout<<"Introduzca el nombre del producto: ";cin>>this->nombre;
        cout<<"Introduzca el codigo del producto: ";cin>>this->codigo;
        cout<<"Introduzca la descripcion del producto: ";cin>>this->descripcion;
        cout<<"Introduzca el pais de origen del producto: ";cin>>this->paisOrigen;
        cout<<"Introduzca la cantidad de elementos que va a tener el producto: ";this->cantidad;
    };
    // virtual void eliminar();
    //virtual void imprimir();

};

class RegistroTextiles : public RegistroProducto {
public:
    string material;
    string sexo;
    char talla;

    RegistroTextiles(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                     string _material, char _sexo, char _talla) : RegistroProducto(_nombre, _codigo, _descripcion,
                                                                                   _paisOrigen,
                                                                                   _cantidad) {
        material = _material;
        sexo = _sexo;
        talla = _talla;

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

    RegistroElectrodomesticos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                              int _tiempo, int _voltaje, bool _manual) : RegistroProducto(_nombre, _codigo,
                                                                                          _descripcion, _paisOrigen,
                                                                                          _cantidad) {
        tiempo = _tiempo;
        voltaje = _voltaje;
        manual = _manual;
    }

    void imprimir(ostream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen
               << " " << cantidad << " " << tiempo << " " << voltaje << " ";

        salida << (manual == true) ? "Manual de usuario incluido\n" : "Sin manual de usuario\n";

    }

};

class RegistroAlimentos : public RegistroProducto, public Date {
public:
    string clasificacion;
    string empleado;
    long codigoEstiba;
    bool eliminado;

    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad, int _dia,
                      int _mes,
                      int _anio, string _clasificacion, string _empleado, long _codigoEstiba,
                      bool _eliminado) : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad),
                                         Date(_dia, _mes, _anio) {
        clasificacion = _clasificacion;
        empleado = _empleado;
        codigoEstiba = _codigoEstiba;
        eliminado = _eliminado;

    }

    void imprimir(ostream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen << " "
               << cantidad << " " << day << " " << month << " " << year << " " << clasificacion << " " << empleado
               << " " << codigoEstiba << " " << endl;
    }
};


