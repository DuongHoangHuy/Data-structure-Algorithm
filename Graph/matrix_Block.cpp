#include <iostream>
#include <queue>
using namespace std;

const int n = 3;
const int x[4] = {0,0,1,-1};
const int y[4] = {1,-1,0,0};
void Matrix(int matrix[n][n], pair<int,int> begin, pair<int,int> end){
    int value[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            value[i][j]=matrix[i][j];
        }
    }
    matrix[begin.first][begin.second] = 1;
    queue<pair<int, int>> list;
    list.push(make_pair(begin.first, begin.second));
    while(!list.empty()){
        pair<int,int> tmp = list.front();
        if(tmp == end) break;
        for(int i = 0; i < 4; ++i){
            int X = tmp.first + x[i];
            int Y = tmp.second +y[i];
            if(X >= 0 && X < n && Y >= 0 && Y < n){
                int path = 1;
                if(value[X][Y]){
                    path = value[X][Y];
                }
                if(matrix[X][Y] == value[X][Y]){
                    matrix[X][Y] = matrix[tmp.first][tmp.second] + path;
                    list.push(make_pair(X, Y));
                }else if(matrix[tmp.first][tmp.second] + path < matrix[X][Y]){
                    matrix[X][Y] = matrix[tmp.first][tmp.second] + path;
                    list.push(make_pair(X, Y));
                }   
            }
        }
        list.pop();
    }
    // Display path:
    int count = matrix[end.first][end.second];
    int find = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }
    pair<int,int> cur = end;
    while(count--){
        if(find) cout << cur.first<<"-"<<cur.second<<endl;
        find = 0;
        for(int i = 0; i < 4; ++i){
            int X = cur.first+x[i];
            int Y = cur.second+y[i];
            if(X >= 0 && X < n && Y >= 0 && Y < n && matrix[X][Y] == count){
                find = 1;
                cur = make_pair(X,Y);
            }
        }
    }
    
}
int main(){
    int matrix[n][n] = {0};
    matrix[0][1] = 5;
    matrix[0][2] = 1;
    matrix[1][0] = 3;
    matrix[1][1] = 7;
    matrix[1][2] = 2;
    matrix[2][0] = 3;
    Matrix(matrix, make_pair(0,0), make_pair(2,2));
    return 0;
}