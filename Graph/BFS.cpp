// DFS: depth first search
// BFS: Breadth first search
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool edge[1001][1001];
bool vtx[1001];
int path[1001];
queue<int> vertex;
// Loop
int bfs(int u, int v, int n){
    int max = 0;
    vertex.push(u);
    while(!vertex.empty()){
        int cur = vertex.front();
        vertex.pop();
        for(int i = 1; i <= n; ++i){
            if(edge[cur][i]){
                vertex.push(i);
                path[i] = path[cur] + 1;
            }
        }
        if(edge[cur][v]){ 
            if(max < path[cur] + 1) path[v] = path[cur] + 1 ;
        }
        
    }
    if(path[v]) return path[v];
    else return -1;
}

//De quy
void findShortest(int u, int v, int n, int path[], int &result){
    if(edge[u][v]){
        result = path[u] + 1;
    }else{
        while(!vertex.empty()){
            vertex.pop(); 
            for(int i = 1; i <= n; ++i){
                if(edge[u][i]) vertex.push(i);
            }
            if(!vertex.empty()){
                int cur = vertex.front();
                path[cur] = path[u] + 1 ;
                edge[u][cur] = false;
                edge[cur][u] = false;
                cout << cur << path[cur] <<endl;
                findShortest(cur, v, n, path, result);
            }
        }
    }
}


int graphFunction(int n, std::vector<std::vector<int>> e, int u, int v)
{
    for(int i = 1; i <= n; ++i){
        vtx[i] = true;
    }
    for(int i = 1; i <=n; ++i){
        for(int j = 1; j <= n; ++j){
            edge[i][j] = false;
        }
    }
    for(int i = 0; i < e.size(); ++i){
        edge[e[i][0]][e[i][1]] = true;
        edge[e[i][1]][e[i][0]] = true;
    }

    for(int i = 1; i <= n; ++i){
        path[i] = 0;
    }
    vertex.push(u);
    int result = -1;
    findShortest(u,v,n,path, result);
    return result;
}

int main(){
    int n, u, v; 
    cin >> n;
    vector<vector<int>> e = {{1,2}, {1,3},{3,4},{4,5}};
    cin >> u >>v;
    cout << graphFunction(n, e, u, v);
    return 0;
}