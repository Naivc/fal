
// Tomás Carro y Chang Hong
// FAL-E10 y FAL-E14


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>


// función que resuelve el problema
std::string resolver(std::vector<std::string> v, std::string paisBuscar) {
    int anyos = 0;
    bool encontrado = false;
    while (!encontrado && anyos < (int)v.size())
    {
        anyos++;
        if (v[(int)v.size() - anyos] == paisBuscar)
        {
            encontrado = true;
        }
    }
    if (!encontrado)
        return "NUNCA";
    else
        return std::to_string(anyos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numAnyos;
    std::cin >> numAnyos;
    if (numAnyos == 0)
        return false;

    std::vector<std::string> paises;
    std::string paisBuscar;
    std::cin >> paisBuscar;

    std::string nombres;
    for (int i = 0; i < numAnyos; i++)
    {
        std::cin >> nombres;
        paises.push_back(nombres);
    }

    std::string sol = resolver(paises, paisBuscar);

    // escribir sol
    std::cout << sol << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
