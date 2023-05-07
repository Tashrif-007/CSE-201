#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int x,y,n;
    Graph(int n){
        graph.resize(n);
    }
    vector<vector<int>>graph;
    void create(int x, int y)
    {
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    void print()
    {
        for(int i=0; i<graph.size(); i++)
        {
            cout<<"Adjacent vertex of " << i <<": ";
            for(int j=0; j<graph[i].size(); j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.create(0, 1);
    g.create(0, 4);
    g.create(1, 2);
    g.create(1, 3);
    g.create(1, 4);
    g.create(2, 3);
    g.create(3, 4);
    g.print();
    return 0;
}
