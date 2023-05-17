#include<iostream>
using namespace std;

int graph[20][20] = {0};
int q[20], f = -1, r = -1;

void enqueue(int n)
{
    if (r == 19) {
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
        cout << "Adjacent of " << i << ": ";
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j])
                cout << j << " ";
        }
        cout << endl;
    }
}

void bfs(int start, int v)
{
    int visited[20] = {0};
    enqueue(start);
    visited[start] = 1;
    while (f <= r)
    {
        int temp = dequeue();
        cout << temp << " ";
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
    int x, y, v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        create(x, y);
    }

    cout << "BFS traversal starting from vertex 0: ";
    bfs(0, v);
    cout << endl;

    // Print the adjacency list
    cout << "Adjacency list:\n";
    print(v);

    return 0;
}
