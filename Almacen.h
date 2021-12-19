#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

class Date{    //clase para almacenar la fecha
    public:
    int day;
    int month;
    int year;

    Date(int _day, int _month, int _year){ //constructor de la clase
        day = _day;
        month = _month;
        year = _year;

    }

        void mostrarFecha(){ //metodo para mostrar la fecha
            cout << day << "-" << month << "-" << year;
        }


};

class Producto{     // superclase prodcuto
    public:
    char nombre[15];
    long codigo;
    char descripcion[15];
    char paisOrigen[15];
    int cantidad;
    Producto(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad){
        strncpy(nombre, _nombre, 13);
        nombre[14] = '/0';
        codigo = _codigo;
        strncpy(descripcion, _descripcion, 13);
        descripcion[14] = '/0';
        strncpy(paisOrigen, _paisOrigen, 13);
        paisOrigen[14] = '/0';
        cantidad = _cantidad;

    }
    //virtual void agregar();
   // virtual void eliminar();
    virtual void imprimir();

};

class Textiles: public Producto{
    public:
    char material[15];
    char sexo;
    char talla;

    Textiles(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
    string _material, char _sexo, char _talla) : Producto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad){
        strncpy(material, _material, 13);
        material[14] ='/0';
        sexo = _sexo;
        talla = _talla;

    }

    void imprimir(ostream &salida){
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen
        << " " << cantidad << " " << material << " " << sexo << " " << talla << endl;
    }

};

class Electrodomesticos: public Producto{
    public:
    int tiempo; //tiempo en meses
    int voltaje;
    bool manual;

    Electrodomesticos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad,
    int _tiempo, int _voltaje, bool _manual) : Producto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad){
        tiempo = _tiempo;
        voltaje = _voltaje;
        manual = _manual;
    }

    void imprimir(ostream &salida){
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen
        << " " << cantidad << " " << tiempo << " " << voltaje << " " ;

        salida << (manual == true)? "Manual de usuario incluido\n": "Sin manual de usuario\n";

    }

};

class Alimentos: public Producto, public Date{
      public:
      char clasificacion[15];
      char empleado[15];
      long codigoEstiba;
      bool eliminado;

    Alimentos(string _nombre, long _codigo, string _descripcion, string _paisOrigen, int _cantidad, int _dia, int _mes,
    int _anio, string _clasificacion,
     ): Producto(_nombre, _codigo, _descripcion, _paisOrigen, _cantidad), Date(_dia, _mes, _anio){
     strncpy(clasificacion, _clasificacion, 13);

     empleado = " ";
     codigoEstiba = 0;
     eliminado = false;

     }

    void imprimir(ostream &salida){
        salida << nombre << " " << codigo << " " << descripcion << " " << paisOrigen << " "
        << cantidad << " " << day << " " << month << " " << year << " " << clasificacion << " " << empleado
        << " " << codigoEstiba << " " << endl;
    }
};

 /*ESTA CLASE ES SOLO PARA LOS TEXTILES, HYA Q HACER UNA CLASE PADRE Y TRES HIJAS UNA DE ELLAS SERIA ESTA, SOLAMENTE DEBEN HEREDAR
 LOS DOS PRIMEROS ATRIBUTOS Y EL METODO FIND, LO DEMAS HAY Q HACERLO PARA CADA CLASE*/
 /*class ContainerTextiles{ // clase que contiene los metodos para manipular la clase textiles
     public:
       int max_size;
       int counter;
    Textiles** producto_textiles; // Array of Textiles pointers.

    ContainerTextiles()
    {
        max_size = 2;
        counter = 0;
        producto_textiles = new Textiles*[max_size];
    }

    void agregarTextiles(Textiles* productoTextilesAdd)
    {
        if(counter == max_size)
        {
            cout << "Extending array..." << endl;

            max_size *= 2;
            Textiles** new_array = new Textiles*[max_size];

            for(int i = 0; i < max_size/2; i++)
            {
                new_array[i] = producto_textiles[i];
            }

            delete [] producto_textiles;
            producto_textiles = new_array;
        }
        else
        {
            cout << "Added without extending." << endl;
        }

        producto_textiles[counter] = productoTextilesAdd; //agrega el nuevo producto
        counter++;
    }
     void extract(int index)
    {
       if(producto_textiles[index]->codigo/1000 != 3){
             counter--;

            for(int i = index; i < counter; i++)
            {
                producto_textiles[i] = producto_textiles[i+1];
            }
        }

    }
     int find_one_with_data_a(string nombre)
    {
        for(int i = 0; i < counter; i++)
        {
            if(producto_textiles[i]->nombre == nombre)
            {
                return i;
            }
        }
        return -1;
    }

};
*/

