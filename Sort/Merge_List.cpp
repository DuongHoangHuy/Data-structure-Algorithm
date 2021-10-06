#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target, bool bound){
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

vector<int> searchRange(vector<int>& nums, int target) {
    if(!nums.size()) return {-1,-1};
    int bound1 = binarySearch(nums, target, true);
    if(bound1 == -1) return {-1,-1};
    int bound2 = binarySearch(nums, target, false);
    return {bound1, bound2};
}

int main(){
    vector<int> a = {5,7,7,8,8,10};
    cout << searchRange(a, 6)[0] << searchRange(a, 6)[1];
    return 0;
}