#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
  : val(x), left(left), right(right) {}
};

struct Subtree {
  int sum;
  int ct;
  Subtree() : sum(0), ct(0) {}
  Subtree(TreeNode *leaf) : sum(leaf->val), ct(1) {}
};

class Solution {
public:
  double maximumAverageSubtree(TreeNode* root) {
    double max = 0.0f;
    // call aux
    Subtree placeholder = aux(root, &max);

    return max;
  }

private:
  Subtree& aux(TreeNode* nd, double* max) {
    Subtree res(nd);

    TreeNode* left = nd->left;
    if (left) {
      Subtree subtree = aux(left, max);
      // up res
      res.sum += subtree.sum;
      res.ct += subtree.ct;
    }
    TreeNode* right = nd->right;
    if (right) {
      Subtree subtree = aux(right, max);
      // up res
      res.sum += subtree.sum;
      res.ct += subtree.ct;
    }

    // leaf case
    if (!nd->left && !nd->right) {
      Subtree leaf(nd);
      res = leaf;
    }

    // aux
    double avg = (double)res.sum / (double)res.ct;
    double newMax = std::max(*max, avg);
    *max = newMax;

    std::cout << std::endl;

    return res;
  }
};

