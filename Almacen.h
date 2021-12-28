#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

void limpiar_consola() {
    system("clear");
}

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

    virtual void imprimir(ostream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen << endl;
    }

    virtual ~RegistroProducto() {};

};

class RegistroTextiles : public RegistroProducto {
public:
    string material;
    char sexo;
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

    void imprimir(ostream &salida) {
        RegistroProducto::imprimir(salida);
        salida << cantidad << " " << material << " " << sexo << " " << talla << endl;
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

    void imprimir(ostream &salida) {
        RegistroProducto::imprimir(salida);
        salida << cantidad << " " << tiempo << " " << voltaje << " ";

        salida << (manual == true) ? "Manual de usuario incluido\n" : "Sin manual de usuario\n";

    }


};

class RegistroAlimentos : public RegistroProducto { //, public Date
public:
    string clasificacion;
    string empleado;
    long codigoEstiba;
    // bool eliminado;

    RegistroAlimentos() {};

    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      string _clasificacion, string _empleado, long _codigoEstiba)
            : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad)
    //Date(_dia, _mes, _anio)
    {
        clasificacion = _clasificacion;
        empleado = _empleado;
        codigoEstiba = _codigoEstiba;

    } // este constructor sera para leer del archivo
    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      string _clasificacion)
            : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad)
    //Date(_dia, _mes, _anio)
    {
        clasificacion = _clasificacion;

    }

    void imprimir(ostream &salida) {
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen << " "
               << cantidad << " " << clasificacion << endl;
    }
};


