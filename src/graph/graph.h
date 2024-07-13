#include <iostream>

using namespace std;

class Node {
public:
    Node* adjList[100];
    int key;
    int flag = 0;

    Node(int key) {
        this->key = key;
        for (int i = 0; i < 100; ++i) {
            adjList[i] = nullptr;  // Initialize all pointers to nullptr
        }
    }

    void addEdge(Node* n) {
        adjList[flag] = n;
        flag = flag + 1;
    }
};

class Graph {
public:
    int Nodes;
    int** adj;
    Node* vertices[100];
    int NoV;

    Graph(int Nodes) {
        this->Nodes = Nodes;
        adj = new int*[Nodes];
        for (int i = 0; i < Nodes; ++i) {
            adj[i] = new int[Nodes];
            for (int j = 0; j < Nodes; ++j) {
                adj[i][j] = 0;  // Initialize with 0
            }
        }
        NoV = 0;
    }

    Graph() {
        NoV = 0;
        adj = nullptr;
    }

    ~Graph() {
        for (int i = 0; i < Nodes; ++i) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void AddNode(int key) {
        Node* n = new Node(key);
        vertices[NoV] = n;
        NoV = NoV + 1;
    }

    void AddEdge(int key, int val) {
        Node* add = nullptr;
        for (int j = 0; j < NoV; ++j) {
            if (vertices[j]->key == val) {
                add = vertices[j];
                break;
            }
        }
        if (add == nullptr) return;

        for (int i = 0; i < NoV; ++i) {
            if (vertices[i]->key == key) {
                vertices[i]->addEdge(add);
                break;
            }
        }
    }

    void displayADJ() {
        adj = new int*[NoV];
        for (int i = 0; i < NoV; ++i) {
            adj[i] = new int[NoV];
            for (int j = 0; j < NoV; ++j) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < NoV; ++i) {
            Node* temp = vertices[i];
            for (int j = 0; j < temp->flag; ++j) {
                if (temp->adjList[j] != nullptr) {
                    int adjKey = temp->adjList[j]->key;
                    adj[temp->key][adjKey] = 1;
                }
            }
        }

        for (int i = 0; i < NoV; ++i) {
            for (int j = 0; j < NoV; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};
