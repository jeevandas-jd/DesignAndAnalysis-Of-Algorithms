#include <iostream>

#include <vector>
#include <limits>
using namespace std;

const int INF=numeric_limits<int>::max();

class Node{

    public:

    Node* adjlist[100];
    int flag;
    int key;

    Node(int key) : key(key), flag(0){
        for (int i=0;i<100;i++){
            adjlist[i]=nullptr;
        }
    }
    void AddEdge(Node* n){
        adjlist[flag]=n;
        flag++;
    }
};
    struct Edge {
        int u, v, weight;
    };
class Graph {
public:
    int Nodes;
    vector<Edge> edges; // Store edges in a vector
    Node* vertices[100];
    int NoV;



    Graph(int Nodes) : Nodes(Nodes), NoV(0) {
        for (int i = 0; i < 100; ++i) {
            vertices[i] = nullptr;
        }
    }

    void AddNode(int key) {
        if (NoV < 100) {
            Node* n = new Node(key);
            vertices[NoV++] = n;
        }
    }

    void AddEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
        if (vertices[u] && vertices[v]) {
            vertices[u]->AddEdge(vertices[v]);
        }
    }

    void BellmanFord(int src) {
        vector<int> dist(Nodes, INF);
        dist[src] = 0;

        // Relax edges repeatedly
        for (int i = 1; i < Nodes; ++i) {
            for (const auto& edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.weight;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
                cout << "Graph contains a negative weight cycle" << endl;
                return;
            }
        }

        // Print distances
        for (int i = 0; i < Nodes; ++i) {
            if (dist[i] == INF) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << dist[i] << endl;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < NoV; ++i) {
            delete vertices[i];
        }
    }
};

int main() {
    Graph g(5);

    g.AddNode(0);
    g.AddNode(1);
    g.AddNode(2);
    g.AddNode(3);
    g.AddNode(4);

    g.AddEdge(0, 1, -1);
    g.AddEdge(0, 2, 4);
    g.AddEdge(1, 2, 3);
    g.AddEdge(1, 3, 2);
    g.AddEdge(1, 4, 2);
    g.AddEdge(3, 2, 5);
    g.AddEdge(3, 4, 1);
    g.AddEdge(4, 3, -3);

    g.BellmanFord(0);

    return 0;
}