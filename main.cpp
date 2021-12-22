#include "Almacen.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;

class Contenedor{ // clase que contiene los metodos y atributos para trabajar con arreglos de de tipo textil alimento y electrodomestico
    public:
    Producto** productos; //arreglo donde se almacenaran los productos
    int max_size;
    int counter;

    Contenedor(){
               max_size = 2;
               counter = 0;
               productos = new Producto*[max_size];

    }
    void add(Producto* productoAdd)
    {
        if(counter == max_size)
        {

            max_size *= 2;
            Producto** new_array = new productos*[max_size];

            for(int i = 0; i < max_size/2; i++)
            {
                new_array[i] = productos[i];
            }

            delete [] departamentoTextiles;
            departamentoTextiles = new_array;
        }


        productos[counter] = productoAdd; //se agrega el nuevo producto
        counter++;
    }


};

Contenedor productosTextiles = Contenedor(); //con esta instancia se crea un arrglo para la clase textiles


int main(){
cout << "HOLA MUNDO";
    return 0;
}
