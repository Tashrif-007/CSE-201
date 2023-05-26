#include<iostream>
using namespace std;
#define max 10

string names[max];
int graph[max][max] = {0};
int q[max], f = -1, r = -1;

void enqueue(int n)
{
    if (r == max) {
        cout << "Overflow\n";
        return;
    }
    if (f == -1)
        f = 0;
    r++;
    q[r] = n;
}

int dequeue()
{
    if (f > r || f == -1) {
        cout << "Underflow\n";
        return -1;
    }
    return q[f++];
}

void create(int x, int y)
{
    graph[x][y] = 1;
    graph[y][x] = 1;
}

void print(int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Adjacent of " << names[i] << ": ";
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j])
                cout << names[j] << " ";
        }
        cout << endl;
    }
}

void bfs(int start, int v)
{
    int visited[20] = {0};
    enqueue(start);
    visited[start] = 1;
    cout <<"You can travel from "<<names[start]<<" to: "<<endl;
    while (f <= r)
    {
        int temp = dequeue();
        if(temp!=start)
        cout<<names[temp]<<endl;
        for (int i = 0; i < v; i++)
        {
            if (graph[temp][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int v,e,x,y,start;
    string a,b;
    cout<<"Enter country num: ";
    cin>>v;
    cout<<"Enter countries: ";
    for(int i=0; i<v; i++)
    cin>>names[i];
    cout<<"Enter edge num: ";
    cin>>e;
    cout<<"Enter connections: ";
    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        for(int j=0; j<v; j++)
        {
            if(a==names[j])
            x=j;
            if(b==names[j])
            y=j;
        }
        create(x, y);
    }
    cout<<"Enter starting country: ";
    cin>>a;
    for(int i=0; i<v; i++)
    {
        if(a==names[i]){
        start=i;
        break;
        }
    }
    bfs(start, v);
    return 0;
}
