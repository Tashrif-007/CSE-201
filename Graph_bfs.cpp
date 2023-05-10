#include<bits/stdc++.h>
using namespace std;

void create(vector<vector<int>>&graph,int x, int y)
{
    graph[x].push_back(y);
    graph[y].push_back(x);
}
void print(vector<vector<int>>&graph, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Adjacent vertex of "<<i<<": "<<endl;
        for(int j=0; j<graph[i].size(); j++){
        cout<<"("<<graph[i][j]<<")"<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,x,y,start,e;
    cout<<"Enter number of Vertex: "<<endl;
    cin>>n;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    vector<vector<int>>graph(n);
    cout<<"Enter the connected vertices: "<<endl;
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        create(graph, x, y);
    }
    print(graph, n);
    return 0;
}
