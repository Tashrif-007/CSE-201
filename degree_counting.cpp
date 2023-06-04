#include <iostream>
using namespace std;
#define max 20

int graph[max][max]={0};
int in[max]={0};
int out[max]={0};

void create(int x, int y){
    graph[x][y]=1;
}
void calculateDegree(int v){
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(graph[i][j])
            {
                out[i]++;
                in[j]++;
            }
        }
    }
}
int main() {
    int v,e,x,y;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        create(x, y);
    }
    calculateDegree(v);
    cout<<"vertex\t\t"<<"In\t\t\t"<<"out"<<endl;
    for(int i=0; i<v; i++)
    {
        cout<<i<<"\t\t\t"<<in[i]<<"\t\t\t"<<out[i]<<endl;
    }
    return 0;
}
