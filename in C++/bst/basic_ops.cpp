#include<iostream>

using namespace std;

class BinarySearchTree {
    private:
        struct TreeNode {
            TreeNode* left;
            int val;
            TreeNode* right;

            TreeNode(int value): val(value), left(nullptr), right(nullptr) {}
        };
        TreeNode* root;
    
    public:
        BinarySearchTree(): root(nullptr) {}

        
};
