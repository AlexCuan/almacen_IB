#include "iostream"
#include <fstream>
#include <stdlib.h>
#include <string>

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

            size_of_array *= 2;
            RegistroTextiles** new_array = new RegistroTextiles*[size_of_array];

            for(int i = 0; i < size_of_array/2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete [] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }


        in_memory_warehouse[counter] = new_entry;
        counter++;
    }
    void extract(int index, int cant)
    {  if(index == -1){
        cout << "Producto no encontrado\n";
    }
        else if(cant > in_memory_warehouse[index]->cantidad){
        cout << "Esa cantidad no esta disponible en el almacen\n";

    }
        else if(cant < in_memory_warehouse[index]->cantidad){ //Aqui deberia
            in_memory_warehouse[index]->cantidad -= cant;
    }
        else{
            counter--;

            for(int i = index; i < counter; i++)
            {
                in_memory_warehouse[i] = in_memory_warehouse[i+1];
            }
       }

    }
    int find_index(string name)
    { /*debe tenerse en cuenta que el usuario puede emplera lo mismo mayuscuka q minucula por lo q es
 conveniente cambiar la entrada del usuario ya sea todo en mayuscula o en minuysculas*/
        for(int i = 0; i < counter; i++)
        {
            if(in_memory_warehouse[i]->nombre == name)
            {
                return i;
            }
        }
        return -1;
    }
    void list(){
        for(int i = 0; i < counter; i++)
        {
           in_memory_warehouse[i]->imprimir(cout);
           // esto sirve para llenar el regitro tambien
        }
    }
}

;

class ContainerElectrodomesticos {
public:
    int size_of_array = 4;
    int counter = 0;
    RegistroElectrodomesticos **in_memory_warehouse;

    ContainerElectrodomesticos(){
        in_memory_warehouse = new RegistroElectrodomesticos*[size_of_array];
    }

    /*ContainerElectrodomesticos(int size_of_array, int counter) {
        this->size_of_array = size_of_array;
        this->counter = counter;
        in_memory_warehouse = new RegistroElectrodomesticos*[size_of_array];
    }*/
    /*Los parametros deben quedar inicializados, esta operacion no puede depender del usuario*/
    void add(RegistroElectrodomesticos* new_entry)
    {
        if(counter == size_of_array)
        {
            size_of_array *= 2;
            RegistroElectrodomesticos** new_array = new RegistroElectrodomesticos*[size_of_array];

            for(int i = 0; i < size_of_array/2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete [] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }


        in_memory_warehouse[counter] = new_entry;
        counter++;
    }
    void extract(int index, int cant)
    {  if(index == -1){
            cout << "Producto no encontrado\n";
        }
        else if(cant > in_memory_warehouse[index]->cantidad){
            cout << "Esa cantidad no esta disponible en el almacen\n";

        }
        else if(cant < in_memory_warehouse[index]->cantidad){
            in_memory_warehouse[index]->cantidad -= cant;
        }
        else{
            counter--;

            for(int i = index; i < counter; i++)
            {
                in_memory_warehouse[i] = in_memory_warehouse[i+1];
            }
        }

    }
    int find_index(string name)
    { /*debe tenerse en cuenta que el usuario puede emplera lo mismo mayuscuka q minucula por lo q es
 conveniente cambiar la entrada del usuario ya sea todo en mayuscula o en minuysculas*/
        for(int i = 0; i < counter; i++)
        {
            if(in_memory_warehouse[i]->nombre == name)
            {
                return i;
            }
        }
        return -1;
    }
    void list(){
        for(int i = 0; i < counter; i++)
        {
            in_memory_warehouse[i]->imprimir(cout);
            // esto sirve para llenar el regitro tambien
        }
    }

};

class ContainerAlimentos {
public:
    int size_of_array;
    int counter;
    RegistroAlimentos **in_memory_warehouse;

    /*ContainerAlimentos(int size_of_array, int counter) {
        this->size_of_array = size_of_array;
        this->counter = counter;
        in_memory_warehouse = new RegistroAlimentos*[size_of_array];
    }*/
    void add(RegistroAlimentos* new_entry)
    {
        if(counter == size_of_array)
        {
            size_of_array *= 2;
            RegistroAlimentos** new_array = new RegistroAlimentos*[size_of_array];

            for(int i = 0; i < size_of_array/2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete [] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }


        in_memory_warehouse[counter] = new_entry;
        counter++;
    }
    void extract(int index, int cant) /* se debe poner una condicional para comprobar que el producto esta
 vencido mediante la fcha de vencimiento*/
    {  if(index == -1){
            cout << "Producto no encontrado\n";
        }
        else if(cant > in_memory_warehouse[index]->cantidad){
            cout << "Esa cantidad no esta disponible en el almacen\n";

        }
        else if(cant <= in_memory_warehouse[index]->cantidad){
            in_memory_warehouse[index]->cantidad -= cant;
            cout << "introduzca su nombre para extraer el producto: ";
           string nombreEmpleado;
            cin >> nombreEmpleado;
            in_memory_warehouse[index]->empleado = nombreEmpleado;
            cout << "Introduzca su codigo de estiba: ";
            long codigoEstib;
            cin >> codigoEstib;
            in_memory_warehouse[index]->codigoEstiba = codigoEstib;
        }
        /*else{
            counter--;

            for(int i = index; i < counter; i++)
            {
                in_memory_warehouse[i] = in_memory_warehouse[i+1];
            }
        }*/

    }
    int find_index(string name)
    { /*debe tenerse en cuenta que el usuario puede emplera lo mismo mayuscuka q minucula por lo q es
 conveniente cambiar la entrada del usuario ya sea todo en mayuscula o en minuysculas*/
        for(int i = 0; i < counter; i++)
        {
            if(in_memory_warehouse[i]->nombre == name)
            {
                return i;
            }
        }
        return -1;
    }
    void list(){
        for(int i = 0; i < counter; i++)
        {
            in_memory_warehouse[i]->imprimir(cout);
            // esto sirve para llenar el regitro tambien
        }
    }
};