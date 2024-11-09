#include <iostream>
using namespace std;

const int V = 5; // Number of vertices (Constant)

struct Edge {
    int src, des, weight;
};

string departmentNames[V] = {"Admin", "CS", "ENTC", "Mech", "Civil"};

int minKey(int key[], bool inMST[]) {
    int min = 999999;
    int min_index;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    bool inMST[V] = {false};

    for (int i = 0; i < V; i++) {
        key[i] = 999999;
        parent[i] = -1;
    }
    key[0] = 0;

    int total_weight = 0; // Variable to store the total weight of the MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Minimum Spanning Tree (MST) using Prim's algorithm :\n";
    cout << "Edge \t\tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << departmentNames[parent[i]] << " - " << departmentNames[i] << "\t" << graph[i][parent[i]] << "m\n";
        total_weight += graph[i][parent[i]]; // Sum the weights of the MST
    }
    cout << "Total weight of the MST using Prim's algorithm: " << total_weight << "m\n";
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(Edge edges[], int edgeCount) {
    // Sort edges based on weight
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    int total_weight = 0; // Variable to store the total weight of the MST

    cout << "\nMinimum Spanning Tree (MST) using Kruskal's algorithm:\n";
    cout << "Edge \t\tWeight\n";
    for (int i = 0; i < edgeCount; i++) {
        int src = edges[i].src;
        int dest = edges[i].des;
        int weight = edges[i].weight;

        if (find(parent, src) != find(parent, dest)) {
            cout << departmentNames[src] << " - " << departmentNames[dest] << "\t" << weight << "m\n";
            unionSets(parent, src, dest);
            total_weight += weight; // Sum the weights of the MST
        }
    }
    cout << "Total weight of the MST using Kruskal's algorithm: " << total_weight << "m\n";
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},  // Distances from Admin to other departments
        {2, 0, 3, 8, 5},  // Distances from CS to other departments
        {0, 3, 0, 0, 7},  // Distances from ENTC to other departments
        {6, 8, 0, 0, 9},  // Distances from Mech to other departments
        {0, 5, 7, 9, 0}   // Distances from Civil to other departments
    };

    primMST(graph);

    Edge edges[] = {
        {0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5},
        {2, 4, 7}, {3, 4, 9}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);
    kruskalMST(edges, edgeCount);

    return 0;
}

