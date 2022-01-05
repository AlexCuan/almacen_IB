//g++ getDate.cpp -o getDate
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <vector>
using namespace std;

string getDate()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    stringstream ss_year;
    ss_year << timePtr->tm_year+1900;
    string Year = ss_year.str();

    stringstream ss_month;
    ss_month << timePtr->tm_mon+1;
    string Month = ss_month.str();
    if(atoi(Month.c_str()) < 10)
        Month = "0"+Month;

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string Day = ss_day.str();
    if(atoi(Day.c_str()) < 10)
        Day = "0"+Day;

    stringstream ss_hour;
    ss_hour << timePtr->tm_hour;
    string Hour = ss_hour.str();
    if(atoi(Hour.c_str()) < 10)
        Hour = "0"+Hour;

    stringstream ss_min;
    ss_min << timePtr->tm_min;
    string Min = ss_min.str();
    if(atoi(Min.c_str()) < 10)
        Min = "0"+Min;

    stringstream ss_sec;
    ss_sec << timePtr->tm_sec;
    string Sec = ss_sec.str();
    if(atoi(Sec.c_str()) < 10)
        Sec = "0"+Sec;

    string Fecha = Year+Month+Day;//+"_"+Hour+Min+Sec;

    return Fecha;
}

int obtainDate(){
    int date;
    string fecha = getDate();
    date = atoi(fecha.c_str());
    return date;

}




/*using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;*/

template<typename T>
T &validateInput_int(T &val)
{
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


string minusculas(string cadena){

    for(int i = 0; i < cadena.length(); i++){
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}
// hacer una funcion para contraer y otra para extender

string contraer(string cadena){
    for(int i = 0; i < cadena.size(); i++){
        if(cadena[i] == 32)
            cadena[i] = 36;
    }return cadena;
}
string extender(string cadena){
    for(int i = 0; i < cadena.size(); i++){
        if(cadena[i] == 36)
            cadena[i] = 32;
    }
    return cadena;
}

void pause() {
    char a;
    cin>>a;
}
