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
    vector<TreeNode*> buildTree(int l, int r) {
	vector<TreeNode*> ans;   
    if(l > r) {
		ans.push_back(NULL);
        return ans;
    }
	for(int i = l; i <= r; ++i) {
		vector<TreeNode*> leftSubTree = buildTree(l, i - 1);
        vector<TreeNode*> rightSubTree = buildTree(i + 1, r);

		for(int j = 0; j < leftSubTree.size(); j++) {
			for(int k = 0; k < rightSubTree.size(); k++) {
				TreeNode* temp = new TreeNode(i);
				temp->left = leftSubTree[j];
                temp->right = rightSubTree[k];
				ans.push_back(temp);
			}
		}
    }
	return ans;
}
    
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }
};