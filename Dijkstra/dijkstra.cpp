#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<pair<int,int>>> graph, int vertices);

int main() {
    int vertices, edges;
    vector<vector<pair<int,int>>> graph;

    cin >> vertices >> edges;

    graph.resize(vertices);

    int u, v, w; // Vertice u, Vertice v e Peso W

    for (int i = 0; i < edges; ++i) { // Processo de criacao do grafo
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    dijkstra(graph, vertices);

    return 0;
}

void dijkstra(vector<vector<pair<int,int>>> graph, int vertices) {
    vector<int> dist; // Vetor de distancias
    dist.resize(vertices, INT_MAX);
    dist[0] = 0;

    // Fila de prioridade que guarda valores pair<int,int>, o menor numero (custo) fica no topo
    priority_queue <pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[0], 0});

    vector<pair<int, int>> path;
    path.resize(vertices, {0, -1});

    while (!pq.empty()) {
        pair<int, int> v = pq.top();
        pq.pop();

        // first eh o peso, second eh o vertice
        for (auto n: graph[v.second]) { // Percorre todos os vizinhos do vertice v, que estava no topo da fila de prioridade
            if (dist[v.second] + n.first < dist[n.second]) {
                dist[n.second] = dist[v.second] + n.first;
                path[n.second] = make_pair(dist[n.second], v.second);
                pq.push({dist[n.second], n.second});
            }
        }
    }

    printf("\nA seguir o caminho do vértice origem a todos os vértices: \n\n");

    for (int i = 0; i < vertices; ++i) { // Para printar o caminho para cada vertice
        printf("Caminho para o vertice %d: ", i);
        int aux = path[i].second, count = 0;
        int p[10000] = {0};
        while (aux != -1) {
            p[count++] = aux;
            aux = path[aux].second;
        }
        int j;
        if (count == 0) {
            printf("Origem, distancia 0\n");
        } else {
            for (j = count - 1; j >= 0; j--) {
                if (j == 0) {
                    printf("%d e distancia %d\n", p[j], dist[i]);
                } else {
                    printf("%d, ", p[j]);
                }
            }
        }
    }

}
