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
class TextilesContainer{
public:
    int size_of_array = 4;
    int counter = 0;
    TextilesRegister **in_memory_warehouse;


    TextilesContainer()
    {
        in_memory_warehouse = new TextilesRegister *[size_of_array];
    }

    /*
     * Agregar nuevos objetos. Al llegar al tope se creara un array nuevo con el doble de tamaño, se copiara la informacion,
     * se borrara el array viejo y se renombrara el nuevo
     */
    void add(TextilesRegister *new_entry)
    {
        if (counter == size_of_array)
        {

            size_of_array *= 2;
            TextilesRegister **new_array = new TextilesRegister *[size_of_array];

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
    void extract(int index, int quantity) {
        if (quantity > in_memory_warehouse[index]->quantity)
        {
            cout << "Esa cantidad no esta disponible en el almacen\n";
        } else if (quantity < in_memory_warehouse[index]->quantity)
        {
            in_memory_warehouse[index]->quantity -= quantity;
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
            if (in_memory_warehouse[i]->name == name)
            {
                return i;
            }
        }
        return -1;
    }

    /*
     * Funcion hibrida. Lista o escribe en archivo dependiendo del flujo
     */
    void list(ostream &output, int stream)
    {
        for (int i = 0; i < counter; i++)
        {
            in_memory_warehouse[i]->print(output, stream);
        }
    }
};

class AppliancesContainer {
public:
    int size_of_array = 4;
    int counter = 0;
    ApplianceRegister **in_memory_warehouse;

    AppliancesContainer()
    {
        in_memory_warehouse = new ApplianceRegister *[size_of_array];
    }

    void add(ApplianceRegister *new_entry)
    {
        if (counter == size_of_array)
        {
            size_of_array *= 2;
            ApplianceRegister **new_array = new ApplianceRegister *[size_of_array];

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

    void extract(int index, int quantity)
    {
        if (quantity > in_memory_warehouse[index]->quantity) {
            cout << "Esa cantidad no esta disponible en el almacen\n";

        } else if (quantity < in_memory_warehouse[index]->quantity) {
            in_memory_warehouse[index]->quantity -= quantity;
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
            if (in_memory_warehouse[i]->name == name) {
                return i;
            }
        }
        return -1;
    }

    void list(ostream &output, int stream)
    {
        for (int i = 0; i < counter; i++) {
            in_memory_warehouse[i]->print(output, stream);
        }
    }

};

class FoodContainer {
public:
    int size_of_array = 4;
    int counter = 0;
    FoodRegister **in_memory_warehouse;

    FoodContainer()
    {
        in_memory_warehouse = new FoodRegister *[size_of_array];
    }

    void add(FoodRegister *new_entry)
    {
        if (counter == size_of_array)
        {
            size_of_array *= 2;
            FoodRegister **new_array = new FoodRegister *[size_of_array];

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
    void extract(int index, int quantity)
    {
        if (obtainDate() >= in_memory_warehouse[index]->entire_date())
        {
            cout << "Este producto ya esta vencido\n";

            if (quantity > in_memory_warehouse[index]->quantity)
            {
                cout << "Esa cantidad no esta disponible en el almacen\n";

            } else if (quantity <= in_memory_warehouse[index]->quantity)
            {
                in_memory_warehouse[index]->quantity -= quantity;

                string employee_name;
                cout << "Introduzca su nombre para extraer el producto: ";
                cin.ignore();
                getline(cin, employee_name);

                in_memory_warehouse[index]->employee = employee_name;

                long stowage_code;
                cout << "Introduzca su codigo de estiba: ";
                stowage_code = validateInput_int(stowage_code);

                in_memory_warehouse[index]->stowage_code = stowage_code;
            }
        } else
            {
            if (quantity > in_memory_warehouse[index]->quantity)
            {
                cout << "Esa cantidad no esta disponible en el almacen\n";
            } else if (quantity < in_memory_warehouse[index]->quantity)
            {
                in_memory_warehouse[index]->quantity -= quantity;
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
            if (in_memory_warehouse[i]->name == name)
            {
                return i;
            }
        }
        return -1;
    }

    void list(ostream &output, int stream)
    {
        for (int i = 0; i < counter; i++)
        {
            in_memory_warehouse[i]->print(output, stream);
        }
    }
};