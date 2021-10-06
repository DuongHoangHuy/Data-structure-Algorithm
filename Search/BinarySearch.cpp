#include <iostream>
#include <vector>
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

// 2 side binary search
int binarySearch2(vector<int> nums, int target, bool bound){
    //true for right, else left
    int l = 0;
    int r = nums.size()-1;
    while(l < r){
        if(bound){
            int mid = (l+r)/2; // for right
            if(target <= nums[mid]) r = mid;
            else l = mid+1;
        }else{
            int mid = (l+r)/2+1; // for left
            if(target >= nums[mid]) l = mid;
            else r = mid-1;
        }
    }
    if(nums[l] != target) return -1;
    else return l;
}

int main(){
    int n, x;
    int a[100001];
    cin >>n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] ;
    }
    cin >> x;
    cout << binarySearch(a, 0, n-1, x);
    return 0;
}