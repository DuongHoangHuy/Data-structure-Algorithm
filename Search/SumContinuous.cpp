#include <iostream>
using namespace std;

//Loop
int binarySearch(int a[], int l, int r, int x){ 
    while(l < r){
        int mid = (l+r)/2;
        if(a[mid] >= x) r = mid; //Huong ve trai
        else l = mid+1; // Huong ve phai
    }
    if(a[r] == x) return r;
    else return -1;
}

void sumContinuous(int a[], int n, int s){
    int sum[100001];
    sum[0] = a[0];
    for(int i = 1; i < n; ++i){
        sum[i] = a[i] + sum[i-1];
    }
    // Trường hợp tổng tính từ đầu dãy:
    for(int i = 0; i < n; ++i){
        if(sum[i] == s){
            for(int j = 0; j <= i; ++j){
                cout << a[j] <<" ";
            }
            return;
        }
    }
    //Trường hợp ko bắt đầu từ đầu dãy:
    int end = -1, beg = -1;
    for(int i = 0; i < n; ++i){
        int tmp = binarySearch(sum, i, n-1, sum[i] + s);
        if(tmp != -1){
            end = tmp;
            beg = i;
            break;
        }
    }

    if(end == -1){
        cout << -1;
        return;
    }

    for(int i = beg+1; i <= end; ++i){
        cout << a[i] <<" ";
    }
}

int main(){
    int n, s;
    int a[100001];
    cin >>n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] ;
    }
    cin >> s;
    sumContinuous(a, n, s);
    return 0;
}