#include "iostream"
#include <fstream>
#include <cstdlib>
#include <string>
/*
 * Clase contenedor. Actuara como almacen temporal en memoria. Se inicializa con un tamaño predeterminado que no tiene
 * ninguna especifidad, puede ser cualquier numero. El contador debera ser inicializado en 0 debido a su naturaleza. El
 * tercer atributo es un arreglo de punteros el cual guardara punteros hacia las posiciones en memoria de los objetos
 * creados.
 */
class ContainerTextiles{
public:
    int size_of_array = 4;
    int counter = 0;
    RegistroTextiles **in_memory_warehouse;


    ContainerTextiles()
    {
        in_memory_warehouse = new RegistroTextiles *[size_of_array];
    }

    /*
     * Agregar nuevos objetos. Al llegar al tope se creara un array nuevo con el doble de tamaño, se copiara la informacion,
     * se borrara el array viejo y se renombrara el nuevo
     */
    void add(RegistroTextiles *new_entry)
    {
        if (counter == size_of_array)
        {

            size_of_array *= 2;
            RegistroTextiles **new_array = new RegistroTextiles *[size_of_array];

            for (int i = 0; i < size_of_array / 2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete[] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }


        in_memory_warehouse[counter] = new_entry;
        counter++;
    }

    /*
     * Eliminar un elemnto del array. Si llega a 0 se reposiciona el arreglo y se elimina por completo el objeto
     */
    void extract(int index, int cant) {
        if (cant > in_memory_warehouse[index]->cantidad)
        {
            cout << "Esa cantidad no esta disponible en el almacen\n";
        } else if (cant < in_memory_warehouse[index]->cantidad)
        {
            in_memory_warehouse[index]->cantidad -= cant;
        } else
            {
            counter--;

            for (int i = index; i < counter; i++)
            {
                in_memory_warehouse[i] = in_memory_warehouse[i + 1];
            }
        }

    }

    //Buscar indice de objeto por nombre. De no existir retorna -1
    int find_index(string name)
    {
        for (int i = 0; i < counter; i++)
        {
            if (in_memory_warehouse[i]->nombre == name)
            {
                return i;
            }
        }
        return -1;
    }

    /*
     * Funcion hibrida. Lista o escribe en archivo dependiendo del flujo
     */
    void list(ostream &salida, int flujo)
    {
        for (int i = 0; i < counter; i++)
        {
            in_memory_warehouse[i]->imprimir(salida, flujo);
        }
    }
};

class ContainerElectrodomesticos {
public:
    int size_of_array = 4;
    int counter = 0;
    RegistroElectrodomesticos **in_memory_warehouse;

    ContainerElectrodomesticos()
    {
        in_memory_warehouse = new RegistroElectrodomesticos *[size_of_array];
    }

    void add(RegistroElectrodomesticos *new_entry)
    {
        if (counter == size_of_array)
        {
            size_of_array *= 2;
            RegistroElectrodomesticos **new_array = new RegistroElectrodomesticos *[size_of_array];

            for (int i = 0; i < size_of_array / 2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete[] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }


        in_memory_warehouse[counter] = new_entry;
        counter++;
    }

    void extract(int index, int cant)
    {
        if (cant > in_memory_warehouse[index]->cantidad) {
            cout << "Esa cantidad no esta disponible en el almacen\n";

        } else if (cant < in_memory_warehouse[index]->cantidad) {
            in_memory_warehouse[index]->cantidad -= cant;
        } else {
            counter--;

            for (int i = index; i < counter; i++) {
                in_memory_warehouse[i] = in_memory_warehouse[i + 1];
            }
        }

    }

    int find_index(string name)
    {
        for (int i = 0; i < counter; i++)
        {
            if (in_memory_warehouse[i]->nombre == name) {
                return i;
            }
        }
        return -1;
    }

    void list(ostream &salida, int flujo)
    {
        for (int i = 0; i < counter; i++) {
            in_memory_warehouse[i]->imprimir(salida, flujo);
        }
    }

};

class ContainerAlimentos {
public:
    int size_of_array = 4;
    int counter = 0;
    RegistroAlimentos **in_memory_warehouse;

    ContainerAlimentos()
    {
        in_memory_warehouse = new RegistroAlimentos *[size_of_array];
    }

    void add(RegistroAlimentos *new_entry)
    {
        if (counter == size_of_array)
        {
            size_of_array *= 2;
            RegistroAlimentos **new_array = new RegistroAlimentos *[size_of_array];

            for (int i = 0; i < size_of_array / 2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete[] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }


        in_memory_warehouse[counter] = new_entry;
        counter++;
    }

    /*
     * Extraer alimentos. Adicionalmente se identifica si esta vencido y el metodo de extraccion pasa a requerir 2 elementos
     * adicionales y no se borra por completo
     */
    void extract(int index, int cant)
    {
        if (obtainDate() >= in_memory_warehouse[index]->fechaEntera())
        {
            cout << "Este producto ya esta vencido\n";

            if (cant > in_memory_warehouse[index]->cantidad)
            {
                cout << "Esa cantidad no esta disponible en el almacen\n";

            } else if (cant <= in_memory_warehouse[index]->cantidad)
            {
                in_memory_warehouse[index]->cantidad -= cant;

                string nombreEmpleado;
                cout << "Introduzca su nombre para extraer el producto: ";
                cin >> nombreEmpleado;

                in_memory_warehouse[index]->empleado = nombreEmpleado;

                long codigoEstib;
                cout << "Introduzca su codigo de estiba: ";
                codigoEstib = validateInput_int(codigoEstib);

                in_memory_warehouse[index]->codigoEstiba = codigoEstib;
            }
        } else
            {
            if (cant > in_memory_warehouse[index]->cantidad)
            {
                cout << "Esa cantidad no esta disponible en el almacen\n";
            } else if (cant < in_memory_warehouse[index]->cantidad)
            {
                in_memory_warehouse[index]->cantidad -= cant;
            } else
                {
                counter--;

                for (int i = index; i < counter; i++)
                {
                    in_memory_warehouse[i] = in_memory_warehouse[i + 1];
                }
            }

        }

    }


    int find_index(string name)
    {
        for (int i = 0; i < counter; i++)
        {
            if (in_memory_warehouse[i]->nombre == name)
            {
                return i;
            }
        }
        return -1;
    }

    void list(ostream &salida, int flujo)
    {
        for (int i = 0; i < counter; i++)
        {
            in_memory_warehouse[i]->imprimir(salida, flujo);
        }
    }
};