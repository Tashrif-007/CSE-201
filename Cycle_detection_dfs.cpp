#include <iostream>
using namespace std;

string color[20];
int Adj[20][20] = {0};
int d[20], tim;
int pre[20], f[20];
bool hasCycle;

void dfs_visit(int u, int numV)
{
    color[u] = "GREY";
    tim++;
    d[u] = tim;

    for (int v = 0; v < numV; v++)
    {
        if (Adj[u][v] && color[v] == "WHITE")
        {
            pre[v] = u;
            dfs_visit(v, numV);
        }
        else if(color[v]=="GREY"){
        hasCycle = true;
        return;
        }
    }
    color[u] = "BLACK";
    tim++;
    f[u] = tim;
}

void dfs(int numV)
{
    for (int u = 0; u < numV; u++)
    {
        color[u] = "WHITE";
        pre[u] = -1;
        f[u] = d[u] = -1;
    }
    tim = 0;
    hasCycle =false;
    
    for (int u = 0; u < numV; u++)
    {
        if (color[u] == "WHITE")
            dfs_visit(u, numV);
            if(hasCycle)
            break;
    }
}

int main()
{
    int numVertices, numEdges;
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

    dfs(numVertices);

    if(hasCycle)
    cout<<"The graph has cycle";
    else
    cout<<"The graph does not have cycle";
    return 0;
}
