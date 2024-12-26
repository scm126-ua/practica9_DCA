#include <iostream>
#include <string>
#include <cstdlib> // Para usar rand()

using namespace std;

enum Clase {
    Barbaro,
    Guerrero,
    Bardo,
    Druida,
    Brujo,
    Mago,
    Hechicero,
    Picaro,
    Explorador,
    Clerigo,
    Monje,
    Paladin,
    Artificiero,
    Ninguna // Para cuando no se haya asignado aún.
};

struct Personaje {
    string nombre;
    Clase clase = Ninguna;
    int fuerza = 0, destreza = 0, inteligencia = 0, constitucion = 0, sabiduria = 0, carisma = 0;
};

string claseToString(Clase c) {
    switch (c) {
        case Barbaro: return "Barbaro";
        case Guerrero: return "Guerrero";
        case Bardo: return "Bardo";
        case Druida: return "Druida";
        case Brujo: return "Brujo";
        case Mago: return "Mago";
        case Hechicero: return "Hechicero";
        case Picaro: return "Picaro";
        case Explorador: return "Explorador";
        case Clerigo: return "Clerigo";
        case Monje: return "Monje";
        case Paladin: return "Paladin";
        case Artificiero: return "Artificiero";
        case Ninguna: return "Sin clase";
    }
    return "Desconocida";
}

void mostrarMenuClases() {
    cout << "=== Seleccion de Clase ===" << endl;
    cout << "1. Barbaro" << endl;
    cout << "2. Guerrero" << endl;
    cout << "3. Bardo" << endl;
    cout << "4. Druida" << endl;
    cout << "5. Brujo" << endl;
    cout << "6. Mago" << endl;
    cout << "7. Hechicero" << endl;
    cout << "8. Picaro" << endl;
    cout << "9. Explorador" << endl;
    cout << "10. Clerigo" << endl;
    cout << "11. Monje" << endl;
    cout << "12. Paladin" << endl;
    cout << "13. Artificiero" << endl;
    cout << "Selecciona una clase (1-13): ";
}

Clase seleccionarClase() {
    int opcion;
    mostrarMenuClases();
    cin >> opcion;
    switch (opcion) {
        case 1: return Barbaro;
        case 2: return Guerrero;
        case 3: return Bardo;
        case 4: return Druida;
        case 5: return Brujo;
        case 6: return Mago;
        case 7: return Hechicero;
        case 8: return Picaro;
        case 9: return Explorador;
        case 10: return Clerigo;
        case 11: return Monje;
        case 12: return Paladin;
        case 13: return Artificiero;
        default:
            cout << "Opcion no valida. Se asignara 'Sin clase'." << endl;
            return Ninguna;
    }
}

void mostrarMenu() {
    cout << "=== Creador de Personajes de D&D ===" << endl;
    cout << "1. Asignar nombre al personaje" << endl;
    cout << "2. Asignar clase del personaje" << endl;
    cout << "3. Asignar atributos manualmente" << endl;
    cout << "4. Asignar atributos aleatorios (tirar dados)" << endl;
    cout << "5. Mostrar detalles del personaje" << endl;
    cout << "6. Salir" << endl;
    cout << "Selecciona una opcion: ";
}

int tirarDado() {
    return rand() % 20 + 1;
}

void asignarAtributosAleatorios(Personaje& p) {
    p.fuerza = tirarDado();
    p.destreza = tirarDado();
    p.inteligencia = tirarDado();
    p.constitucion = tirarDado();
    p.sabiduria = tirarDado();
    p.carisma = tirarDado();
    cout << "Atributos asignados aleatoriamente." << endl;
}

void mostrarDetalles(const Personaje& p) {
    cout << "=== Detalles del Personaje ===" << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Clase: " << claseToString(p.clase) << endl;
    cout << "Fuerza: " << p.fuerza << endl;
    cout << "Destreza: " << p.destreza << endl;
    cout << "Inteligencia: " << p.inteligencia << endl;
    cout << "Constitucion: " << p.constitucion << endl;
    cout << "Sabiduria: " << p.sabiduria << endl;
    cout << "Carisma: " << p.carisma << endl;
}

int main() {
    Personaje personaje;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Introduce el nombre del personaje: ";
                getline(cin, personaje.nombre);
                cout << "Nombre asignado con exito." << endl;
                break;
            case 2:
                personaje.clase = seleccionarClase();
                cout << "Clase asignada con exito." << endl;
                break;
            case 3:
                cout << "Introduce el nivel de fuerza (0-20): ";
                cin >> personaje.fuerza;
                cout << "Introduce el nivel de destreza (0-20): ";
                cin >> personaje.destreza;
                cout << "Introduce el nivel de inteligencia (0-20): ";
                cin >> personaje.inteligencia;
                cout << "Introduce el nivel de constitucion (0-20): ";
                cin >> personaje.constitucion;
                cout << "Introduce el nivel de sabiduria (0-20): ";
                cin >> personaje.sabiduria;
                cout << "Introduce el nivel de carisma (0-20): ";
                cin >> personaje.carisma;
                cout << "Atributos asignados con exito." << endl;
                break;
            case 4:
                asignarAtributosAleatorios(personaje);
                break;
            case 5:
                mostrarDetalles(personaje);
                break;
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 6);

    return 0;
}
