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
int main()
{
    int n,x,y;
    cout<<"Enter number of Vertex: "<<endl;
    cin>>n;
    vector<vector<Node>>graph(n);
    cout<<"Enter the connected vertices: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        create(graph, x, y);
    }
    print(graph, n);
    return 0;
}
