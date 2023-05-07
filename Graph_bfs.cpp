#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000;

bool g[5][5]={{0,1,1,0,0},
                {1,0,0,1,0},
                {1,0,0,1,0},
                {0,1,1,0,1},
                {0,0,0,1,0}
    };
bool visited[MAXN];

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for(int i=1; i<=n; i++) {
            if(g[curr][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){

    bfs(1,5);
    return 0;
}
