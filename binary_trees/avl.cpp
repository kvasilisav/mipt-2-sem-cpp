#include<iostream>
#include<random>
#include<chrono>
#define SPACE 10

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class AVLTree {
public:
    TreeNode* root;
    AVLTree() {
        root = NULL;
    }
    bool isTreeEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    // Get Height  
    int height(TreeNode* r) {
        if (r == NULL)
            return -1;
        else {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    // Get Balance factor of node N  
    int getBalanceFactor(TreeNode* n) {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation  
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation  
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode* insert(TreeNode* r, TreeNode* new_node) {
        if (r == NULL) {
            r = new_node;
            return r;
        }

        if (new_node->value < r->value) {
            r->left = insert(r->left, new_node);
        }
        else if (new_node->value > r->value) {
            r->right = insert(r->right, new_node);
        }
        else {
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left Left Case  
        if (bf > 1 && new_node->value < r->left->value)
            return rightRotate(r);

        // Right Right Case  
        if (bf < -1 && new_node->value > r->right->value)
            return leftRotate(r);

        // Left Right Case  
        if (bf > 1 && new_node->value > r->left->value) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Left Case  
        if (bf < -1 && new_node->value < r->right->value) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;

    }

    TreeNode* iterativeSearch(int v) {
        if (root == NULL) {
            return root;
        }
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (v == temp->value) {
                    return temp;
                }
                else if (v < temp->value) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode* recursiveSearch(TreeNode* r, int val) {
        if (r == NULL || r->value == val)
            return r;

        else if (val < r->value)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }
};

int main() {
    for (int n = 0; n < 100; n++) {
        cout << n << "  ";
        auto start = std::chrono::steady_clock::now();
        AVLTree obj;
        int val;
        for (int k = 0; k < 30; k++) {
            TreeNode* new_node = new TreeNode();
            val = rand() % 500;
            new_node->value = val;
            obj.root = obj.insert(obj.root, new_node);
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        cout << elapsed;
        cout << endl;
    }
    return 0;
}
