#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "utilidades.h"

using namespace std;

void limpiar_consola() {
    system("clear");
}

//To-Do : Buscar libreria para formatear fecha y hacer Date clase padre
class Date {    //clase para almacenar la fecha
public:
    string day;
    string month;
    string year;

    int fecha = fechaEntera();

    Date(string _day, string _month, string _year){
        day = _day;
        month = _month;
        year = _year;

    }
    Date(){}

    int fechaEntera(){
        if(atoi(day.c_str())<10)
            day = "0" + day;
        if (atoi(month.c_str())<10)
            month = "0"+ month;
        string fechaCadena = year + month + day;
        int fecha = atoi(fechaCadena.c_str());
        return fecha;
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
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen <<" "<< cantidad;
    }

    virtual ~RegistroProducto() {};

};

class RegistroTextiles : public RegistroProducto {
public:
    string material;
    string sexo;
    string talla;

    RegistroTextiles() {};

    RegistroTextiles(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                     string _material, string _sexo, string _talla) : RegistroProducto(_nombre, _codigo, _descripcion,
                                                                                   _paisOrigen,
                                                                                   _cantidad) {
        material = _material;
        sexo = _sexo;
        talla = _talla;

    }

    void imprimir(ostream &salida) {
        RegistroProducto::imprimir(salida);
        salida <<" "<< material << " " << sexo << " " << talla << endl;
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
        salida <<" "<< tiempo << " " << voltaje <<" "<<manual<<endl;

        //salida << (manual == true) ? "Manual de usuario incluido\n" : "Sin manual de usuario\n";
        //Aqui realmente no hace falta poner todo eso, el arhivo no lo lee el usuario sino nosotros. Con un bool basta
    }


};

class RegistroAlimentos : public RegistroProducto , public Date{ //, public Date
public:
    string clasificacion;
    string empleado = "Empleado";
    long codigoEstiba = 0;
    // bool eliminado;

    RegistroAlimentos() {};

    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      string _clasificacion, string _day, string _month, string _year, string _empleado, long _codigoEstiba)
            : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad), Date(_day, _month, _year)
    //Date(_dia, _mes, _anio)
    {
        clasificacion = _clasificacion;
        empleado = _empleado;
        codigoEstiba = _codigoEstiba;

    } // este constructor sera para leer del archivo
    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      string _clasificacion, string _day, string _month, string _year)
            : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad), Date(_day, _month, _year)
    //Date(_dia, _mes, _anio)
    {
        clasificacion = _clasificacion;

    }

    void imprimir(ostream &salida) {
        RegistroProducto::imprimir(salida);
        salida<<" " << clasificacion << " ";
        if(codigoEstiba != 0){
            cout << empleado <<" " << codigoEstiba << " ";
        }
        salida << day << " " << month << " " << year<<endl;

    }
};


