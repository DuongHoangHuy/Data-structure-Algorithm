#include <iostream>
#include <vector>
using namespace std;

//Ajacent list: hcm street map
//Print out connected sub graph of int **a, int n

bool edge[1001][1001];
bool vtx[1001]; 
vector<vector<int>> e;
vector<int> list;
int n;

void DFS(int visit){
    cout << visit << " ";
    for(int i = 0; i < n; ++i){
        if(vtx[i] && edge[visit][list[i]] ){
            vtx[visit] = false;
            edge[visit][list[i]] = false;
            edge[list[i]][visit] = false;
            DFS(list[i]);
        }   
    }
}

void allSubGraph(){
    for(int i=0; i < n; ++i){
        if(vtx[i]){
            vtx[i] = false;
            DFS(list[i]);
            cout << endl;
        }
    }
}

void setUp(){
    for(int i = 0; i < n; ++i){
        vtx[i] = true;
    }

    for(int i = 0; i < e.size(); ++i){
        edge[e[i][0]][e[i][1]] = true;
        edge[e[i][1]][e[i][0]] = true;
    }
}

int main(){
    e = {{3,9},{3,6},{9,7},{2,8}, {4,10},{10,10}};
    list = {3,9,6,7,2,8,4,10};
    n = list.size();
    setUp();
    allSubGraph();
    return 0;
}