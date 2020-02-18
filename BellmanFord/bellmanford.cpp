#include <bits/stdc++.h>

using namespace std;

void bellman_ford(vector<vector<pair<int,int>>> graph, int vertices);

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

    bellman_ford(graph, vertices);

    return 0;
}

void bellman_ford(vector<vector<pair<int,int>>> graph, int vertices) {
    vector<int> dist(vertices, INT_MAX);
    vector<int> parent(vertices, -1);

    dist[0] = 0;
    parent[0] = 0;

    for (int i = 1; i < vertices; i++) {
        for (int u = 0; u < vertices; u++) {
            for (auto n: graph[u]) {
                int v = n.second;
                int w = n.first;

                if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    parent[v] = u;
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 0; u < vertices; u++) {
        for (auto n: graph[u]) {
            int v = n.second;
            int w = n.first;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "O grafo contem um ciclo negativo\n\n";
            }
        }
    }

    cout << "A partir do vertice 0\n";
    cout << "Ate\tCusta" << endl;
    for (int i = 0; i < vertices; ++i)
        cout << " " << i << "    -\t  " << dist[i] << endl;

    cout << endl << "Vertice \t Pai" << endl;
    for (int i = 0; i < vertices; ++i)
        cout << "   " <<i << "       -\t  " << parent[i] << endl;
}