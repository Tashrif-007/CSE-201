#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int x,y;
    Node(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    int getV()
    {
        return y;
    }
};
void create(vector<vector<Node>>&graph,int x, int y)
{
    graph[x].push_back(Node(x,y));
    graph[y].push_back(Node(y,x));
}
void print(vector<vector<Node>>&graph, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Adjacent vertex of "<<i<<": "<<endl;
        for(int j=0; j<graph[i].size(); j++){
        Node n = graph[i][j];
        cout<<"("<<n.x<<" "<<n.y<<")"<<" ";
        }
        cout<<endl;
    }
}
void bfs(vector<vector<Node>>&graph, int start, int n)
{
    queue<int>q;
    bool visited[n]={false};
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto x : graph[start])
        {
            int v = x.getV();
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n,x,y,start,e;
    cout<<"Enter number of Vertex: "<<endl;
    cin>>n;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    vector<vector<Node>>graph(n);
    cout<<"Enter the connected vertices: "<<endl;
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        create(graph, x, y);
    }
    print(graph, n);
    cout<<endl;
    cout<<"Enter starting point: ";
    cin>>start;
    bfs(graph, start, n);
    return 0;
}
