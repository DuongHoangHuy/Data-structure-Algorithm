#include <iostream>
using namespace std;

struct Node{
    int dataLeft=0;
    int dataRight=0;
    Node* left;
    Node* middle;
    Node* right;
};

// Check leaf node
bool isLeafNode(Node* root){
    if(!root->left && !root->middle && !root->right){
        return true;
    }else{
        return false;
    }
}

// create new node
Node* createNode(int data, Node* left, Node* middle, Node* right){
    Node* newNode = new Node;
    newNode->dataLeft = data;
    newNode->left = left;
    newNode->middle = middle;
    newNode->right = right;
    return newNode;
}

// add node
Node* add(Node* root, Node* newNode){
    if(root->dataRight == 0){
        if(root->dataLeft < newNode->dataLeft){
            root->dataRight = newNode->dataLeft;
            root->middle = newNode->left;
            root->right = newNode->middle;
        }else{
            root->dataRight = root->dataLeft;
            root->dataLeft = newNode->dataLeft;
            root->right = root->middle;
            root->middle = newNode->middle;
            root->left = newNode->left;
        }
        return root;
    }else{
        //add to  the left
        if(newNode->dataLeft < root->dataLeft){
            Node* pNew = createNode(root->dataLeft, newNode, root, nullptr);
            root->left = root->middle;
            root->middle = root->right;
            root->right = nullptr;
            root->dataLeft = root->dataRight;   root->dataRight=0;
            return pNew;
        //add to the middle
        }else if(newNode->dataLeft < root->dataRight){
            Node* pNew= createNode(root->dataRight, newNode->middle, root->right, nullptr);
            //root->middle = newNode->left;
            root->right = nullptr;
            newNode->left = root;   newNode->middle = pNew;
            root->dataRight=0;
            return newNode;
        //add to the right
        }else{
            Node* pNew = createNode(root->dataRight, root, newNode, nullptr);
            root->right = nullptr;
            root->dataRight=0;
            return pNew;
        }
    }
}

Node* insertNode(Node* root, int data){
    //If root is null:
    if(!root){
        root = createNode(data, nullptr,nullptr,nullptr);
        return root;
    }
    //Remove dupplicated:
    if(data == root->dataLeft || data == root->dataRight){
        return root;
    }
    
    //Insert at LEAF NODE:
    if(isLeafNode(root)){
        Node* newNode = createNode(data, nullptr,nullptr,nullptr);
        Node* finalNode = add(root, newNode);
        return finalNode;
    }
    
    //Find to the LEFT:
    if(data < root->dataLeft){
        Node* newNode = insertNode(root->left, data);
        if(root->left == newNode){
            return root;
        }else{
            return add(root, newNode);
        }
    //Find to the middle    
    }else if(root->dataRight == 0 || data < root->dataRight){
        Node* newNode = insertNode(root->middle, data);
        if(root->middle == newNode){
            return root;
        }else{
            return add(root, newNode);
        }
    //Find to the right
    }else{
        Node* newNode = insertNode(root->right, data);
         if(root->right == newNode){
            return root;
        }else{
            return add(root, newNode);
        }
    }
}

//Print
void printTree(Node* root){
    if(root){
        printTree(root->left);
        cout << root->dataLeft <<" ";
        printTree(root->middle);
        cout << root->dataRight <<" ";
        printTree(root->right);
    }
}

int main(){
    int t;
    cin >> t;
    Node* root = nullptr;
    while(t){
        root = insertNode(root, t);
        cin >> t;
    }
    printTree(root);
}