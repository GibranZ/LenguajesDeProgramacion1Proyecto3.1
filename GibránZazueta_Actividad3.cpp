#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre, apellidoPaterno, apellidoMaterno, rfc;    
    int dia, mes, anio;
    
    // Solicitar los datos al usuario
    cout << "Introduce tu nombre: ";
    getline(cin, nombre);
    
    cout << "Introduce tu apellido paterno: ";
    getline(cin, apellidoPaterno);
    
    cout << "Introduce tu apellido materno: ";
    getline(cin, apellidoMaterno);
    
    cout<<"Introduce tu fecha de nacimiento (DD/MM/AAAA): ";
    
    scanf("%d/%d/%d", &dia, &mes, &anio);
    
    // Calcular el RFC
    string rfc_paterno = apellidoPaterno.substr(0,1) + apellidoPaterno.substr(apellidoPaterno.find_first_of("AEIOU",1),1);
    string rfc_materno = apellidoMaterno.empty() ? "X" : apellidoMaterno.substr(0,1);
    
    string rfc_nombre = nombre.substr(0,1) == "Ñ" ? "X" : nombre.substr(0,1);
    
    string rfc_fecha = to_string(anio).substr(2,2) + (mes < 10 ? "0" + to_string(mes) : to_string(mes)) + (dia < 10 ? "0" + to_string(dia) : to_string(dia));
    
    rfc = rfc_paterno + rfc_materno + rfc_nombre + rfc_fecha;
    
    // Imprimir el resultado
    
    cout << "Tu RFC sin homoclave es: " << rfc << endl;
    
    return 0;
}