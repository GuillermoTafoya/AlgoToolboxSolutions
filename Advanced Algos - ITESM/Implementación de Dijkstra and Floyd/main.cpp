/*
Escribe un programa en C++ que implemente los algoritmos de Dijkstra y
Floyd para encontrar la distancia más corta entre parejas de nodos en un
grafo dirigido. 

El programa debe leer un numero n seguido de n x n valores enteros no negativos
que representan una matriz de adyacencias de un grafo dirigido.
El primer número representa el número de nodos, los siguientes valores en la matriz, 
el valor en la posición i,j representan el peso del arco del nodo i al nodo j. 
Si no hay un arco entre el nodo i y el nodo j, el valor en la matriz debe ser -1

La salida del programa es, primero con el algoritmo de Dijkstra la distancia del nodo 
i a l nodo j para todos los nodos, y luego, la matriz resultado del algoritmo de Floyd.

Ejemplo de entrada:

4
0 2 -1 3
-1 0 1 5
2 3 0 -1
3 -1 4 0

Ejemplo de salida:

Dijkstra :
node 1 to node 2 : 2
node 1 to node 3 : 3
node 1 to node 4 : 3
node 2 to node 1 : 3
...

node 4 to node 2 : 5
node 4 to node 3 : 4

Floyd :
0 2 3 3
3 0 1 5
2 3 0 5
3 5 4 0
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>

std::vector<int> dijkstra(const std::vector<std::vector<int>> &graph, int source)
{
    std::vector<int> dist(graph.size(), std::numeric_limits<int>::max());
    std::vector<bool> visited(graph.size(), false);
    dist[source] = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        int u = -1;
        for (int j = 0; j < graph.size(); j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        if (dist[u] == std::numeric_limits<int>::max())
            break;
        visited[u] = true;
        for (int v = 0; v < graph.size(); v++)
        {
            if (graph[u][v] != -1)
            {
                int distance = dist[u] + graph[u][v];
                dist[v] = std::min(distance,dist[v]);
            }
        }
    }
    return dist;
}
void processDijkstra(const std::vector<std::vector<int>> &graph){
    int V = graph.size();
    
    // Print shortest distances
    std::cout << "Dijkstra :" << std::endl;

    for (int i = 0; i < graph.size(); ++i){
        std::vector<int> dist = dijkstra(graph, i);
        for (int j = 0; j < graph.size(); ++j){
            if (i != j){
                std::cout << "node " << i + 1 << " to node " << j + 1 << " : " << dist[j] << std::endl;
            }
        }
    }
}


void floyd(const std::vector<std::vector<int>> &graph){
    std::vector<std::vector<int>> dist(graph);
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            for (int j = 0; j < graph.size(); ++j)
            {
                if (dist[i][k] != -1 && dist[k][j] != -1)
                {
                    if (dist[i][j] != -1)
                    {
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                    else
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Print shortest distances
    std::cout << "Floyd :" << std::endl;

    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph.size(); ++j)
        {
            std::cout << std::setw(2) << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    // Read graph
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            std::cin >> graph[i][j];
        }
    }

    // Dijkstra
    processDijkstra(graph);

    // Floyd
    floyd(graph);

    return 0;
}