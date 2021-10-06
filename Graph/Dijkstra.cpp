#include <iostream>
#include <vector>
using namespace std;

const int n = 18;
const int pth = 28;
#define MAX 99999999

int minDistance(vector<int> dist, bool vtx[]){
    int min = MAX;
    int minDist;
    for(int i = 0; i < n; ++i){
        if(dist[i] < min && !vtx[i]){
            minDist = i;
            min = dist[i];
        }
    }
    return minDist;
}

void Dijkstra(int begin, int end, int edge[n][n]){
    vector<int> dist(n, MAX);
    bool vtx[n];
    int prev[n];
    for(int i = 0; i < n; ++i){
        prev[i] = i;
    }
    dist[begin] = 0;
    int cur;

    for(int i = 0; i < n; ++i){
        cur = begin;
        cur = minDistance(dist, vtx);
        if(cur == end) break;
        vtx[cur] = true;
        for(int j = 0; j < n; ++j){ 
            if(edge[cur][j] && dist[cur] + edge[cur][j] < dist[j]){
                // cout << j <<" ";
                dist[j] = dist[cur] + edge[cur][j];
                prev[j] = cur; 
            }
        }
    }
    cout <<"Total: "<<dist[end] <<endl;
    int i = end;
    vector<int> temp;
    while(prev[i] != i){
        temp.push_back(i);
        i = prev[i];
    }
    temp.push_back(begin);
    for(int i = temp.size()-1; i >= 0; --i){
        cout << temp[i] << (i !=0 ?"->":"");
    }
}

int main(){
    int edge[n][n];
    int connect[pth][2]={ {0,14},   {0,7},   {0,4},   {0,1},  {1,4},   {1,2},  {2,5},   {2,6},  {3,6},  {3,10},  {5,8},   {5,9},  {6,9},  {6,10}, {7,11}, {8,11},  {8,12}, {9,10},  {9,13},{10,13},{11,14}, {11,12},{12,15}, {12,13},{13,16}, {13,17},{14,15},{16,17}};
    int path[pth] = {9,1,5,6,5,5,3,6,2,4,9,7,6,6,9,6,8,5,9,4,2,8,6,1,1,7,1,9};
    for(int i = 0; i < n; ++i){
        for(int j =0; j < n; ++j){
            edge[i][j] = 0;
        }
    }
    for(int i = 0; i < pth; ++i){
        edge[connect[i][0]][connect[i][1]] = path[i];
        edge[connect[i][1]][connect[i][0]] = path[i];
        // cout << connect[i][0]<<" "<<connect[i][1] <<":"<<path[i]<<endl;
    }
    int s,f;
    cin >> s >> f;
    Dijkstra(s, f, edge);
    return 0;
}