#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random> //std::random_device
#include <Windows.h>
#include "DoHoa.h"
using namespace std;

//------------------GLOBAL VARIABLE--------------------------------
#define width 101
#define length 31
#define Up 0
#define Right 1
#define Down 2
#define Left 3

char Grid[width*length];
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};
//------------------FUNCTION---------------------------------------
// Khởi tạo lưới
void initialGrid(){
    for(int i = 0; i < width*length; ++i){
        Grid[i] = '#';
    }
}
// Tọa độ hóa 
int coorToIndex(int x, int y){
    return (y*width + x);
}

//Check có nằm trong lưới hay không ?
bool isBound(int x, int y){
    if(x < 0 || x >= width) return false;
    if(y < 0 || y >= length) return false;
    return true;

}

//Di chuyển theo tọa 
void Visit(int x, int y){
    Grid[coorToIndex(x,y)] = ' ';

    // Create the direction and shuffle them:
    int direct[4] = {Up, Right, Down, Left};
    for(int i =0; i < 4; ++i){
        int r = rand() & 3;
        int tmp = direct[r];
        direct[r] = direct[i];
        direct[i] = tmp; 
    }

    // Create the moving vector
    for(int i = 0; i < 4; ++i){
        int vecx = 0, vecy = 0;
        switch(direct[i]){
            case Up: vecy = -1; break;
            case Right: vecx = 1; break;
            case Down: vecy = 1; break;
            case Left: vecx = -1; break;
        }

        int x1 = x+vecx*2, y1 = y+vecy*2;
        if(isBound(x1,y1) && Grid[coorToIndex(x1,y1)] == '#'){
            Grid[coorToIndex(x+vecx, y+vecy)] = ' ';
            Visit(x1, y1);
        }
    }
}

//Xuất maze
void printGrid(){
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < width; ++j){
            if(Grid[coorToIndex(j, i)] == '#'){
                textcolor(14);
                cout << char(219);
            }else if(Grid[coorToIndex(j, i)] == '.'){
                textcolor(10);
                cout <<Grid[coorToIndex(j, i)];
            }else{
                cout <<Grid[coorToIndex(j, i)];
            }
        }
        cout <<endl;
    }
}

void findPath(int x, int y){
    if(x == (width - 2) && y == (length -2)){
        Grid[coorToIndex(x, y)] = '.';
        printGrid();
    }else for(int i = 0; i < 4; ++i){
        if(Grid[coorToIndex(x+X[i], y+Y[i])] == ' '){
            Grid[coorToIndex(x+X[i], y+Y[i])] = '.';
            findPath(x+X[i], y+Y[i]);
            Grid[coorToIndex(x+X[i], y+Y[i])] = ' ';
        }
    }
}
//------------------------------FIND PATH ----------------------------------------------
int main()
{
    // Starting point and top-level control.
    srand( time(0) ); // seed random number generator.
    initialGrid();
    Visit(1,1);
    findPath(1,1);
    system("pause");
    return 0;
}