#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        vector<TreeNode *> tree;
        tree.push_back(root);
        while (tree.size() > 0) {
            int levelSize = tree.size();
            for (int i = 0; i < levelSize; i++) {
                if ((tree[i] == NULL && tree[levelSize - i - 1] != NULL) ||
                    (tree[i] != NULL && tree[levelSize - i - 1] == NULL) ||
                    (tree[i] != NULL && tree[levelSize - i - 1] != NULL &&
                     tree[i]->val != tree[levelSize - i - 1]->val))
                    return false;
                if (tree[i] != NULL) {
                    tree.push_back(tree[i]->left);
                    tree.push_back(tree[i]->right);
                }
            }
            tree.erase(tree.begin(), tree.begin() + levelSize);
        }
        return true;
    }
};

int main() {
    TreeNode testTree1_Node1 = TreeNode(1);
    TreeNode testTree1_Node2 = TreeNode(2);
    TreeNode testTree1_Node3 = TreeNode(2);
    TreeNode testTree1_Node4 = TreeNode(3);
    TreeNode testTree1_Node5 = TreeNode(4);
    TreeNode testTree1_Node6 = TreeNode(4);
    TreeNode testTree1_Node7 = TreeNode(3);
    testTree1_Node1.left = &testTree1_Node2;
    testTree1_Node1.right = &testTree1_Node3;
    testTree1_Node2.left = &testTree1_Node4;
    testTree1_Node2.right = &testTree1_Node5;
    testTree1_Node3.left = &testTree1_Node6;
    testTree1_Node3.right = &testTree1_Node7;
    Solution solution;
    if (solution.isSymmetric(&testTree1_Node1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
