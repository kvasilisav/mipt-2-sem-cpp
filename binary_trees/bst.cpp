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

class BST {
public:
    TreeNode* root;
    BST() {
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

    TreeNode* insert(TreeNode* r, TreeNode* new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            return r;
        }

        if (new_node->value < r->value)
        {
            r->left = insert(r->left, new_node);
        }
        else if (new_node->value > r->value)
        {
            r->right = insert(r->right, new_node);
        }
        else
        {
            return r;
        }
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
    for (int n = 0; n < 10; n++) {
        cout << n << endl;
        auto start = std::chrono::steady_clock::now();
        BST obj;
        int val;
        for (int k = 0; k < n; k++) {
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
    cout << "ready";
    return 0;
}
