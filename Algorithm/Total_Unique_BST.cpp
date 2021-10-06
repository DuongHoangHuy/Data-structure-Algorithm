#include <iostream>
#include <math.h>
using namespace std;

// Use DP to break down the problem: 
// F(root, n) = G(root-1, n- (root-1))
// G(1) = 1, G(2) = 2
int numTrees(int n) {
    unsigned int total = 0;
    if(n == 1 || n == 0) return 1;
    if(n == 2) return 2;
    for(int i = 1; i <= n; ++i){ // i is root
        total += numTrees(i-1)*numTrees(n-i);
    }
    return total;
}

int main(){
    cout << numTrees(5);
    return 0;
}