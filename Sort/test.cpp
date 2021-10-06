#include<iostream>
#include<string>
#include <vector>
using namespace std;

void shellSort(int n, int a[]){
    for(int gap = n/2; gap != 0; gap /= 2){
        for(int i = gap; i < n; ++i){
            int key = a[i];
            int j = i - gap;
            while(j >= 0 && a[j] > key){
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;
        }
    }
}

int main(){
    int a[10] = {1,43,2324,674,3213124,69867,234,567,12309,456};
    shellSort(10, a);
    for(int i = 0; i < 10; ++i){
        cout << a[i] <<" ";
    }
    return 0;
}