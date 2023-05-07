#include<bits/stdc++.h>
using namespace std;

bool graph[100][100]={false};
class Graph{
public:
    int n;
    Graph(int n){
        this->n = n;
    }
    void create(int x, int y)
    {
        graph[x][y]=true;
        graph[y][x]=true;
    }
    void print()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j])
                    cout<<"("<<i<<" "<<j<<")"<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.create(0,2);
    g.create(0,1);
    g.create(1,0);
    g.create(1,2);
    g.create(2,0);
    g.create(2,4);
    g.create(3,4);
    g.create(4,2);
    g.create(4,3);
    g.print();
    return 0;
}
