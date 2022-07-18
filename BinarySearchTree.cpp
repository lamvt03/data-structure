#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

void insertNode(Tree &root, int data);
bool searchNode(Tree &root, int data);
void searchStandFor(Tree &p, Tree &q);
void deleteNode(Tree &root, int data);
void removeTree(Tree &root);
void printTree(Tree &root);
int main(){
    Tree root = NULL;
    insertNode(root, 1);
    insertNode(root, 5);
    insertNode(root, 13);
    insertNode(root, 9);
    insertNode(root, 78);
    insertNode(root, 56);
    insertNode(root, 10);
    printTree(root);
    cout << "\n";

    removeTree(root);

    printTree(root);
    cout << "\n";
    return 0;
}
void printTree(Tree &root){
    if(root != NULL){
        cout << root->data << " ";
        printTree(root->pLeft);
        printTree(root->pRight);
    }
}
void insertNode(Tree &root, int data){
    if(root == NULL){
        root = new Node;
        root->data = data;
        root->pLeft = root->pRight = NULL;
    }
    if(root->data > data)
        insertNode(root->pLeft, data);
    if(root-> data < data)    
        insertNode(root->pRight,data);
}
bool searchNode(Tree &root, int data){
    if(root != NULL){
        if(root->data == data)
            return true;
        else if(root->data > data)
            return searchNode(root->pLeft, data);
        else 
            return searchNode(root->pRight, data);
    }
    return false;
}
void searchStandFor(Tree &p, Tree &q){
    if(q->pRight != NULL)
        return searchStandFor(p, q->pRight);
    else{
        p->data = q->data;
        p = q;
        q = q->pLeft;
    }
}
void deleteNode(Tree &root, int data){
    if(root == NULL)
        return;
    if(root->data > data)
        return deleteNode(root->pLeft, data);
    if(root->data < data)
        return deleteNode(root->pRight, data);
    Node *p = root;
    if(root->pLeft == NULL)
        root = root->pRight;
    else{
        if(root->pRight == NULL)
            root = root->pLeft;
        else{
            searchStandFor(p, p->pLeft);
        }
    }
    delete p;
}
void removeTree(Tree &root){
    while(root != NULL){
        deleteNode(root, root->data);
    }
}