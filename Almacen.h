#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

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

class Producto {     // superclase prodcuto
public:
    string nombre;
    long codigo;
    string descripcion;
    string paisOrigen;
    int cantidad;

    Producto(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad) {
        nombre = _nombre;
        codigo = _codigo;
        descripcion = _descripcion;
        paisOrigen = _paisOrigen;
        cantidad = _cantidad;

    }

    //virtual void agregar();
    // virtual void eliminar();
    //virtual void imprimir();

};

class Textiles : public Producto {
public:
    string material;
    string sexo;
    char talla;

    Textiles(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
             string _material, char _sexo, char _talla) : Producto(_nombre, _codigo, _descripcion, _paisOrigen,
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

class Electrodomesticos : public Producto {
public:
    int tiempo; //tiempo en meses
    int voltaje;
    bool manual;

    Electrodomesticos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      int _tiempo, int _voltaje, bool _manual) : Producto(_nombre, _codigo, _descripcion, _paisOrigen,
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

class Alimentos : public Producto, public Date {
public:
    string clasificacion;
    string empleado;
    long codigoEstiba;
    bool eliminado;

    Alimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad, int _dia, int _mes,
              int _anio, string _clasificacion, string _empleado, long _codigoEstiba,
              bool _eliminado) : Producto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad),
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

