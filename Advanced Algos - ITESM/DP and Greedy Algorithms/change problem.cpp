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

    int minCoins = 100000;
    // Our objective
    m = Q - P;

    // To optimize space, we only need to store the last row of the table
    std::vector<int> lastRow(m + 1, 100000);
    lastRow[0] = 0;

    // We iterate over the denominations
    for(int i = 0; i < N; i++){
        // We iterate over the values of the objective
        for(int j = 1; j <= m; j++){
            // We check if the denomination is less than the value
            if(denominations[i] <= j){
                // We check if the number of coins is less than the previous value
                if(lastRow[j - denominations[i]] + 1 < lastRow[j]){
                    lastRow[j] = lastRow[j - denominations[i]] + 1;
                }
            }
        }
    }

    // We print the number of coins
    // std::cout << lastRow[m] << '\n';

    // We print the denominations
    int i = N - 1;
    while(m > 0){
        if(lastRow[m] == lastRow[m - denominations[i]] + 1){
            std::cout << denominations[i] << '\n';
            m = m - denominations[i];
        }
        else{
            i--;
        }
    }



    return 0;
}