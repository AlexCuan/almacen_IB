//g++ getDate.cpp -o getDate
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;

string getDate() {
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    stringstream ss_year;
    ss_year << timePtr->tm_year + 1900;
    string Year = ss_year.str();

    stringstream ss_month;
    ss_month << timePtr->tm_mon + 1;
    string Month = ss_month.str();
    if (atoi(Month.c_str()) < 10)
        Month = "0" + Month;

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string Day = ss_day.str();
    if (atoi(Day.c_str()) < 10)
        Day = "0" + Day;

    stringstream ss_hour;
    ss_hour << timePtr->tm_hour;
    string Hour = ss_hour.str();
    if (atoi(Hour.c_str()) < 10)
        Hour = "0" + Hour;

    stringstream ss_min;
    ss_min << timePtr->tm_min;
    string Min = ss_min.str();
    if (atoi(Min.c_str()) < 10)
        Min = "0" + Min;

    stringstream ss_sec;
    ss_sec << timePtr->tm_sec;
    string Sec = ss_sec.str();
    if (atoi(Sec.c_str()) < 10)
        Sec = "0" + Sec;

    string Fecha = Year + Month + Day;//+"_"+Hour+Min+Sec;

    return Fecha;
}

int obtainDate() {
    int date;
    string fecha = getDate();
    date = atoi(fecha.c_str());
    return date;

}


template<typename T>
T &validateInput_int(T &val) {
    while (true) {

        if (cin >> val && val > 0) {
            break;
        } else {
            cout << "Enter a valid integer value!\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return val;
}


string str_to_lower(string used_str) {

    for (int i = 0; i < used_str.length(); i++) {
        used_str[i] = tolower(used_str[i]);
    }
    return used_str;
}

// hacer una funcion para contraer y otra para extender

string contract(string used_str) {
    for (int i = 0; i < used_str.size(); i++) {
        if (used_str[i] == 32)
            used_str[i] = 36;
    }
    return used_str;
}

string extend(string used_str) {
    for (int i = 0; i < used_str.size(); i++) {
        if (used_str[i] == 36)
            used_str[i] = 32;
    }
    return used_str;
}


void clean_console() {
    system("clear");
}

bool stringDigit(string used_str) {
    bool digit = true;
    for (int i = 0; i < used_str.size(); i++) {
        if (!(isdigit(used_str[i]))) {
            digit = false;
            break;
        }
    }
    return digit;
}


string visoi(string used_str) {
    while (true) {
        if (cin >> used_str && stringDigit(used_str))
            break;
        else {
            cout << "Introduzca un numero entero valido: ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        }
    }
    return used_str;
}

void pause() {
    cout << "Presione enter para continuar ...";
    getchar();
}