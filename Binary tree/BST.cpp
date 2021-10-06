#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
//Insert
Node* insertTree(Node* cur, int x){
    if(!cur){
        cur = new Node;
        cur->data = x;
        cur->left = nullptr;
        cur->right = nullptr;   
    }else{
        if(cur->data > x) cur->left = insertTree(cur->left, x);
        else cur->right = insertTree(cur->right, x);   
    }
    return cur;
    
}
//Print:
void printTree(Node* root){
    if(root){
        printTree(root->left);
        cout << root->data <<" ";
        printTree(root->right);
    }
}
//Delete:
void deleteTree(Node* &root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
//Search:
Node* search(Node* root, int x){
    if(!root || root->data == x) return root;
    if(x <= root->data) return search(root->left,x);
    else return search(root->right, x);
}
//print leaf:
void printLeaf(Node* root){
    if(!root) return;
    if(!root->left && !root->right) cout << root->data<<" ";
    printLeaf(root->left);
    printLeaf(root->right);
}
//______________________HOME WORK______________________
//print out all the root to X
// void printXtoRoot(Node* root, vector<int> &path, int x){
//     if(!root) return;
//     if(root->data == x){
//         path.push_back(x);
//         for(int i = 0; i < path.size(); ++i) cout << path[i] <<" ";
//     }else{
//         path.push_back(root->data);
//         if(x < root->data) printXtoRoot(root->left, path, x);
//         else printXtoRoot(root->right, path, x);
//         path.pop_back();
//     }
// }

//________________________PRINT NODES AT LEVEL K_______________________________
void printAtLevelK(Node*  root, int k, int cur){
    if(!root) return;
    if(cur == k){
        cout << root->data <<" ";
    }else{
        printAtLevelK(root->left, k, cur+1);
        printAtLevelK(root->right, k, cur+1);
    }
}

// ____________________________PATH X TO ROOT______________________________
bool pathXtoRoot(Node* root, vector<int> &path, int x){
    if(!root) return false;
    path.push_back(root->data);
    if(root->data == x) return true;
    if(pathXtoRoot(root->left, path, x) ||  pathXtoRoot(root->right, path, x)){
        return true;
    }
    path.pop_back();
    return false;
}
//_______________________________LOWEST ANCESTOR _________________________________
int lowestAncestor1(Node* root, int x, int y){
    vector<int> path1, path2;
    if(!pathXtoRoot(root, path1, x) || !pathXtoRoot(root, path2, y)) return -1;
    for(int i = 0; i < path1.size(); ++i){
        if(path1[i] != path2[i]) return path1[i-1];
    }
}
//2.
Node* lowestAncestor2(Node* root, int x, int y){
    if(!root) return nullptr;
    if(root->data == x || root->data == y) return root;
    //Find the x, y
    Node* left_LA = lowestAncestor2(root->left, x, y);
    Node* right_LA = lowestAncestor2(root->right, x, y);

    //If x, y co-exist -> find it(there is so many couple )
    // ex: 0 1 -> 1 , 1 1 -> 1, 0 0 ->0
    if(left_LA && right_LA) return root;
    // Use for the next step
    if(left_LA) return left_LA;
    else return right_LA;

}
//_______________________________________________________
//Count leaf:
int countLeaf(Node* root){
    if(!root) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    return countLeaf(root->left)+countLeaf(root->right);
}
//________________________________AVL____________________________
//Tree level:
int treeLevel(Node* root){
    if(!root) return -1;
    return 1 + max(treeLevel(root->left), treeLevel(root->right));
}
// AVL tree:
bool AVLTree(Node* root){
    if(abs(treeLevel(root->left)-treeLevel(root->right)) >1) return false;
    return true;
}

bool checkFullAVL(Node* root){
    if(!root) return true;
    return (abs(treeLevel(root->left)-treeLevel(root->right)) <= 1) && checkFullAVL(root->left) && checkFullAVL(root->right);
}
//fix to  avl tree:
Node* turnRight(Node* a){
    Node* b = a->left;
    Node* d = b->right;
    a->left = d;
    b->right = a;
    return b;
}

Node* turnLeft(Node* a){
    Node* b = a->right;
    Node* d = b->left;
    a->right = d;
    b->left = a;
    return b;
}
Node* updateAVLtree(Node* root){
    if(!AVLTree(root)){
        if(treeLevel(root->left) > treeLevel(root->right)){
            Node* a = root->left;
            if(treeLevel(a->left) >= treeLevel(a->right)){
                root = turnRight(root);
            }else{
                root->left = turnLeft(a);
                root = turnRight(root);
            }
        }else{
            Node* a = root->right;
            if(treeLevel(a->right) >= treeLevel(a->left)){
                root = turnLeft(root);
            }else{
                root->right = turnRight(a);
                root = turnLeft(root);
            }
        }
    }
    if(root->left) root->left = updateAVLtree(root->left);
    if(root->right) root->right = updateAVLtree(root->right);
    if(!AVLTree(root)) root = updateAVLtree(root);
    return root;
}

//______________________________DELETE NODE__________________________________
Node* deleteNode(Node* root, int x){
    //3 TH:
    if(!root) return nullptr;
    if(x < root->data) root->left = deleteNode(root->left, x);
    else if(x > root->data) root->right = deleteNode(root->right, x);
    else{
        // case 1: leaf:
        if(!root->left && !root->right){
            delete root;
            root = nullptr;
        //case 2: 2 nodes
        }else if(root->left && root->right){
            Node* cur = root->right;
            while(cur->left || cur->right){
                if(cur->left){
                    cur = cur->left;
                }else{
                    cur = cur->right;
                }
            }
            root->data = cur->data;
            root->right = deleteNode(root->right, cur->data);
        }else if(root->left == nullptr){
            Node* tmp = root;
            root = root->right;
            delete tmp;
        }else if(root->right == nullptr){
            Node* tmp = root;
            root = root->left;
            delete tmp;
        }
    }
    return root;
}

//__________________CHECK SUB TREE____________________
bool checkSubTree(Node* root, Node* x){
    if(!root && !x) return true;
    if(!root || !x) return false;
    return (root->data == x->data) && checkSubTree(root->left,x->left) && checkSubTree(root->right, x->right);
}

bool isSubTree(Node* root, Node* x){
    if(checkSubTree(root, x)) return true;
    if(x->data < root->data) return isSubTree(root->left, x);
    else return isSubTree(root->right, x);
}

//__________________CHECK SUB SET_______________________________
bool checkSubset(Node* root, Node* x){
    if(!x) return true; //Dau hieu end cua x
    if(!root) return false;
    return root->data == x->data && checkSubset(root->left,x->left) && checkSubset(root->right, x->right);
}

bool isSubset(Node* root, Node* x){
    if(!x) return true;
    if(!root) return false;
    if(checkSubset(root, x)) return true;
    if(x->data < root->data) return isSubset(root->left, x);
    else return isSubset(root->right,x);
}

//_______________IS SYMETRIC____________
bool isSymetric(Node* root){
    
}

void print(Node* root){
    queue<Node*> a;
    a.push(root);
    while(!a.empty()){
        cout << a.front()->data<<" ";
        if(a.front()->left) a.push(a.front()->left);
        if(a.front()->right) a.push(a.front()->right);
        a.pop();
    }
}
int main(){
    Node* root = nullptr;
    int t;
    cout <<"Input the data(0 to exit:) ";
    cin >> t;
    while(t){
        root = insertTree(root,t);
        cout <<"Input the data(0 to exit:) ";
        cin >> t;
    }
    Node* x = nullptr;
    cout <<"Input the data(0 to exit:) ";
    cin >> t;
    while(t){
        x = insertTree(x,t);
        cout <<"Input the data(0 to exit:) ";
        cin >> t;
    }
    cout << isSubTree(root, x);
    deleteTree(root);
    return 0;
}
//          50
//      40      70
//    35   45   65 75
//  20  37     68 
// 12 22  39

//24 9 3 15 1 4 6 45 32 98 55 69