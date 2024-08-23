#include <iostream>

using namespace std;
#de
class graph{
    public:
    int cost[100][100];
    int Nodes;

    graph(int n){
        this->Nodes=n;
    }

    void setCost(){
        for(int i =0;i<Nodes;i++){
            for(int j=0;j<Nodes;j++){
                cout<<"enter distance between "<<i<<"And"<<j<<endl;
                cin>>cost[i][j];
            }
        }
    }
};
