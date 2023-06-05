#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
    string val;
    string cityName;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& x) : val(x), left(nullptr), right(nullptr) {}
};

void ýnsert(TreeNode*& root, const string& value) {

    if (root == nullptr)  // eger kök bossa 
    {
        root = new TreeNode(value);
        return;
    }
    if (value < root->val) // eger kökün degeri degerden buyukse kökün soluna ekle.
    {
        ýnsert(root->left, value);
    }
    else if (value > root->val)  // eger kökün degeri degerden kucukse kökün sagýna ekle.
    {
        ýnsert(root->right, value);
    }
}

void display(TreeNode* root, const string& prefix = "") {
    if (!root) {
        return;
    }

    cout << prefix;
    cout << "|--" << " " << root->val << " " << endl;

    display(root->left, prefix + "|   ");
    display(root->right, prefix + "|   ");
}

int treeDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = treeDepth(root->left);
    int rightHeight = treeDepth(root->right);

    if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

TreeNode* search(TreeNode* root, const string& value) {
    if (root == nullptr || value == root->val) {
        return root;
    }
    else if (value > root->val) {
        if (root->right != NULL)
            return search(root->right, value);
        else
            return NULL;
    }
    else {
        if (root->right != NULL)
            return search(root->left, value);
        else
            return NULL;
    }
}

int getLevel(TreeNode* root, const string& value, int level) {
    if (!root) {
        return -1;
    }

    if (root->val == value) {
        return level;
    }

    int leftLevel = getLevel(root->left, value, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }

    int rightLevel = getLevel(root->right, value, level + 1);
    return rightLevel;
}

void preorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
