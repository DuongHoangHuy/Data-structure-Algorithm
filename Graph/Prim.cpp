// eclectricity generator
#include <iostream>
using namespace std;

#define n 9
int Prim(int edge[n][n]){
    bool vtx[n];
    for(int i = 0; i < n; ++i){
        vtx[i] = true;
    }   

    vtx[0] = false;
    int total = 0;
    for(int i = 0 ; i < n-1; ++i){
        int shortest = 20000000, s, f;
        for(int v = 0; v < n; ++v){
            if(!vtx[v]){
                for(int p = 0; p < n; ++p){
                    if(vtx[p] && edge[v][p] && edge[v][p] < shortest){
                        shortest = edge[v][p];
                        f = p;
                        s = v; 
                    }
                }
            }
        }
        vtx[f] = false;
        total += edge[s][f];
        cout <<s<<"->"<<f<<"="<<edge[s][f]<<endl;
    }
    return total;
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
    int connect[28][2]={ {0,14},   {0,7},   {0,4},   {0,1},  {1,4},   {1,2},  {2,5},   {2,6},  {3,6},  {3,10},  {5,8},   {5,9},  {6,9},  {6,10}, {7,11}, {8,11},  {8,12}, {9,10},  {9,13},{10,13},{11,14}, {11,12},{12,15}, {12,13},{13,16}, {13,17},{14,15},{16,17}};
    int path[28] = {9,1,5,6,5,5,3,6,2,4,9,7,6,6,9,6,8,5,9,4,2,8,6,1,1,7,1,9};
    for(int i = 0; i < n; ++i){
        for(int j =0; j < n; ++j){
            edge[i][j] = 0;
        }
    }
    for(int i = 0; i < 28; ++i){
        edge[connect[i][0]][connect[i][1]] = path[i];
        edge[connect[i][1]][connect[i][0]] = path[i];
    }

    cout << Prim(edge)<<endl;
    return 0;
}