#include <iostream>

using namespace std;

class Node{
    public:
    Node* adjv[100];
    string token;
    int flag;
    void addEdge(Node * n);

};