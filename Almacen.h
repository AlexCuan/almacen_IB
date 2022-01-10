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
    int entire_date(){
        if(atoi(day.c_str())<10)
            day = "0" + day;
        if (atoi(month.c_str())<10)
            month = "0"+ month;
        string dateString = year + month + day;
        int date = atoi(dateString.c_str());
        return date;
    }

    void print_date() { //metodo para mostrar la fecha
        cout << day << "-" << month << "-" << year;
    }
};

/*
 *Clase padre de la que heredan los diferentes tipos de productos
 */
class ProductRegister {
public:
    string name;
    long code;
    string description;
    string country;
    int quantity;

    ProductRegister() {};

    ProductRegister(string _name, long _code, string _description, string _country, int _quantity) {
        name = _name;
        code = _code;
        description = _description;
        country = _country;
        quantity = _quantity;

    }

    /*
    * Funcion base hibrida para imprimir tanto en consola como en archivo
    * Salida representa el valor en consola del flujo de datos, puede ser cout o un archivo abierto
    * ARCH y COUT  es una constante para manualmente reconocer el flujo
    */
    virtual void print(ostream &output, int stream)
    {
        // Si el flujo es hacia un archivo convierte las cadenas en una palabra sin espacio
        if(stream == ARCH)
        {
            name = contract(name);
            description = contract(description);
            country = contract(country);
        }
        output << name << " " << code << " " << description << " " << country << " " << quantity;
    }

};

class TextilesRegister : public ProductRegister {
public:
    string material;
    string gender;
    string size;

    TextilesRegister() {};

    TextilesRegister(string _name, long _code, string _description, string _country, int _quantity,
                     string _material, string _gender, string _size) : ProductRegister(_name, _code, _description,
                                                                                       _country, _quantity){
        material = _material;
        gender = _gender;
        size = _size;

    }

    void print(ostream &output, int stream)
    {
        ProductRegister::print(output, stream);
        if(stream == ARCH)
        {
            material = contract(material);
            gender = contract(gender);
            size = contract(size);
        }
        output << " " << material << " " << gender << " " << size << endl;
    }

};

class ApplianceRegister : public ProductRegister {
public:
    int warranty; //tiempo en meses
    int voltage;
    bool manual;

    ApplianceRegister() {};

    ApplianceRegister(string _name, long _code, string _description, string _country, int _quantity,
                      int _time, int _voltage, bool _manual) : ProductRegister(_name, _code,
                                                                               _description, _country,
                                                                               _quantity) {
        warranty = _time;
        voltage = _voltage;
        manual = _manual;
    }

    void print(ostream &output, int stream)
    {
        ProductRegister::print(output, stream);
        output << " " << warranty << " " << voltage << " " << manual << endl;
    }
};

/*
 * Clase alimentos que tiene 2 atributos por default para trabajar mas comodos. Si estos dejan de tener su valor por defecto
 * se listaran en consola, de no ser asi no se listaran. En cambio, sea cual sea su valor se escribira y leera de un archivo,
 * para eso 2 constructores
 */
class FoodRegister : public ProductRegister , public Date{
public:
    string classification;
    string employee = "Empleado";
    long stowage_code = 0;

    FoodRegister() {};

    //Constructor para leer informacion de un archivo
    FoodRegister(string _name, long _code, string _description, string _country, int _quantity,
                 string _classification, string _day, string _month, string _year, string _employee, long _stowage_code)
            : ProductRegister(_name, _code, _description, _country, _quantity), Date(_day, _month, _year)

    {
        classification = _classification;
        employee = _employee;
        stowage_code = _stowage_code;

    }

    //Constructor para crear objetos introducidos por el usuario. No se pasa como argumento empleado y codigo de estiba
    //que no estan concebidos para la creacion del objeto, sino para la extraccion(ver biblioteca Container.h)
    FoodRegister(string _name, long _code, string _description, string _country, int _quantity,
                 string _classification, string _day, string _month, string _year)
            : ProductRegister(_name, _code, _description, _country, _quantity), Date(_day, _month, _year)

    {
        classification = _classification;

    }

    void print(ostream &output, int stream)
    {
        ProductRegister::print(output, stream);

        if(stream == ARCH)
        {
            classification = contract(classification);
            employee = contract(employee);
            day = contract(day);
            month = contract(month);
            year = contract(year);

            output << " " << classification << " " << day << " " << month << " " << year << " " << employee << " " << stowage_code << endl;
        }


        else if(stream == COUT)
        {
            output << " " << classification << " " << day << " " << month << " " << year;
            if(stowage_code != 0)
                output << " " << employee << " " << stowage_code << endl;
            else
                output << endl;

        }
    }
};


