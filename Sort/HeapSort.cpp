#include<iostream>
using namespace std;

//Big O: n.log(n)
// Heap: đống
//Gồm max heap & min heap

// Cách 1: Sử dụng thư viện heap có sẵn
// Cách 2: Tự build
// - độ cao của heap là h
// => chỉ xếp từ 1 -> h-1 (có tất cả 2^h = n phần tử)
// => chỉ chạy từ 0 -> n/2
//Heapify
void heapify(int a[], int n, int i){ // quy luật: cha luôn lớn hơn con 
    int max = i;                    // (2 con cùng 1 cha có thể lớn bé tùy ý)
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[max]) max = l;
    if(r < n && a[r] > a[max]) max = r;
    if(max != i){
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}

//Make a heap from arr
void buildHeap(int a[], int n){ // Using bottom - up
    for(int i = (n/2)+1; i >= 0; --i){
        heapify(a, n, i);
    }
}
//Heap sort
void heapSort(int a[], int n){ //đưa vị trí lớn nhất(root) về cuối
    for(int i = n-1; i >=0; --i){ // sau đó điều chình heap về đúng dạng
        swap(a[i], a[0]);     // !!! : chuyển max về cuối, giảm độ dài -> ko đụng vào cuối max
        heapify(a, i, 0);
    }
}
void printArr(int a[], int n){
    for(int i =0; i < n; ++i){
        cout << a[i] <<" ";
    }
}

int main(){
    int n = 9;
    int a[9] = {5,13,2,25,7,17,20,8,4};
    buildHeap(a, n);
    heapSort(a, n);
    printArr(a, n);
    return 0;
}



