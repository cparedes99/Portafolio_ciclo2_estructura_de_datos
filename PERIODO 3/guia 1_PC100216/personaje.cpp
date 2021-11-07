#include <iostream>
#include <string>

using namespace std;

class personaje
{
private:
    string nombre;
    int puntosVida;
public:
    personaje(string nombre, int puntosVida);

    void recibirGolpe(int puntosPerdidos){
       this ->puntosVida = this ->puntosVida - puntosPerdidos;
    }

    bool estaVivo(){
        if(this->puntosVida > 0){
            return true;
        }
        return false;
    }

    int getPuntosVida(){
        return this->puntosVida;
    }

    string getNombre(){
        return this->nombre;
    }

    void comer(int puntosGanados){
        if (this->estaVivo())
        {
            this->puntosVida = this->puntosVida + puntosGanados;
        }
    }
};

personaje::personaje(string nombre, int puntosVida){
    this ->nombre = nombre;
    this ->puntosVida = puntosVida;
}

int main(){
    string nom;
    string estado = "Muerto";
    int pv, accion;
    cout << "Ingrese el nombre del personaje " << endl;
    cin >> nom;
    cout << "Ingrese los puntos de vida " << endl;
    cin >> pv;
    personaje personaje1 = personaje(nom,pv);
    cout << "Personaje " << personaje1.getNombre() << endl;
    cout << "puntos vida " << personaje1.getPuntosVida() << endl;
    cout << "----------------------------------------------- " << endl;
    cout << "recibir golpe: " << endl;
    cin >> accion;
    personaje1.recibirGolpe(accion);
    cout << "puntos de vida restantes " << personaje1.getPuntosVida() << endl;
    cout << "recargar puntos : " << endl;
    cin >> accion;
    personaje1.comer(accion);
    cout << "puntos de vida restantes " << personaje1.getPuntosVida() << endl;
    if(personaje1.estaVivo()){
        estado = "Vivo";
    }
    cout << "Estado del personaje: " << estado << endl;
    return 0;
}
