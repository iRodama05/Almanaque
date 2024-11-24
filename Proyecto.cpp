#include <iostream>
#include <vector> // Para usar listas (vectores)
#include <string>

using namespace std;

// Clase base abstracta para todas las plantas
class Planta {
protected:
    string nombre; // Nombre de la planta
    int vida;      // Puntos de vida
    int coste;     // Coste de la planta

public:
    Planta(string _nombre, int _vida, int _coste) 
        : nombre(_nombre), vida(_vida), coste(_coste) {}

    virtual void mostrar_info() = 0; // Método virtual puro

    virtual ~Planta() {} // Destructor virtual
};

// Clase para plantas ofensivas
class PlantaOfensiva : public Planta {
private:
    int ataque; // Puntos de ataque

public:
    PlantaOfensiva(string _nombre, int _vida, int _coste, int _ataque)
        : Planta(_nombre, _vida, _coste), ataque(_ataque) {}

    void mostrar_info() override {
        cout << "\nPlanta Ofensiva: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Coste: " << coste << endl;
        cout << "Ataque: " << ataque << endl;
    }
};

// Clase para plantas defensivas
class PlantaDefensiva : public Planta {
private:
    string funcion; // Función de la planta

public:
    PlantaDefensiva(string _nombre, int _vida, int _coste, string _funcion)
        : Planta(_nombre, _vida, _coste), funcion(_funcion) {}

    void mostrar_info() override {
        cout << "\nPlanta Defensiva: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Coste: " << coste << endl;
        cout << "Función: " << funcion << endl;
    }
};

// Clase para plantas especiales
class PlantaEspecial : public Planta {
private:
    string modifica_a;
    string efecto;

public:
    PlantaEspecial(string _nombre, int _coste, string _modifica_a, string _efecto)
        : Planta(_nombre, 0, _coste), modifica_a(_modifica_a), efecto(_efecto) {}

    void mostrar_info() override {
        cout << "\nPlanta Especial: " << nombre << endl;
        cout << "Coste: " << coste << endl;
        cout << "Modifica a: " << modifica_a << endl;
        cout << "Efecto: " << efecto << endl;
    }
};

// Clase para zombies
class Zombie {
private:
    string nombre;
    int vida;
    int ataque;

public:
    Zombie(string _nombre, int _vida, int _ataque) 
        : nombre(_nombre), vida(_vida), ataque(_ataque) {}

    void mostrar_info() {
        cout << "\nNombre: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
    }
};

// Clase para el almanaque
class Almanaque {
private:
    vector<Planta*> plantas;
    vector<Zombie*> zombis;

public:
    void agregar_planta(Planta* planta) {
        plantas.push_back(planta);
    }

    void agregar_zombie(Zombie* zombie) {
        zombis.push_back(zombie);
    }

    void mostrar_plantas(int categoria) {
        for (auto& planta : plantas) {
            if (categoria == 1 && dynamic_cast<PlantaOfensiva*>(planta)) {
                planta->mostrar_info();
            } else if (categoria == 2 && dynamic_cast<PlantaDefensiva*>(planta)) {
                planta->mostrar_info();
            } else if (categoria == 3 && dynamic_cast<PlantaEspecial*>(planta)) {
                planta->mostrar_info();
            }
        }
    }

    void mostrar_zombis() {
        for (auto& zombie : zombis) {
            zombie->mostrar_info();
        }
    }

    ~Almanaque() {
        for (auto& planta : plantas) delete planta;
        for (auto& zombie : zombis) delete zombie;
    }
};

void mostrar_menu(Almanaque& almanaque) {
    int opcion_principal;
    do {
        cout << "\n===== Almanaque =====" << endl;
        cout << "1. Ver Plantas" << endl;
        cout << "2. Ver Zombis" << endl;
        cout << "3. Agregar Elemento" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion_principal;

        switch (opcion_principal) {
        case 1: {
            int opcion_plantas;
            do {
                cout << "\n=== Menú de Plantas ===" << endl;
                cout << "1. Ofensivas" << endl;
                cout << "2. Defensivas" << endl;
                cout << "3. Especiales" << endl;
                cout << "4. Volver" << endl;
                cout << "Seleccione una opción: ";
                cin >> opcion_plantas;

                if (opcion_plantas >= 1 && opcion_plantas <= 3) {
                    almanaque.mostrar_plantas(opcion_plantas);
                }
            } while (opcion_plantas != 4);
            break;
        }
        case 2:
            almanaque.mostrar_zombis();
            break;
        case 3: {
            int tipo;
            cout << "\n1. Agregar Planta\n2. Agregar Zombie\nSeleccione una opción: ";
            cin >> tipo;

            if (tipo == 1) {
                int subtipo, vida, coste, ataque;
                string nombre, funcion, modifica_a, efecto;
                cout << "\nSeleccione tipo de planta (1. Ofensiva, 2. Defensiva, 3. Especial): ";
                cin >> subtipo;
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);

                if (subtipo == 1) {
                    cout << "Vida: ";
                    cin >> vida;
                    cout << "Coste: ";
                    cin >> coste;
                    cout << "Ataque: ";
                    cin >> ataque;
                    almanaque.agregar_planta(new PlantaOfensiva(nombre, vida, coste, ataque));
                } else if (subtipo == 2) {
                    cout << "Vida: ";
                    cin >> vida;
                    cout << "Coste: ";
                    cin >> coste;
                    cout << "Función: ";
                    cin.ignore();
                    getline(cin, funcion);
                    almanaque.agregar_planta(new PlantaDefensiva(nombre, vida, coste, funcion));
                } else if (subtipo == 3) {
                    cout << "Coste: ";
                    cin >> coste;
                    cout << "Modifica a: ";
                    cin.ignore();
                    getline(cin, modifica_a);
                    cout << "Efecto: ";
                    getline(cin, efecto);
                    almanaque.agregar_planta(new PlantaEspecial(nombre, coste, modifica_a, efecto));
                }
            } else if (tipo == 2) {
                string nombre;
                int vida, ataque;
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Vida: ";
                cin >> vida;
                cout << "Ataque: ";
                cin >> ataque;
                almanaque.agregar_zombie(new Zombie(nombre, vida, ataque));
            }
            break;
        }
        case 4:
            cout << "Saliendo del Almanaque..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion_principal != 4);
}

int main() {
    Almanaque almanaque;

  // Agregar plantas ofensivas
    almanaque.agregar_planta(new PlantaOfensiva("Lanzaguisantes", 300, 100, 20));
    almanaque.agregar_planta(new PlantaOfensiva("Repetidora", 300, 200, 20));
    almanaque.agregar_planta(new PlantaOfensiva("Melonpulta", 300, 300, 70));
    almanaque.agregar_planta(new PlantaOfensiva("Pinchohierva", 1, 100, 20));
    almanaque.agregar_planta(new PlantaOfensiva("Petaseta", 1, 125, 1000));

    // Agregar plantas defensivas
    almanaque.agregar_planta(new PlantaDefensiva("Girasol", 300, 50, "Produce soles"));
    almanaque.agregar_planta(new PlantaDefensiva("Nuez", 4000, 50, "Resiste los ataques"));
    almanaque.agregar_planta(new PlantaDefensiva("Magnetoseta", 300, 100, "Atrae objetos metálicos"));
    almanaque.agregar_planta(new PlantaDefensiva("Maceta", 300, 25, "Te permite plantar en el tejado"));
    almanaque.agregar_planta(new PlantaDefensiva("Nenúfar", 300, 25, "Te permite plantar en el agua"));
    
    // Agregar plantas especiales
    almanaque.agregar_planta(new PlantaEspecial("Guisantralladora", 250, "Repetidora", "Duplica el número de disparos"));
    almanaque.agregar_planta(new PlantaEspecial("Birasol", 150, "Girasol", "Duplica el número de soles producidos"));
    almanaque.agregar_planta(new PlantaEspecial("Melonpulta Congelada", 200, "Melonpulta", "Los ataques ahora realentizan"));
    almanaque.agregar_planta(new PlantaEspecial("Pinchorroca", 125, "Pinchohierva", "Aumenta el ataque y soporta 2 golpes más"));
    almanaque.agregar_planta(new PlantaEspecial("Magnetoseta Dorada", 50, "Magnetoseta", "Ahora atrae el dinero en vez de los objetos metálicos"));
    almanaque.agregar_planta(new PlantaEspecial("Imitadora", 0, "N/A", "Planta una copia de una planta por el mimso precio"));

    // Agregar zombies
    almanaque.agregar_zombie(new Zombie("Zombie Básico", 200, 75));
    almanaque.agregar_zombie(new Zombie("Zombie Cono", 350, 50));
    almanaque.agregar_zombie(new Zombie("Zombie Cubo", 500, 50));
    almanaque.agregar_zombie(new Zombie("Zombie Futbolista", 1000, 75));
    almanaque.agregar_zombie(new Zombie("Zombiestein", 2000, 9999));
    almanaque.agregar_zombie(new Zombie("Dr. Zomboss", 50000, 9999));

    mostrar_menu(almanaque);
    return 0;
}
