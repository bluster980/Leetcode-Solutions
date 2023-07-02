class Solution {
public:
    int maxDepth(Node* root) {
        int maxx = 0;
        if(root==NULL) return 0;
        for(int i=0; i<root->children.size(); i++){
            maxx = max(maxx,maxDepth(root->children[i]));
        }
        return maxx+1;
    }
};