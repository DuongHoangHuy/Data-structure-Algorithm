#include<iostream>
using namespace std;
// Big O notation : n.log(n)
// To merge 2 array: m1+m2 -> n     
void merge(int a[], int l, int m, int r){
    //Chia mang lớn thành hai mảng nhỏ:
    int i, j, k; // k là vị trí trong mảng kết quả
    int n1 = m -l+1; // Số phần tử mảng con bên trái
    int n2 = r-m;// bên phải

    //Đưa vào 2 mảng con:
    int L[1001], R[1001];
    for(i = 0; i < n1; ++i){
        L[i] = a[l+i];
    }
    for(j = 0; j < n2; ++j){
        R[j] = a[m+j+1];
    }
    
    i = 0;
    j = 0;
    k = l; 

    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            a[k] = L[i];
            ++i;
        }else{
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    while(i < n1){
        a[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2){
        a[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int mid = l +(r-l)/2;
        mergeSort(a, l, mid);
        mergeSort(a,mid+1, r);
        merge(a,l, mid,r);

    }
}

int main(){
    int n;
    cin >> n;
    int a[10000];
    for(int i =0; i < n; ++i){
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
    for(int i =0; i < n; ++i){
        cout << a[i] <<" ";
    }
    return 0;
}





