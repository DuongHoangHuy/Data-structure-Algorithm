#include <iostream>
using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    static const int n = 1000003;
    int a[n];
    MyHashSet() { 
        for(int i = 0; i < n; ++i){
            a[i] = -1;
        }
    }
    
    void add(int key) {
        int i = key%n;
        while(a[i] >= 0){
            i = (i+1)%n;
        }
        a[i] = key;
    }
    
    void remove(int key) {
        int i = key%n;
        while(a[i] >= 0){
            if(a[i] == key) {
                a[i] = -1;
                return;
            }
            i = (i+1)%n;
        }   
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = key%n;
        while(a[i] >= 0){
            if(a[i] == key) return true;
            i = (i+1)%n;
        }
        return false;
    }
};

int main(){
    MyHashSet a;
    a.add(2);
    cout << a.contains(2);
    a.remove(2);
    a.remove(2);
    cout << a.contains(2);
    return 0;
}