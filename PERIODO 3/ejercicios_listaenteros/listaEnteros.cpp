#include "lista.h"
#include <iostream>

using namespace std;

int main(){
	ListaEnteros lintl(10);
	
	lintl.adjuntar(12);
	lintl.adjuntar(7);
	lintl.adjuntar(19);
	lintl.imprimirLista();
	
	lintl.adjuntar(30);
	lintl.imprimirLista();
	
	lintl.insertar(1,41);
	lintl.imprimirLista();
	
	lintl.remover(2);
	lintl.imprimirLista();
	
	return 0;
	
	
	
}
