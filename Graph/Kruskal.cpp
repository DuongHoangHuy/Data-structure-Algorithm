//sort the edge in ascending order, start - end
//keep the shortest -> not creating circle
// Using 2 array: 
//-> 1 is the distance
// -> is from
// eclectricity generator
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

#define n 6

int checkParent(int i, int parent[]){
    if(i == parent[i]) return i;
    else{
        return checkParent(parent[i],parent);
    }
}

void Kruskal(vector<pair<int,pair<int,int>>> graph, int parent[], int edge[n][n]){
    int total = 0;
    sort(graph.begin(),graph.end());
    for(int i = 0; i < graph.size(); ++i){
        // cout << graph[i].second.first <<" "<<graph[i].second.second <<endl;
        int vtx1 = checkParent(graph[i].second.first,parent);
        int vtx2 = checkParent(graph[i].second.second,parent);
        if(vtx1 != vtx2){
            cout << graph[i].second.first<<"-"<<graph[i].second.second<<"="<<graph[i].first<<endl;
            total += graph[i].first;
            parent[vtx2] = parent[vtx1];
        }
    }
    cout << total;
}



int main(){
    // int edge[n+1][n+1]={//0  1  2  3  4  5  6  7  8  
    //                      {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },//0
    //                      {0 ,0 ,50,75,12,10,46,0 ,65},//1
    //                      {0 ,50,0 ,5 ,7 ,0 ,0 ,0 ,0 },//2
    //                      {0 ,75,5 ,0 ,49,0 ,0 ,35,17},//3
    //                      {0 ,12,7 ,49,0 ,27,19,43,80},//4
    //                      {0 ,10,0 ,0 ,27,0 ,60,0 ,54},//5
    //                      {0 ,46,0 ,0 ,19,60,0 ,0 ,22},//6
    //                      {0 ,0 ,0 ,35,43,0 ,0 ,0 ,3 },//7
    //                      {0 ,65,0 ,17,80,54,22,3 ,0 } //8
    //                     };
    int edge[n][n];
    // int connect[28][2]={ {0,14},   {0,7},   {0,4},   {0,1},  {1,4},   {1,2},  
    // {2,5},   {2,6},  {3,6},  {3,10},  {5,8},   {5,9},  {6,9},  {6,10}, {7,11}, 
    // {8,11},  {8,12}, {9,10},  {9,13},{10,13},{11,14}, {11,12},{12,15}, {12,13},
    // {13,16}, {13,17},{14,15},{16,17}};
    // int path[28] = {9,1,5,6,5,5,3,6,2,4,9,7,6,6,9,6,8,5,9,4,2,8,6,1,1,7,1,9};
    int connect[9][2] ={ {0,2}, {2,5}, {2,3},{0,5},{ 0,3}, {1,3},{1,2},{0,1},{3,5}};
    int path[9] = {1,2,4,5,6,7,8,9,10};
    for(int i = 0; i < n; ++i){
        for(int j =0; j < n; ++j){
            edge[i][j] = 0;
        }
    }
    for(int i = 0; i < 9; ++i){
        if(connect)
        edge[connect[i][0]][connect[i][1]] = path[i];
        // edge[connect[i][1]][connect[i][0]] = path[i];
    }

    int parent[n];
    for(int i = 0; i < n; ++i){
        parent[i] = i;
    }
    vector<pair<int,pair<int,int>>> graph;
    for(int i = 0; i < n; ++i){
        for(int j = 0;j < n; ++j){
            if(edge[i][j]){
                graph.push_back(make_pair(edge[i][j], make_pair(i,j)));
            }
        }
    }
    Kruskal(graph, parent,edge);
    

    return 0;
}