//mid = l + (r-l)*(x-a[l])/(a[r]-a[l])
// Tỉ số: (x-a[l])/(a[r]-a[l]) ước lượng vị trí của x trong khoảng (l,r)
// Độ phức tạp: Ο(log (log n))#include <iostream>
// Công thức có thể ddauw ra index dự đoán năm ngoài khoảng or mẫu số = 0
#include <iostream>
#include <Windows.h>
using namespace std;

int interpolationSearch(int a[], int n, int x){
    int l = 0, r = n-1;
    while(l < r && x >= a[l] && x <= a[r]){
        int mid = l + (r-l)*(x-a[l])/(a[r]-a[l]);
        if(x < a[mid]) r = mid-1;
        else if(x > a[mid]) l = mid+ 1;
        else{
            if(mid > 0 && a[mid-1] == x) r = mid-1;
            else return mid;
        }
    }
    return -1;
}

int main(){
    int n, x;
    int a[1001];
    cin >>n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] ;
    }
    cin >> x;
    cout << interpolationSearch(a, n, x);
    return 0;
}