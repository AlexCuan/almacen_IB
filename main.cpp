#include "Menu.h"
#include "iostream"
#include <cstdlib>
#include "fstream"
#include <ncurses.h>

using namespace std;

int main() {
    load_info();
    main_menu();

    return 0;
}