#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Vertex{
    public:
    int id;

    list<Edge> edgeList;
    int getValue();
    void setValue();
    void connectTo();
    void connectedFrom();
};
class Edge{
    public:
    int destId;
    int weight;
};

class Graph{
    public:
    vector <Vertex> vertices;
    void addNode();
    void addConnections();
    void removeConnection();
};
