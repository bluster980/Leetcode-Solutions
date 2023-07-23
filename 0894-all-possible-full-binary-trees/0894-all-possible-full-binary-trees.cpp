/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* clone(TreeNode* root) {
    TreeNode* new_root = new TreeNode(0);
    new_root->left = (root->left) ? clone(root->left) : nullptr;
    new_root->right = (root->right) ? clone(root->right) : nullptr; 
    return new_root;
  } 

  vector<TreeNode*> allPossibleFBT(int N) {
    if (0 == N % 2) {
      return std::vector<TreeNode*>{};
    } else if (1 == N) {
      return std::vector<TreeNode*>{1, new TreeNode{0}};
    }

    std::vector<std::vector<TreeNode>> patterns;
    patterns.emplace_back();
    patterns.back().emplace_back(0);

    for (int root = 1; root < N / 2; ++root) {
      patterns.emplace_back();
      for (int left_size = 0; left_size < root; ++left_size) {
        for (auto& left : patterns[left_size]) {
          for (auto& right : patterns[root - left_size - 1]) {
            patterns.back().emplace_back(0);
            patterns.back().back().left = &left;
            patterns.back().back().right = &right;
          }
        }
      }
    }
    std::vector<TreeNode*> ret;
    for (int root = 0; root < N / 2; ++root) {
      for (auto& left : patterns[root]) {
        for (auto& right : patterns[N / 2 - root - 1]) {
          ret.emplace_back(new TreeNode(0));
          ret.back()->left = clone(&left);
          ret.back()->right = clone(&right);
        }
      }
    }

    return ret;
  }
};