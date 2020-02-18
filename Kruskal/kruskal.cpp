#include <bits/stdc++.h>

using namespace std;

struct DisjointSets {
    int *parent, *rnk;
    int n;

    // Constructor.
    explicit DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //every element is parent of itself
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
           from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height
           a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int kruskal(vector<pair<int, pair<int, int>>> edges);

int main() {
    int vertices, edges;
    vector<pair<int,pair<int,int>>> graph;

    cin >> vertices >> edges;

    graph.resize(vertices);

    int u, v, w; // Vertice u, Vertice v e Peso W

    for (int i = 0; i < edges; ++i) { // Processo de criacao do grafo
        cin >> u >> v >> w;
        graph.push_back({w, {u,v}});
    }

    int mst_weight = kruskal(graph);

    cout << "Custo MST: " << mst_weight;

    return 0;
}

int kruskal(vector<pair<int, pair<int, int>>> edges) {
    int mst_weight = 0, vertices = edges.size();

    sort(edges.begin(), edges.end());

    DisjointSets ds(vertices);

    vector<pair<int, pair<int,int>>>::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v) {
            cout << u << " - " << v << endl;
            mst_weight += it->first;
            ds.merge(set_u, set_v);
        }
    }

    return mst_weight;
}

