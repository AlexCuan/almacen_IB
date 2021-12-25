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
            cout << "Extending array..." << endl;

            size_of_array *= 2;
            RegistroTextiles** new_array = new RegistroTextiles*[size_of_array];

            for(int i = 0; i < size_of_array/2; i++)
            {
                new_array[i] = in_memory_warehouse[i];
            }

            delete [] in_memory_warehouse;
            in_memory_warehouse = new_array;
        }
        else
        {
            cout << "Added without extending." << endl;
        }

        in_memory_warehouse[counter] = new_entry;
        counter++;
    }
};

class ContainerElectrodomesticos {
public:
    int size_of_array;
    int counter;
    RegistroElectrodomesticos **in_memory_warehouse;

    ContainerElectrodomesticos(int size_of_array, int counter) {
        this->size_of_array = size_of_array;
        this->counter = counter;
        in_memory_warehouse = new RegistroElectrodomesticos*[size_of_array];
    }

};

class ContainerAlimentos {
public:
    int size_of_array;
    int counter;
    RegistroAlimentos **in_memory_warehouse;

    ContainerAlimentos(int size_of_array, int counter) {
        this->size_of_array = size_of_array;
        this->counter = counter;
        in_memory_warehouse = new RegistroAlimentos*[size_of_array];
    }

};