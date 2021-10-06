#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int findPivot(vector<int> a){
    int l = 0;
    int r = a.size()-1;
    int mid = -1;
    while(a[l] > a[r]){
        mid = (l+r)/2;
        if(a[mid] > a[r]) l = mid+1;
        else r = mid;
    }
    return mid;
}

int binarySearch(vector<int> a, int l, int r, int target){
    while(a[l] < a[r]){
        int mid = (l+r)/2;
        if(target <= a[mid]) r = mid;
        else l = mid+1;
    }
    if(a[l] == target) return l;
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivot = findPivot(nums);
    int l,r;
    if(pivot == -1){
        l = 0;
        r = nums.size()-1;
    }else if(target <= nums[pivot] && target >= nums[0]){
        l = 0;
        r = pivot;
    }else{
        l = pivot+1;
        r = nums.size()-1;
    }
    return binarySearch(nums, l, r, target);
}

void dfs(vector<vector<int>> &matrix, int start, int end, bool &find, vector<bool> &vtx){
    if(start == end){
        find = true;
        return;
    }
    vtx[start] = false;
    for(int i = 0; i < matrix[start].size(); ++i){
        if(vtx[matrix[start][i]]){
            dfs(matrix, matrix[start][i], end, find, vtx);
        }
    }
}
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> matrix(n);
    for(int i = 0; i < edges.size(); ++i){
        matrix[edges[i][0]].push_back(edges[i][1]);
        matrix[edges[i][1]].push_back(edges[i][0]);
    }
    bool find = false;
    vector<bool> vtx (n, true);
    dfs(matrix, start, end, find, vtx);
    return find;
}


int main(){
    vector<vector<int>> a =  {{0,1}, {1,2}, {2,0},{2,3}, {1,4}, {4,5}};
    cout << validPath(6, a, 0, 4);
    return 0;
}