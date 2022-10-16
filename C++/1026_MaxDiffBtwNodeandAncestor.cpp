
class Solution {
public:
    int maxAncestorDiffMM(TreeNode* node, int mx, int mn){
        return node ? max(maxAncestorDiffMM(node->left, max(node->val, mx), min(node->val, mn)),
                    maxAncestorDiffMM(node->right, max(node->val, mx), min(node->val, mn))): mx-mn;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiffMM(root, 0, INT_MAX);
    }
};