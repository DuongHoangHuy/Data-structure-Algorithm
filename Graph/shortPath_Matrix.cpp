#include <iostream>
#include <queue>
using namespace std;

const int n = 6;
const int x[4] = {0,0,1,-1};
const int y[4] = {1,-1,0,0};
void Matrix(bool a[n][n], pair<int,int> begin, pair<int,int> end){
    int matrix[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            matrix[i][j] = 0;
        }
    }
    queue<pair<int, int>> list;
    list.push(make_pair(begin.first, begin.second));
    matrix[begin.first][begin.second] = 0;
    while(!list.empty()){
        pair<int,int> tmp = list.front();
        a[tmp.first][tmp.second] = true;
        if(tmp == end) break;
        for(int i = 0; i < 4; ++i){
            int X = tmp.first + x[i];
            int Y = tmp.second +y[i];
            if(X >= 0 && X < n && Y >= 0 && Y < n && !a[X][Y]){
                matrix[X][Y] = matrix[tmp.first][tmp.second]+1;
                list.push(make_pair(X, Y));    
            }
        }
        list.pop();
    }
    // Display path:
    if(!a[end.first][end.second]){
        cout << "Can not find the path";
    }else{
        int num = matrix[end.first][end.second];
        pair<int, int> cur = end;
        while(num != 0){
            --num;
            cout << cur.first<<"-"<<cur.second<<endl;
            for(int i = 0; i < 4; ++i)
            {
                if(matrix[cur.first+x[i]][cur.second+y[i]] == num)
                {
                    cur = make_pair(cur.first+x[i], cur.second+y[i]);
                }
            }
        }
        cout << cur.first<<"-"<<cur.second<<endl;
    }
}
int main(){
    bool matrix[n][n] = {0};
    matrix[0][4] = true;
    matrix[0][5] = true;
    matrix[1][1] = true;
    matrix[1][2] = true;
    matrix[2][0] = true;
    matrix[2][5] = true;
    matrix[3][3] = true;
    matrix[3][5] = true;
    matrix[4][1] = true;
    matrix[5][0] = true;
    matrix[5][4] = true;
    Matrix(matrix, make_pair(0,0), make_pair(5,5));

    return 0;
}