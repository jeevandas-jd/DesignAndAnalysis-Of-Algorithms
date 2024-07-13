#include "graph.h"

int main(){
    Graph g1;
   g1.AddNode(1);
   g1.AddNode(2);
   g1.AddNode(3);
   g1.AddNode(4);
   g1.AddNode(5);
   g1.AddEdge(1,2);
   g1.AddEdge(1,3);
   g1.AddEdge(1,4);
   g1.AddEdge(2,1);
   g1.AddEdge(2,3);
   g1.AddEdge(2,4);
   g1.AddEdge(2,5);
   g1.AddEdge(3,1);
   g1.AddEdge(3,2);
   g1.AddEdge(3,4);
   g1.AddEdge(4,1);
   g1.AddEdge(4,2);
   g1.AddEdge(4,3);
   g1.AddEdge(4,5);
   g1.displayADJ();


}

