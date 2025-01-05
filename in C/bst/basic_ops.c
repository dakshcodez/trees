#include<stdio.h>
#include<stdlib.h>

struct btreenode{
    struct btreenode *left, *right;
    int val;
};

struct btreenode* createNewNode(int val){
    struct btreenode* newNode = (struct btreenode*)malloc(sizeof(struct btreenode));
    newNode -> left = newNode -> right = NULL;
    newNode -> val = val;
}

void insertWithoutRecursion(struct btreenode** root, int val){
    if (*root == NULL){
        *root = createNewNode(val);
        return;
    }
    struct btreenode* child = *root;
    struct btreenode* parent = NULL;
    struct btreenode* newNode = createNewNode(val);
    while (child != NULL){
        parent = child;
        if (val >= child -> val){
            child = child -> right;
        } else {
            child = child -> left;
        }
    }
    if (val < parent -> val){
        parent -> left = newNode;
    } else {
        parent -> right = newNode;
    }
}

void insertWithRecursion(struct btreenode** root, int val){
    if (*root == NULL){
        *root = createNewNode(val);
        return;
    } else {
        if (val < (*root) -> val){
            insertWithRecursion(&((*root) -> left), val);
        } else {
            insertWithRecursion(&((*root) -> right), val);
        }
    }
}

void inOrderWithRecursion(struct btreenode* root){
    if (root != NULL){
        inOrderWithRecursion(root -> left);
        printf("%d\t", root -> val);
        inOrderWithRecursion(root -> right);
    }
}

void preOrderWithRecursion(struct btreenode* root){
    if (root != NULL){
        printf("%d\t",root -> val);
        preOrderWithRecursion(root -> left);
        preOrderWithRecursion(root -> right);
    }
}

int main(){
    struct btreenode* root = NULL;
    insertWithRecursion(&root,55);
    insertWithRecursion(&root,25);
    insertWithRecursion(&root,75);
    insertWithRecursion(&root,35);
    insertWithRecursion(&root,15);
    insertWithRecursion(&root,5);

    printf("Inorder traversal: ");
    inOrderWithRecursion(root);
    printf("\n");

    printf("Preorder traversal: ");
    preOrderWithRecursion(root);
    printf("\n");

    return 0;
}