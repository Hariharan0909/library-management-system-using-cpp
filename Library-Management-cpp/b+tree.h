#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int admissionNumber;
};


struct Book {
    string author;
    int bookNumber;
    string bookName;
};


template<typename T>
struct BPlusTreeNode {
    vector<T> keys;
    vector<BPlusTreeNode*> children;
    bool isLeaf;
};


template<typename T>
class BPlusTree {
private:
    BPlusTreeNode<T>* root;
    int degree;

public:
    BPlusTree(int degree) {
        this->degree = degree;
        root = nullptr;
    }

   
    BPlusTreeNode<T>* search(T key);

    
    void insert(T key);


    void remove(T key);

  
    void print();

private:

    void printRecursive(BPlusTreeNode<T>* node);
};


template<typename T>
BPlusTreeNode<T>* BPlusTree<T>::search(T key) {
    BPlusTreeNode<T>* current = root;
    while (current) {
        int i = 0;
        while (i < current->keys.size() && key > current->keys[i])
            ++i;
        if (i < current->keys.size() && key == current->keys[i])
            return current;
        if (current->isLeaf)
            return nullptr;
        current = current->children[i];
    }
    return nullptr;
}


template<typename T>
void BPlusTree<T>::insert(T key) {
    if (!root) {
        root = new BPlusTreeNode<T>;
        root->keys.push_back(key);
        root->isLeaf = true;
        return;
    }
    
}

template<typename T>
void BPlusTree<T>::remove(T key) {
    if (!root) {
        cout << "Tree is empty. Cannot delete." << endl;
        return;
    }

    // Implement deletion logic
    // Note: Deletion in B+ tree is more complex, involving merging and redistributing keys from sibling nodes.
    // You'll need to consider cases like deleting from leaf nodes, internal nodes, handling underflow, etc.
}


template<typename T>
void BPlusTree<T>::print() {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }
    cout << "B+ Tree:" << endl;
    printRecursive(root);
}


template<typename T>
void BPlusTree<T>::printRecursive(BPlusTreeNode<T>* node) {
    if (node->isLeaf) {
        for (int i = 0; i < node->keys.size(); ++i)
            cout << node->keys[i] << " ";
        cout << "| ";
    } else {
        int i;
        for (i = 0; i < node->keys.size(); ++i) {
            printRecursive(node->children[i]);
            cout << node->keys[i] << " ";
        }
        printRecursive(node->children[i]);
    }
}

#endif /* BPLUSTREE_H */
