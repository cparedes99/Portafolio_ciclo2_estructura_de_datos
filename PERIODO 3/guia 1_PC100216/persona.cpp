#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class persona {
private:
    string nombres;
    string apellidos;
    int anioNacimiento;
public:
    persona(string nombres, string apellidos, int anioNacimiento);
    string getNombreCompleto();
    int edad();
    
};

persona::persona(string nombres, string apellidos, int anioNacimiento){
    this ->nombres = nombres;
    this ->apellidos = apellidos;
    this ->anioNacimiento = anioNacimiento;
}

string persona::getNombreCompleto(){
    string getNombreCompleto = this ->nombres + " " + this ->apellidos;
    return getNombreCompleto;
}

persona::edad (){

    time_t now =time(0);
    tm* ltm = localtime(&now);

    int anioActual = 1900 + ltm->tm_year;

    int edad = (anioActual - this->anioNacimiento);
    return edad;
}

int main(){
    string nombres;
    string apellidos;
    int anioNacimiento;

    cout << "Por favor ingrese sus nombres: ";
    getline(cin, nombres);

    cout << "Por favor ingrese sus apellidos: ";
    getline(cin, apellidos);


    cout << "Por favor ingrese su anio de nacimiento: ";
    cin >> anioNacimiento;

    persona persona1(nombres, apellidos, anioNacimiento);
    cout << "------ Datos de la persona ----" << endl;
    cout << "Nombre : " << persona1.getNombreCompleto() << endl;
    cout << "Edad : " << persona1.edad() << endl;
    
    return 0; 
}
