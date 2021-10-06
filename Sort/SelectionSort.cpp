#include <iostream>

using namespace std;

void selectionSort(int a[], int n){
    for(int i = 0;i < n; ++i){
        int min = i;
        for(int j = i+1; j < n; ++j){
            if(a[min] > a[j]){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

int main(){

    return 0;
}