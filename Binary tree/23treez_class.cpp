#include <iostream>
using namespace std;

class _23tree{
public:
    _23tree(){
        root = nullptr;
    }
    void buildTree();
private:
    struct Node{
        string dataLeft;
        string dataRight;
        Node* left = nullptr;
        Node* middle = nullptr;
        Node* right = nullptr;
    };
    Node* root;
    Node* createNode(string data, Node* left, Node* middle, Node* right);//done
    Node* findPlace(Node* root, string data);//
    Node* add(Node* root, Node* pNew);
    bool isLeafNode(Node* root);
};

void _23tree::buildTree(){
    cout <<"CREATING A 2-3 TREE\n";
    cout <<"Input the num(0 to exit):\n";
    string t;
    cin >> t;
    while(t != "0"){
        findPlace(root, t);
    }
}

_23tree::Node*::_23tree::createNode(string data, Node* left, Node* middle, Node* right){
    Node* newNode = new Node;
    newNode->dataLeft = data;
    newNode->left = left;
    newNode->middle = middle;
    newNode->right = right;
    return newNode;
}

bool _23tree::isLeafNode(Node* root){
    if(!root->left && !root->middle && !root->right){
        return true;
    }else{
        return false;
    }
}

//-----------------------ADD--------------------------
_23tree::Node*::_23tree::add(Node* root, Node* pNew){
    //the right slot is empty:
    if(root->dataRight.empty()){
        if(pNew->dataLeft < root->dataLeft){ // < left root
            
        }else{ //swap
            
        }
    }
}

_23tree::Node*::_23tree::findPlace(Node* root, string data){
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
        Node* finalNode = add();
        return finalNode;
    }
    
    //Find to the LEFT:
    if(data < root->dataLeft){
        Node* newNode = findPlace(root->left, data);
        if(root->left == newNode){
            return root;
        }else{
            return newNode;
        }
    //Find to the middle 
    }else if(data <= root->dataRight){
        Node* newNode = findPlace(root->middle, data);
         if(root->left == newNode){
            return root;
        }else{
            return newNode;
        }
    //Find to the right
    }else{
        Node* newNode = findPlace(root->right, data);
         if(root->left == newNode){
            return root;
        }else{
            return newNode;
        }
    }
}



int main(){
    _23tree a;
    return 0;
}