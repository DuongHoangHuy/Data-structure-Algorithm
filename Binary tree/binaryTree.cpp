#include<iostream>
#include<cmath>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};
//--------------------------------INSERT------------------------------------------
Node* insertNode(Node* t, int x){
    if(t == nullptr){
        Node* pTmp = new Node;
        pTmp->data = x;
        pTmp->left = nullptr;
        pTmp->right =nullptr;
    }else{
        if(x < t->data){
            t->left = insertNode(t->left, x);
        }else{
            t->right = insertNode(t->right, x);
        }
        return t;
    }
}
//-------------------------------PRINT----------------------------------------------
void printTree(Node *t){
	if (t != NULL){
		printTree(t->left);
		cout << t->data << " " ;
		printTree(t->right);
	}
}
//-------------------------------HOW MANY LEAF Node --------------------------------
int countLeaf(Node* t){
	if(!t) return 0;
	if(t->left == nullptr && t->right == nullptr) return 1;
	return countLeaf(t->left)+countLeaf(t->right);
}
// ------------------------------ BẬC CỦA TREE -----------------------------------------
int treelevel(Node* t){
	if(!t) return -1;
	int a = 0, b = 0;
	if(t->left) a =  1 + treelevel(t->left);
	if(t->right) b = 1 + treelevel(t->right);
	return max(a,b);
}
//------------------------------- AVL tree(Adelson, Velski và Landis)----------------------
int treeLevel(Node* t){
	if(!t) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

bool AVLtree(Node* t){
	//if(!t) return true;
	if(abs(treeLevel(t->left)-treeLevel(t->right)) >1) return false;
	return true;
}
//-----------------------------Turn left & turn right ---------------------------------------
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

Node* updateTreeAVL(Node* t){
	//Nếu cầy ko balance: 
	if(!AVLtree(t)){
		//Lệch trái
		if(treeLevel(t->left) > treeLevel(t->right)){
			Node* a = t->left;
			//trái trái 
			if(treeLevel(a->left) >= treeLevel(a->right)){
				t = turnRight(t);
			}else{
			//trái phải
				t->left = turnLeft(a);
				t = turnRight(t);
			}
		//Lệch phải
		} else {
			Node* a = t->right;
			//phải phải 
			if(treeLevel(a->left) <= treeLevel(a->right)){
				t = turnLeft(t);
			}else{
			//phải trái
				t->right = turnRight(a);
				t = turnLeft(t);
			}
		}
	} 
	if(t->left) t->left = updateTreeAVL(t->left);
	if(t->right) t->right = updateTreeAVL(t->right);
	if(!AVLtree(t)) t = updateTreeAVL(t);
	return t;
}
// ---------------------------------Count x ---------------------------------------------
int countNum(Node* t, int num){
	if(!t) return 0;
	if(t->data == num) return 1 + countNum(t->left, num) + countNum(t->right, num);
	if(t->data > num) return countNum(t->left, num);
	return countNum(t->right,num);
}
//----------------------------------DELETE NODE--------------------------------------------
Node* deleteNode(Node* t){
	if(t){
		deleteNode(t->left);
		deleteNode(t->right);
		delete t;
	}
	t = nullptr;
	return t;
}

Node* deleteNodeVal(Node* t, int val){
	if(t){
		if(t->data == val) t = deleteNode(t);
		else{
			if(t->data > val) t->left = deleteNodeVal(t->left, val);
			else t->right = deleteNodeVal(t->right, val);
		}
	}
	return t;
}
int main(){
	int n, x;
	cin >> n;
	Node* t = nullptr;
	for (int i = 0; i < n; i++){
		cin >> x;
		t = insertNode(t, x);
	}
	t = updateTreeAVL(t);
	printTree(t);
	cout << AVLtree(t);
	return 0;
}