#include "lista_generica.hpp"
#include <string>

template <typename TIPODATO>
class Pila : private Lista<TIPODATO>{
public:
    // constructor
    Pila();
    // Agregar  un elemento en la parte superior
    push(TIPODATO item);
    // Remover un elemento de la parte superior 
    TIPODATO pop();
    bool estaPilaVacia();
    string pilaComoCadena();
};

template<typename TIPODATO>
Pila<TIPODATO>::Pila(){
    Lista<TIPODATO> Lista;
}

template<typename TIPODATO>
Pila<TIPODATO>::push(TIPODATO item){
    this->adjuntar(item);
}

template<typename TIPODATO>
TIPODATO Pila<TIPODATO>::pop(){
    return this->remover(this->tamano() - 1);
}

template<typename TIPODATO>
bool Pila<TIPODATO>::estaPilaVacia(){
    return this->estaVacia();
}

template<typename TIPODATO>
string Pila<TIPODATO>::pilaComoCadena(){
    return this->comoCadena();
}
