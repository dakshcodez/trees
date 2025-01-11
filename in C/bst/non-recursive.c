#include<stdio.h>
#include<stdlib.h>

struct btreenode{
    int val;
    struct btreenode* left;
    struct btreenode* right;
};

struct btreenode* createNewNode(int val){
    struct btreenode* newNode = (struct btreenode*)malloc(sizeof(struct btreenode));
    newNode -> left = newNode -> right = NULL;
    newNode -> val = val;
}

void insertWithoutRecursion(struct btreenode** root, int val){
    struct btreenode* newNode = createNewNode(val);
    if (*root == NULL){
        *root = newNode;
        return;
    }
    struct btreenode* parent = NULL;
    struct btreenode* child = *root;
    while (child != NULL){
        parent = child;
        if (val < child->val){
            child = child->left;
            if (child == NULL){
                parent->left = newNode;
            }
        }else{
            child = child->right;
            if (child == NULL){
                parent->right= newNode;
            }
        }
    }
}

// void inorderTraversal(struct btreenode *root) {
//     if(root != NULL) {
//         inorderTraversal(root->left);
//         printf("%d ", root->val);
//         inorderTraversal(root->right);
//     }
// }

// the below functions make use of stacks 

void inorderTraversalWithoutRecursion(){

}

void preorderTraversalWithoutRecursion(){

}

void inorderTraversalWithoutRecursion(){

}

int main(){
    struct btreenode* root = NULL;
    insertWithoutRecursion(&root,10);
    insertWithoutRecursion(&root,1);
    insertWithoutRecursion(&root,20);
    insertWithoutRecursion(&root,15);
    insertWithoutRecursion(&root,2);
    //inorderTraversal(root);
    return 0;
}