// Tomás Carro y Chang Hong
// FAL-E10 y FAL-E14


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


// función que resuelve el problema
std::vector<int> resolver() {
    std::vector<int> res(2);    //posicion 0: numero mayor posicion 1: numero de jugadores que han conseguido esa puntuacion
    int punt;
    std::cin >> res[0] >> punt;
    res[1] = 1;
    while (punt != 0)
    {
        if (punt > res[0])
        {
            res[0] = punt;
            res[1] = 1;
        }
        else if(punt == res[0])
        {
            res[1]++;
        }
        std::cin >> punt;
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    
    std::vector<int> sol = resolver();
    // escribir sol
    std::cout << sol[0] << " " << sol[1] << std::endl;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
