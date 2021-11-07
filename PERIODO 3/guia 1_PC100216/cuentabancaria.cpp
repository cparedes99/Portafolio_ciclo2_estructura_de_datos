#include <iostream>
#include <string>


using namespace std;

class cuentaBancaria {
    private:
    string numeroCuenta;
    string nombreTitular;
    double saldo;
public:
    cuentaBancaria(string num, string titular, double saldo);
    double getSaldo();
    string getNumeroCuenta();
    string getNombreTitular();
    void depositar(double importeDeposito);
    void retirar(double importeRetiro);
};

cuentaBancaria::cuentaBancaria(string num,
    string titular, double saldo){
        if (saldo <0){
            this ->saldo = 0.00;
        } else {
            this ->saldo = saldo;
        }
        this ->numeroCuenta = num;
        this ->nombreTitular = titular;
    }

double cuentaBancaria::getSaldo(){
        return this ->saldo;
}
string cuentaBancaria::getNumeroCuenta(){
        return this->numeroCuenta;
}
string cuentaBancaria::getNombreTitular(){
        return this->nombreTitular;
}
void cuentaBancaria::depositar(double importeDeposito){
    if (importeDeposito > 0){
        this ->saldo += importeDeposito;
    }else {
    cout << "! - importe no valido " << endl;    
    }    
}
void cuentaBancaria::retirar(double importeRetiro){
    if (importeRetiro > 0 && importeRetiro <= this ->saldo){
        this->saldo -= importeRetiro;
    } else {
    cout << "! - importe no valido " << endl;
    }
}
using namespace std;

int main(){
    // crear una cuenta bancaria
    cuentaBancaria miCuenta("A-48063", "Cristian Paredes", 2900.00);
    cout << "Titular: " << miCuenta.getNombreTitular() << endl;
    cout << "# Cuenta: " << miCuenta.getNumeroCuenta() << endl;
    cout << "Saldo: $" << miCuenta.getSaldo() << endl;
    cout << " ------------------------------------ " << endl;
    
    // creando otra cuenta
    cuentaBancaria cuentaAmigo("C-165687", "Lionel Messi", 784661.00);
    cout << "Titular: " << cuentaAmigo.getNombreTitular() << endl;
    cout << "# Cuenta: " << cuentaAmigo.getNumeroCuenta() << endl;
    cout << "Saldo: $" << cuentaAmigo.getSaldo() << endl;
    cout << " ------------------------------------ " << endl;
    
    // creando otra cuenta
    cuentaBancaria cuentaNoValida("A-36325", "Lebron James", -500.00);
    cout << "Titular: " << cuentaNoValida.getNombreTitular() << endl;
    cout << "# Cuenta: " << cuentaNoValida.getNumeroCuenta() << endl;
    cout << "Saldo: $" << cuentaNoValida.getSaldo() << endl;
    cout << " ------------------------------------ " << endl;

    // hacer un retiro de la cuenta bancaria 
    cout << "Quiero retirar $25 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
    cout << "Saldo inicial: $" << miCuenta.getSaldo() << endl;
    miCuenta.retirar(25);
    cout << "Saldo de la operacion; $" << miCuenta.getSaldo() << endl;
    cout << " ------------------------------ " << endl;

    // hacer un retiro de la cuenta micuenta mayor al saldo disponible
    cout << "Quiero retirar $2000 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
    cout << "Saldo inicial: $" << miCuenta.getSaldo() << endl;
    miCuenta.retirar(2000);
    cout << "Saldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
    cout << " -------------------------------------" << endl;

    // hacer un retiro de un monto negativo
    cout << "Quiero retirar -$500 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
    cout << "Saldo inicial: $" << miCuenta.getSaldo() << endl;
    miCuenta.retirar(-500);
    cout << "Saldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
    cout << " -------------------------------------" << endl;

    // hacer un retiro de la cuenta micuenta
    cout << "Quiero depositar $125 a la cuenta " << miCuenta.getNumeroCuenta() << endl;
    cout << "Saldo inicial: $" << miCuenta.getSaldo() << endl;
    miCuenta.retirar(125);
    cout << "Saldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
    cout << " -------------------------------------" << endl;

    // hacer un retiro de la cuneta micuenta
    cout << "Quiero retirar -$3000 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
    cout << "Saldo inicial: $" << miCuenta.getSaldo() << endl;
    miCuenta.retirar(-3000);
    cout << "Saldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
    cout << " -------------------------------------" << endl;

    return 0;
}

