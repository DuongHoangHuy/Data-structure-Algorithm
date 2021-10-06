#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBST(TreeNode* root, TreeNode* min, TreeNode* max){
    // left: new max, right: new min
    if(!root) return true;
    if((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

bool isValidBST(TreeNode* root) {
    return isBST(root, nullptr, nullptr);
}


int main(){

    return 0;
}