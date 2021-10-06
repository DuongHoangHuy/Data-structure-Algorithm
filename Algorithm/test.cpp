#include <iostream>
#include <math.h>
using namespace std;

int numTrees(int n) {
    int total = pow(2, n-1);
    if(n-3 >= 0){
        if(n % 2 != 0) total += pow(2, n-3);
        if(n!=3) total += pow(2,n-2)*ceil((n-2)/2.0);
    }    
    return total;
}

int main(){
    int a = 9;
    cout << a++ + a++ - --a;
    return 0;
}