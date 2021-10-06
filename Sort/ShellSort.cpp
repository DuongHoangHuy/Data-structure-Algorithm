#include<iostream>
using namespace std;

//Base on the insertion sort
// k is interval
void shellSor1t(int a[], int n){
    int k;
    for(k = n/2; k > 0; k /= 2){// cac khoang can xet
        for(int j = k; j < n; ++j){
            for(int pos = j; pos >= 0 && a[pos] < a[pos-k]; pos -= k){
                int tmp = a[pos];
                a[pos] = a[pos-k];
                a[pos-k] = tmp;
            }
        }
    }
}


int shellSort(int arr[], int n){
 	for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                    arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return 0;
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
    shellSort(a, n);
    printArr(a, n);
    return 0;
}








