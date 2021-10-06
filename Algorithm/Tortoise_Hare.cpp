#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int tortoise = 0, hare = 0;
    do{
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }while(tortoise != hare);
    int tortoise_fake = 0;
    do{
        tortoise = nums[tortoise];
        tortoise_fake = nums[tortoise_fake];
    }while(tortoise != tortoise_fake);
    return tortoise;

}

int main(){
    vector<int> tmp = {2,5,9,6,9,3,8,9,7,1};
    cout << findDuplicate(tmp);
    return 0;
}