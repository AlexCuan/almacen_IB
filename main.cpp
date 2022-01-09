#include "Menu.h"
#include "iostream"
#include <cstdlib>
#include "fstream"
#include <ncurses.h>

using namespace std;

int main() {
    load_info();
    //cout << textiles_departament.in_memory_warehouse[0]->nombre;
   // add_dummies();
   food_department.in_memory_warehouse[1]->imprimir(cout, COUT);
    main_menu();

    return 0;
}