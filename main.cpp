#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void crearArchivoNuevo(){
    string nombreArchivo,opcion;
    cout<<"Ingrese el nombre del archivo nuevo: ";
    cin>>nombreArchivo;
    ofstream archivo(nombreArchivo,ios::trunc);
    if(archivo.is_open()) {
        cout << "Archivo " << nombreArchivo << " creado exitosamente." << endl;
        cout<<"¿¿desea agregar información a su nuevo archivo?? S/N"<<endl;
        cin >>opcion;
        if (opcion=="S") {
            string texto;
            cout << "Ingrese el texto a agregar al archivo" << nombreArchivo << "." << endl;
            cin.ignore();
            getline(cin, texto);
            archivo << texto << endl;
            cout << "Texto agregado correctamente al archivo" << nombreArchivo << "." << endl;
            archivo.close();
        }else {
            cout<<"proceso finalizado"<<endl;
        }
        archivo.close();

    }else{
        cout<<"No se pudo crear un archivo"<<nombreArchivo<<"."<<endl;
    }
}
void modificarArchivoExistente() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo que desea modificar: ";
    cin >> nombreArchivo;
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        string texto;
        cout << "Ingrese el texto a agregar al archivo" << nombreArchivo << "." << endl;
        cin.ignore();
        getline(cin, texto);
        archivo << texto << endl;
        cout << "Texto agregado correctamente al archivo" << nombreArchivo << "." << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << nombreArchivo << "." << endl;
    }
}
int main() {
    char opcion;
    cout << "¿Desea crear un archivo nuevo (N) o modificar uno existente (M)? ";
    cin >> opcion;

    switch (toupper(opcion)) {
        case 'N':
            crearArchivoNuevo();
            break;
        case 'M':
            modificarArchivoExistente();
            break;
        default:
            cout << "Opción inválida. Por favor, seleccione 'N' o 'M'." << endl;
            break;
    }

    return 0;
}