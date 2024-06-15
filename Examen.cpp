#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para la semilla del generador de números aleatorios
#include <string>  // Para usar strings

using namespace std;

// Función para generar un número aleatorio entre min y max (incluidos)
int generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Clase Sensor
class Sensor {
private:
    string tipo;
    int valorActual;
    int limiteSuperior;
    string unidadMedida;

public:
    Sensor(string tipo, int limiteSuperior, string unidadMedida)
        : tipo(tipo), limiteSuperior(limiteSuperior), unidadMedida(unidadMedida) {
        valorActual = 0; // Inicializamos el valor del sensor
    }

    void generarDatoAleatorio() {
        valorActual = generarNumeroAleatorio(0, limiteSuperior);
    }

    int getValorActual() const { return valorActual; }
    string getTipo() const { return tipo; }
    string getUnidadMedida() const { return unidadMedida; }

    bool superaLimiteSuperior() const {
        return valorActual > limiteSuperior;
    }
};

// Verificar y mostrar alertas tempranas
void verificarAlertaTemprana(const Sensor& sensor) {
    if (sensor.superaLimiteSuperior()) {
        cout << "¡Alerta Temprana! " << sensor.getTipo() << " ha superado el límite de seguridad: " << sensor.getValorActual() << " " << sensor.getUnidadMedida() << endl;
    }
}


int main() {
    srand(time(0));

    // Provincias de Costa Rica
    string provincias[7] = {"San Jose", "Alajuela", "Cartago", "Heredia", "Guanacaste", "Puntarenas", "Limon"};

    // Fronteras de Costa Rica
    string fronteras[2] = {"Panama", "Nicaragua"};

    // Sensores
    Sensor temperatura("Temperatura", 30, "°C");
    Sensor humedad("Humedad", 80, "%");
    Sensor calidadAire("Calidad del aire", 100, "ppm");

    // (7 provincias y 2 fronteras)
    for (int i = 0; i < 7; ++i) { // Cambio aquí: itera sobre las 7 provincias
        // Mostrar título de la provincia
        cout << "Provincia: " << provincias[i] << endl;

      
        temperatura.generarDatoAleatorio();
        humedad.generarDatoAleatorio();
        calidadAire.generarDatoAleatorio();

        //lecturas de sensores
        cout << " - " << temperatura.getTipo() << ": " << temperatura.getValorActual() << " " << temperatura.getUnidadMedida() << endl;
        cout << " - " << humedad.getTipo() << ": " << humedad.getValorActual() << " " << humedad.getUnidadMedida() << endl;
        cout << " - " << calidadAire.getTipo() << ": " << calidadAire.getValorActual() << " " << calidadAire.getUnidadMedida() << endl;

        // Alertas tempranas
        verificarAlertaTemprana(temperatura);
        verificarAlertaTemprana(humedad);
        verificarAlertaTemprana(calidadAire);

        cout << "-------------------------------------------------------------" << endl;
        _sleep(2000);
    }

    //Fronteras (Panamá y Nicaragua)
    for (int i = 0; i < 2; ++i) {
        // Mostrar título de la frontera
        cout << "Frontera: " << fronteras[i] << endl;

      
        temperatura.generarDatoAleatorio();
        humedad.generarDatoAleatorio();
        calidadAire.generarDatoAleatorio();

        // Lecturas de sensores
        cout << " - " << temperatura.getTipo() << ": " << temperatura.getValorActual() << " " << temperatura.getUnidadMedida() << endl;
        cout << " - " << humedad.getTipo() << ": " << humedad.getValorActual() << " " << humedad.getUnidadMedida() << endl;
        cout << " - " << calidadAire.getTipo() << ": " << calidadAire.getValorActual() << " " << calidadAire.getUnidadMedida() << endl;

        // Verificar alertas tempranas
        verificarAlertaTemprana(temperatura);
        verificarAlertaTemprana(humedad);
        verificarAlertaTemprana(calidadAire);

        
        cout << "-------------------------------------------------------------" << endl;
        _sleep(2000); 
    }

    return 0;
}

