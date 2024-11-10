#include <iostream>
using namespace std;

class Planta {
    private:

        string nombre;
        int vida;
        int ataque;
        int coste;

    public:

        Planta(string _nom, int _vida, int _ataque, int _coste) {
            nombre = _nom;
            vida = _vida;
            ataque = _ataque;
            coste = _coste;
        }
    
    void mostrar_info() {
        cout << "Nombre: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Coste: " << coste << endl;
    }
};

class Zombie {
    private:

        string nombre;
        int vida;
        int ataque;

    public:

        Zombie(string _nom, int _vida, int _ataque) {
            nombre = _nom;
            vida = _vida;
            ataque = _ataque;
    }

    void mostrar_info() {
        cout << "Nombre: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
    }
};

class Especial {
    private:

        string nombre;
        string potenciando;
        int coste;
        string accion;  

    public:

        Especial(string _nom, string _potenciando, int _coste, string _accion) {
            nombre = _nom;
            potenciando = _potenciando;
            coste = _coste;
            accion = _accion;
        }

    void mostrar_info() {
        cout << "Nombre: " << nombre << endl;
        cout << "Potenciando: " << potenciando << endl;
        cout << "Coste: " << coste << endl;
        cout << "Acción: " << accion << endl;
    }
};

int main() {

    // Creación de Plantas
    Planta lanzaguisantes("Lanzaguisantes", 300, 20, 100);

    // Creación de Zombies
    Zombie basico("Zombie básico", 200, 75);

    // Creación de especiales
    Especial guisantralladora("Guisantralladora", "Repetidora", 250, "Duplica los guisantes disparados.");

    // Mostrar información de cada objeto creado
    cout << "=== Información de Planta ===" << endl;
    lanzaguisantes.mostrar_info();
    cout << endl;

    cout << "=== Información de Zombie ===" << endl;
    basico.mostrar_info();
    cout << endl;

    cout << "=== Información de Especial ===" << endl;
    guisantralladora.mostrar_info();
    cout << endl;

    return 0;
}