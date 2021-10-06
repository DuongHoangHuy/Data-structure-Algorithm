#include<iostream>
using namespace std;

//Big O: log(n)
void quickSort(int a[], int l, int r){
    int pivot = a[(l+r)/2];
    int i = l;
    int j = r;
    while(i < j){
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if(i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            ++i;
            --j;
        }
    }
    // có thể đổi m thành i, j vì i = m+1, j = m-1;
    if(j > l) quickSort(a, l, j); // sort cac phan tu ben trai
    if(i < r) quickSort(a, i, r); // sort cac phan tu ben phai
}

void printArr(int a[], int n){
    for(int i =0; i < n; ++i){
        cout << a[i] <<" ";
    }
}

int main(){
    int n;
    cin >> n;
    int a[100001];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    quickSort(a, 0, n-1);
    printArr(a, n);
    return 0;
}



