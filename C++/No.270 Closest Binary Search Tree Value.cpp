#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        this->target = target;
        ans = root->val;
        recursive_helper(root);
        return ans;
    }
    double target;
    int ans;
    void recursive_helper(TreeNode* n) {
        if (n == nullptr) return;
        if (n->val > target) {
            if (n->val - target < abs(ans - target)) ans = n->val;
            recursive_helper(n->left);
        }
        else if (n->val < target) {
            if (target - n->val < abs(ans - target)) ans = n->val;
            recursive_helper(n->right);
        }
        else ans = n->val;
    }
};