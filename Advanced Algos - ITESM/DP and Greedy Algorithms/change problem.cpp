#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
/*
El programa recibe un numero entero N, seguido de N valores enteros 
(uno en cada línea) que representan las diferentes denominaciones 
disponibles de las monedas.

Seguido de esto, el programa recibe dos números enteros: P y Q, 
(uno en cada línea) por la entrada estándar, que representan P: 
el precio de un producto dado y Q: es el billete o moneda con el 
que se paga dicho producto.

La salida del programa es una lista de N valores correspondientes 
al número de monedas de cada denominación, de mayor a menor, 
una en cada línea, que se tienen que dar para dar el cambio por 
el producto pagado, primero utilizando programación dinámica, y 
luego utilizando un algoritmo avaro.
*/



int main(){
    int N, P, Q, m ;
    std::cin >> N;
    std::vector<int> denominations(N);
    for(int i = 0; i < N; i++){
        std::cin >> denominations[i];
    }

    std::cin >> P >> Q;

    // Greedy Algorithm

    std::cout << "Greedy Algorithm\n";

    std::sort(denominations.begin(), denominations.end(), std::greater<int>());
    m = Q - P;
    for(int i = 0; i < N; i++){
        while(m >= denominations[i]){
            std::cout << denominations[i] << '\n';
            m = m - denominations[i];
        }
    }
    
    // Dynamic Programming

    std::cout << "Dynamic Programming\n";

    int minCoins = INT_MAX;
    // Our objective
    m = Q - P;

    // To optimize space, we only need to store the last row of the table
    std::vector<int> lastRow(m + 1, INT_MAX);
    lastRow[0] = 0;

    for (int i = 0; i < N; i++) {
        std::vector<int> currentRow(m + 1, INT_MAX);
        for (int j = 0; j <= m; j++) {
            if (j >= denominations[i]) {
                if (lastRow[j - denominations[i]] != INT_MAX) {
                    currentRow[j] = std::min(currentRow[j], lastRow[j - denominations[i]] + 1);
                }
            }
            currentRow[j] = std::min(currentRow[j], lastRow[j]);
        }
        lastRow = currentRow;
    }
    
    if (lastRow[m] != INT_MAX) {
        // We can give change
        minCoins = lastRow[m];
    }
    else { 
        if (m == 0) {
            // If the objective is 0, we don't need any coins
            minCoins = 0;
        }
        else {
            // No solution
            minCoins = -1;
        }
    }

    std::cout << "Min coins: "<< minCoins << '\n';



    return 0;
}