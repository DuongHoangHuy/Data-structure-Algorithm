#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color (n, 0);
    queue<int> bfs;
    for(int j = 0; j < n; ++j){
        if(!color[j]){
            color[j] = 1;
            bfs.push(j);
            while(!bfs.empty()){
                int cur = bfs.front();
                bfs.pop();
                for(int i = 0; i < graph[cur].size(); ++i){
                    int neighbor = graph[cur][i];
                    if(color[neighbor] == 0){
                        color[neighbor] = -color[cur];
                        bfs.push(neighbor);
                    }else if(color[neighbor] == color[cur]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> a = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << isBipartite(a);
    return 0;
}   