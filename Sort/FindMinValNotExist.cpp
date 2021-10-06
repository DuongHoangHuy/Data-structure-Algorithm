#include <iostream>
using namespace std;

void  quickSort(int a[], int l, int r){
    int pivot = a[(l+r)/2];
    int i = l;
    int j = r;
    while(i < j){
        while(a[i] < pivot) ++i;
        while(a[j] > pivot) --j;
        if(i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            ++i;
            --j; 
        }
    }
    if(j > l) quickSort(a, l, j);
    if(i < r) quickSort(a, i, r);
}

int findMin(int a[], int n){
    quickSort(a, 0, n-1);
    if(a[0] > 0) return 0;
    for(int i = 1; i < n; ++i){
        if(a[i] > a[i-1] + 1) return a[i-1]+1;
    }
    return a[n-1] + 1;
}

int main(){
    int n;
    cin >> n;
    int a[10000];
    for(int i =0; i < n; ++i){
        cin >> a[i];
    }
    cout << findMin(a, n);
    return 0;
}