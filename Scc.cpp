#include <bits/stdc++.h>
using namespace std;

stack<int>st;
string colors[20];
int d[20],f[20],tim,graph[20][20]={0};
int newG[20][20];
void dfs_visit_2(int u, int numV);
void transpose(int numV);
void findScc(int numV);
void dfs_visit_2(int u, int numV)
{
    
    colors[u]="GREY";
    cout<<u<<" ";
    for(int v=0; v<numV; v++)
    {
        if(newG[u][v] && colors[v]=="WHITE")
        dfs_visit_2(v, numV);
    }
    colors[u]="BLACK";
}
void dfs_visit(int u, int numV)
{
    colors[u]="GREY";
    
    for(int v=0; v<numV; v++)
    {
        if(graph[u][v] && colors[v]=="WHITE")
        dfs_visit(v, numV);
    }
    colors[u]="BLACK";
    st.push(u);
}
void dfs(int numV)
{
    for(int u=0; u<numV; u++)
    {
        colors[u]="WHITE";
        d[u]=f[u]=-1;
    }
    tim=0;
    for(int u=0; u<numV; u++)
    {
        if(colors[u]=="WHITE")
        dfs_visit(u, numV);
    }
}
void transpose(int numV)
{
    for(int i=0; i<numV; i++)
    {
        for(int j=0; j<numV; j++)
        newG[j][i]= graph[i][j];
    }
}
void findScc(int numV)
{
    dfs(numV);
    transpose(numV);
    for(int u=0; u<numV; u++)
    {
        colors[u]="WHITE";
    }
    cout<<"Strongly Connected Components: "<<endl;
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        if(colors[temp]=="WHITE"){
        dfs_visit_2(temp, numV);
        cout<<endl;}
    }
}
int main() {
    int v,e,x,y;
    cout<<"Enter vertex number: ";
    cin>>v;
    cout<<"Enter edge number: ";
    cin>>e;
    cout<<"Enter edges: ";
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        graph[x][y]=1;
    }
    findScc(v);
    return 0;
}
