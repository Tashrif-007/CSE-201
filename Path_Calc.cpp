#include <iostream>
using namespace std;

int visited[20]={0};
int Adj[20][20] = {0};
int paths;

void pathCalc(int u, int dest, int numV)
{
    visited[u]= 1;
    
    if(u==dest)
    {
        paths++;
        visited[u]=0;
        return;
    }

    for (int v = 0; v < numV; v++)
    {
        if (Adj[u][v] && !visited[v])
        {
            pathCalc(v, dest, numV);
        }
    }
    
    visited[u]=0;
}

int main()
{
    int numVertices, numEdges, source, dest;
    cout<<"Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (vertex1 vertex2):\n";
    for (int i = 0; i < numEdges; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        Adj[vertex1][vertex2] = 1;
    }
    cout<<"Enter source: ";
    cin>>source;
    cout<<"Enter destination: ";
    cin>>dest;
    
    pathCalc(source, dest, numVertices);

    cout<<paths;
    return 0;
}
