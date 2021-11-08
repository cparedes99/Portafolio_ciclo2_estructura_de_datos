#ifndef lista_generica_hpp
#define lista_generica_hpp

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

template <typename TIPODATO>
class Lista{
	
	private:
		int cuenta;
		int capacidad;
		TIPODATO *items;
		void agrandar();
	public:
		Lista(int capacidad);
		Lista();
		~Lista();
		Lista(const Lista &otra);
		bool estaVacia();
		int tamano();
		void insertar(int indice, TIPODATO item);
		void adjuntar(TIPODATO item);
		TIPODATO obtener(int indice);
		bool contiene (TIPODATO item);
		TIPODATO remover(int indice);
		string comoCadena();
};


template <typename TIPODATO>
Lista<TIPODATO>::Lista(int capacidad){
	this->cuenta = 0;
	this->capacidad = capacidad;
	this->items = new TIPODATO[capacidad];	
}


template <typename TIPODATO>
Lista<TIPODATO>::Lista() : Lista(4){}



template <typename TIPODATO>
Lista<TIPODATO>::~Lista(){
	delete[] items;
}


template <typename TIPODATO>
Lista<TIPODATO>::Lista(const Lista<TIPODATO> &otra){
	this->cuenta = otra.cuenta;
	this->capacidad = otra.capacidad;
	this->items = new TIPODATO[capacidad];
	for (int i = 0; i <this->cuenta; i++)
	this->items[i] = otra.items[i];	
}	


template <typename TIPODATO>
bool Lista<TIPODATO>::estaVacia(){
	return this->cuenta == 0;
}


template <typename TIPODATO>
int Lista<TIPODATO>::tamano(){
	return this->cuenta;
}



template <typename TIPODATO>
void Lista<TIPODATO>::agrandar(){

	TIPODATO *temp = this->items;
	this->capacidad *=2;
	this->items = new TIPODATO[capacidad];
	for (int i=0; i<cuenta; i++)
	this->items[i] = temp[i];
	delete [] temp;

}


template <typename TIPODATO>
void Lista<TIPODATO>::insertar (int indice,TIPODATO item){
	
	if (indice <0 || indice >this->cuenta) throw "indice fuera de rango";
	

	if (this->cuenta >=this->capacidad) this->agrandar();
	

	for (int i = cuenta - 1; i>=indice; i--){
		cout << "desplazando elemento " << items [i] << "del indice";
		cout <<i<< "al indice" << (i+1) << endl;
		this->items[i+1] = this->items[i];
	}
	

	this->items[indice] = item;
	

	this->cuenta++;
}


template <typename TIPODATO>
void Lista<TIPODATO>::adjuntar(TIPODATO item){
	this->insertar(this->cuenta, item);
}


template <typename TIPODATO>
TIPODATO Lista<TIPODATO>::obtener(int indice){
	
	if (indice < 0 || indice >= this->cuenta) throw "indice fuera de rango";
	if (this->estaVacia()) throw "No se puede recuperar elementos de una lista vacia";
	

	return this->items[indice];
	}


template <typename TIPODATO>
bool Lista <TIPODATO>::contiene(TIPODATO item){
	for (int i =0; i <this->cuenta; i++){

		if (this->items[i] == item)
		return true;
	}
	
	return false;
}


template <typename TIPODATO>
TIPODATO Lista<TIPODATO>::remover(int indice){

	if (this->estaVacia()) throw "no se puede remover elementos de una lista vacia";
	if (indice < 0 ||indice >=this->cuenta) throw "indice fuera de rango";
	

	TIPODATO valor = this->items[indice];
	for (int i = indice; i <cuenta -1;i++){

		this->items[i] = this->items[i+1];
	}
	

	this->cuenta--;
	return valor;
}

template <typename TIPODATO>
string Lista<TIPODATO>::comoCadena(){
	ostringstream s;
	s<< "[";
	for (int i =0; i<(this->cuenta);i++){
		s << this->items[i];
		if (i < this->cuenta-1)
		s <<", ";
	}
	s << "]";
	return s.str();
}
	
#endif 
