#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "utilidades.h"
#define COUT 1
#define ARCH 2
using namespace std;

/*
 * Clase padre de la que hereda RegistroAlimentos. Por problemas de abstraccion y encapsulamiento se separa de RegistroAlimentos
 */
class Date {
public:
    string day;
    string month;
    string year;


    Date(string _day, string _month, string _year){
        day = _day;
        month = _month;
        year = _year;

    }
    Date(){}

    //Devuelve la fecha en el mismo formato de la computadora
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

/*
 *Clase padre de la que heredan los diferentes tipos de productos
 */
class RegistroProducto {
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

    /*
    * Funcion base hibrida para imprimir tanto en consola como en archivo
    * Salida representa el valor en consola del flujo de datos, puede ser cout o un archivo abierto
    * ARCH y COUT  es una constante para manualmente reconocer el flujo
    */
    virtual void imprimir(ostream &salida, int flujo)
    {
        // Si el flujo es hacia un archivo convierte las cadenas en una palabra sin espacio
        if(flujo == ARCH)
        {
            nombre = contraer(nombre);
            descripcion = contraer(descripcion);
            paisOrigen = contraer(paisOrigen);
        }
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen <<" "<< cantidad;
    }

};

class RegistroTextiles : public RegistroProducto {
public:
    string material;
    string sexo;
    string talla;

    RegistroTextiles() {};

    RegistroTextiles(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                     string _material, string _sexo, string _talla) : RegistroProducto(_nombre, _codigo, _descripcion,
                                                                                   _paisOrigen, _cantidad){
        material = _material;
        sexo = _sexo;
        talla = _talla;

    }

    void imprimir(ostream &salida, int flujo)
    {
        RegistroProducto::imprimir(salida, flujo);
        if(flujo == ARCH)
        {
            material = contraer(material);
            sexo = contraer(sexo);
            talla = contraer(talla);
        }
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

    void imprimir(ostream &salida, int flujo)
    {
        RegistroProducto::imprimir(salida, flujo);
        salida <<" "<< tiempo << " " << voltaje <<" "<<manual<<endl;
    }
};

/*
 * Clase alimentos que tiene 2 atributos por default para trabajar mas comodos. Si estos dejan de tener su valor por defecto
 * se listaran en consola, de no ser asi no se listaran. En cambio, sea cual sea su valor se escribira y leera de un archivo,
 * para eso 2 constructores
 */
class RegistroAlimentos : public RegistroProducto , public Date{
public:
    string clasificacion;
    string empleado = "Empleado";
    long codigoEstiba = 0;

    RegistroAlimentos() {};

    //Constructor para leer informacion de un archivo
    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      string _clasificacion, string _day, string _month, string _year, string _empleado, long _codigoEstiba)
            : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad), Date(_day, _month, _year)

    {
        clasificacion = _clasificacion;
        empleado = _empleado;
        codigoEstiba = _codigoEstiba;

    }

    //Constructor para crear objetos introducidos por el usuario. No se pasa como argumento empleado y codigo de estiba
    //que no estan concebidos para la creacion del objeto, sino para la extraccion(ver biblioteca Container.h)
    RegistroAlimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
                      string _clasificacion, string _day, string _month, string _year)
            : RegistroProducto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad), Date(_day, _month, _year)

    {
        clasificacion = _clasificacion;

    }

    void imprimir(ostream &salida, int flujo)
    {
        RegistroProducto::imprimir(salida, flujo);

        if(flujo == ARCH)
        {
            clasificacion = contraer(clasificacion);
            empleado = contraer(empleado);
            day = contraer(day);
            month = contraer(month);
            year = contraer(year);

            salida<<" " << clasificacion << " " << day << " " << month << " " << year<< " " << empleado <<" " << codigoEstiba << endl;
        }


        else if(flujo == COUT)
        {
            salida<<" " << clasificacion << " " << day << " " << month << " " << year;
            if(codigoEstiba != 0)
                salida << " " << empleado <<" " << codigoEstiba << endl;
            else
                salida << endl;

        }
    }
};


