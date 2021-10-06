// DFS: depth first search
// BFS: Breadth first search
#include <iostream>
#include <vector>
using namespace std;


bool edge[1001][1001];
bool vertex[10001]; 
// find connect by DFS
void findPath(int u, int v, int n, bool &ktr){
    for(int i = 1; i <= n; ++i){
        if(edge[u][i] && vertex[i]){
            if(i == v){
                ktr = true;
                return;
            }
            vertex[i] = false;
            findPath(i, v, n, ktr);
            vertex[i] = true;
        }
    }
}

bool isConnected(int n, std::vector<vector<int>> e, int u, int v)
{
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            edge[i][j] = false;
        }
    }

    for(int i = 0; i <= n; ++i){
        vertex[i] = true;
    }

    for(int i = 0; i < e.size(); ++i){
        edge[e[i][0]][e[i][1]] = true;
    }

    for(int i = 2; i <=n ; ++i){
        bool ktr = false;
        findPath(1,i,n,ktr);
        if(!ktr) return false;
        bool ktr = false;
    }
    return true;
}
// find valid path:
void dfs(vector<vector<int>> &matrix, int start, int end, bool &find, vector<bool> &vtx){
    if(start == end){
        find = true;
        return;
    }
    vtx[start] = false;
    for(int i = 0; i < matrix[start].size(); ++i){
        if(vtx[matrix[start][i]]){
            dfs(matrix, matrix[start][i], end, find, vtx);
        }
    }
}
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> matrix(n);
    for(int i = 0; i < edges.size(); ++i){
        matrix[edges[i][0]].push_back(edges[i][1]);
        matrix[edges[i][1]].push_back(edges[i][0]);
    }
    bool find = false;
    vector<bool> vtx (n, true);
    dfs(matrix, start, end, find, vtx);
    return find;
}



//Ajacent list: hcm street map

//Print out connected sub graph of int **a, int n

int main(){
    int n, u, v; 
    cin >> n;
    vector<vector<int>> e = {{1,2}, {2,3}, {3,4}};
    cin >> u >>v;
    cout << isConnected(n, e, u, v);
    return 0;
}