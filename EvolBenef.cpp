
// Tomás Carro y Chang Hong
// FAL-E10 y FAL-E14


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> ventas, int anyoIni) {
    int max = ventas[0];
    std::vector<int> res;
    for (int i = 1; i < (int)ventas.size(); i++)
    {
        if (ventas[i] > max)
        {
            max = ventas[i];
            res.push_back(anyoIni + i);
        }
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int anyoMayor, anyoMenor;
    std::cin >> anyoMenor >> anyoMayor;
    int tam = anyoMayor - anyoMenor + 1;
    std::vector<int> ventas(tam);
    for (int i = 0; i < tam; i++)
        std::cin >> ventas[i];      

    std::vector <int> sol = resolver(ventas, anyoMenor);
    // escribir sol
    for (int i = 0; i < (int)sol.size(); i++)
        std::cout << sol[i] << " ";

    std::cout << std::endl;

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
