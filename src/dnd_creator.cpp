#include <iostream>
#include <string>
#include <cstdlib> // Para usar rand()
#include <limits>  // Para limpiar la entrada inválida

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
        case Ninguna: return "Sin clase";
    }
    return "Desconocida";
}

void mostrarMenuClases() {
    cout << "=== Seleccion de Clase ===" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << i << ". " << claseToString(static_cast<Clase>(i - 1)) << endl;
    }
    cout << "Selecciona una clase (1-12): ";
}

Clase seleccionarClase() {
    int opcion;
    do {
        mostrarMenuClases();
        cin >> opcion;
        if (cin.fail() || opcion < 1 || opcion > 12) {
            cout << "Opcion no valida. Intenta de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return static_cast<Clase>(opcion - 1);
        }
    } while (true);
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

int pedirAtributo(const string& nombreAtributo) {
    int valor;
    do {
        cout << "Introduce el nivel de " << nombreAtributo << " (0-20): ";
        cin >> valor;
        if (cin.fail() || valor < 0 || valor > 20) {
            cout << "Valor invalido. Intenta de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return valor;
        }
    } while (true);
}

void asignarAtributosManual(Personaje& p) {
    p.fuerza = pedirAtributo("fuerza");
    p.destreza = pedirAtributo("destreza");
    p.inteligencia = pedirAtributo("inteligencia");
    p.constitucion = pedirAtributo("constitucion");
    p.sabiduria = pedirAtributo("sabiduria");
    p.carisma = pedirAtributo("carisma");
    cout << "Atributos asignados con exito." << endl;
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
    cout << "\n=== Detalles del Personaje ===" << endl;
    cout << "Nombre: " << (p.nombre.empty() ? "No asignado" : p.nombre) << endl;
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                asignarAtributosManual(personaje);
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
                cout << "Opcion no valida. Intenta de nuevo." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 6);

    return 0;
}
