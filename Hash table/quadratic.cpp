#include <iostream>
using namespace std;

const int N = 103;
void add(int a[], int x){
    int i = 0;
    int index = (x%N + i*i)%N;
    while(a[index] >= 0){
        ++i;
        index = (x%N + i*i)%N;
    }
    a[index] = x;
}

void remove(int a[], int x){
    int i = 0;
    int index = (x%N + i*i)%N;
    while(a[index] != x){
        ++i;
        index = (x%N + i*i)%N;
    }
    a[index] = -1;
}

//______________________DOUBLE HASING_______________________
//hash 1: (key % prime)%table_size
//hash 2: prime - (key % prime)
// (hash1 + i* hash2)%prime

#define TABLE_SIZE 13
  
// Used in second hash function.
#define PRIME 7
  
class DoubleHash {
    // Pointer to an array containing buckets
    int* hashTable;
    int curr_size;
  
public:
    // function to check if hash table is full
    bool isFull()
    {
  
        // if hash size reaches maximum size
        return (curr_size == TABLE_SIZE);
    }
  
    // function to calculate first hash
    int hash1(int key)
    {
        return (key % TABLE_SIZE);
    }
  
    // function to calculate second hash
    int hash2(int key)
    {
        return (PRIME - (key % PRIME));
    }
  
    DoubleHash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
            hashTable[i] = -1;
    }
  
    // function to insert key into hash table
    void insertHash(int key)
    {
        // if hash table is full
        if (isFull())
            return;
  
        // get index from first hash
        int index = hash1(key);
  
        // if collision occurs
        if (hashTable[index] != -1) {
            // get index2 from second hash
            int index2 = hash2(key);
            int i = 1;
            while (1) {
                // get newIndex
                int newIndex = (index + i * index2) % TABLE_SIZE;
  
                // if no collision occurs, store
                // the key
                if (hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }
  
        // if no collision occurs
        else
            hashTable[index] = key;
        curr_size++;
    }
  
    // function to search key in hash table
    void search(int key)
    {
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key) {
            if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1) {
                cout << key << " does not exist" << endl;
                return;
            }
            i++;
        }
        cout << key << " found" << endl;
    }
  
    // function to display the hash table
    void displayHash()
    {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashTable[i] != -1)
                cout << i << " --> "
                     << hashTable[i] << endl;
            else
                cout << i << endl;
        }
    }
};
  

int main(){

    return 0;
}