#include <iostream>

#include <climits>

using namespace std;
int MinDistace(int dist[3],bool flag[3]){

    int min=INT16_MAX;
    int index;
    for(int i =0;i<3;i++){
        if(flag[i]==false && dist[i]<min){
            index=i;
            min=dist[i];
        }
    }
    cout<<"first index = "<<index<<endl;
    return index;

}

void relax();
void dijkstra(int graph[3][3],int src){

    int dist[3];
    bool flags[3];

    for(int i =0;i<3;i++){
        dist[i]=INT16_MAX;
        flags[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<3;i++){
        int m=MinDistace(dist,flags);
        flags[m]=true;
        for(int j=0;j<3;j++){
            if(flags[j]==false && graph[m][j]!=0 && dist[m]<INTMAX_MAX && dist[m]+graph[m][j]<dist[j]){
                dist[j]=dist[m]+graph[m][j];
            }

        }
        
    }
    char str;
    for(int i=0;i<3;i++){
        str=65+i;
        cout<<str<<"\t\t\t"<<dist[i]<<endl;
    }
}

int main(){
   int graph[3][3] = {
    {0, 3, 1},
    {3, 0, 7},
    {1, 7, 0}
};


    dijkstra(graph,0);
}

