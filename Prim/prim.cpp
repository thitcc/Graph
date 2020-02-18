#include <bits/stdc++.h>

using namespace std;

int prim(vector<vector<pair<int,int>>> graph, int vertices);

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

    printf("Custo da MST: %d", prim(graph, vertices));

    return 0;
}

int prim(vector<vector<pair<int,int>>> graph, int vertices) {
    int mst_weight = 0;

    vector<int> lowestDist(vertices, INT_MAX);
    vector<int> parents(vertices, -1);
    vector<bool> visited(vertices, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    lowestDist[0] = 0;
    pq.push({lowestDist[0], 0});

    while(!pq.empty()) {
        int u = pq.top().second;
        visited[u] = true;

        pq.pop();

        for (auto n: graph[u]) {
            int v = n.second;
            int w = n.first;

            if (!visited[v] && w < lowestDist[v]) {
                lowestDist[v] = w;
                parents[v] = u;
                pq.push({w, v});
            }
        }
    }

    for (int i = 1; i < vertices; ++i) {
        cout << "Caminho de " << parents[i] << " para " << i << " - custo: " << lowestDist[i] << endl;
        mst_weight += lowestDist[i];
    }

    return mst_weight;
}