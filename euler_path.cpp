#include <iostream>
using namespace std;
#define max 20

int graph[max][max]={0};
int deg[max]={0};


void create(int x, int y){
    graph[x][y]=1;
    graph[y][x]=1;
}
void calculateDegree(int v){
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(graph[i][j])
            {
                deg[i]++;
                deg[j]++;
            }
        }
    }
}

bool hasEulerPath(int v){
    int odd=0;
    calculateDegree(v);
    for(int i=0; i<v; i++)
    {
        if(deg[i]%2)
        odd++;
    }
    return odd==0 || odd==2;
}
int main() {
    int v,e,x,y;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        create(x, y);
    }
    cout<<hasEulerPath(v);
    
    return 0;
}
