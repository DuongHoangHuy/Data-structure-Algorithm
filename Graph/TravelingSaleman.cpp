#include <iostream>
#include <vector>
using namespace std;

#define vertex 8
int root = 1;
int minLength = 99999999;
vector<int> cheapestPath;

void TSM(int begin,int edge[vertex+1][vertex+1], bool vtx[], vector<int> &path, int sum){
    if(begin == root && path.size() == vertex){
        if(sum < minLength){
            cheapestPath = path;
            minLength = sum;
            for(int i = 0; i < cheapestPath.size(); ++i){
                cout << cheapestPath[i] << " ";
            }
            cout << minLength<<endl;
        }
    }else for(int i = 1; i <= vertex; ++i){
        if(edge[begin][i] && vtx[i]){
            // cout << path.size()<<" ";
            vtx[i] = false;
            path.push_back(i);
            int tmp = sum + edge[begin][i];
            TSM(i, edge, vtx, path, tmp);
            vtx[i] = true;
            path.pop_back();
        }
    }
}

int main(){ 
    int edge[vertex+1][vertex+1]={
                                //0  1  2  3  4  5  6  7  8  
                                 {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },//0
                                 {0 ,0 ,50,75,12,10,46,0 ,65},//1
                                 {0 ,50,0 ,5 ,7 ,0 ,0 ,0 ,0 },//2
                                 {0 ,75,5 ,0 ,49,0 ,0 ,35,17},//3
                                 {0 ,12,7 ,49,0 ,27,19,43,80},//4
                                 {0 ,10,0 ,0 ,27,0 ,60,0 ,54},//5
                                 {0 ,46,0 ,0 ,19,60,0 ,0 ,22},//6
                                 {0 ,0 ,0 ,35,43,0 ,0 ,0 ,3 },//7
                                 {0 ,65,0 ,17,80,54,22,3 ,0 } //8
                                };
    bool vtx[vertex+1];
    for(int i = 0; i <= vertex; ++i){
        vtx[i] = true;
    }
    vector<int> path;
    TSM(root, edge, vtx, path, 0);
    return 0;
}