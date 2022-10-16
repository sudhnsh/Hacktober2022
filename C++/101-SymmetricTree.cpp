class Solution {
public:
    bool isLevelSymmetric(vector<int>& level){
        if(level.size() == 1) return true;
        
        //besides root, each level's size should be even
        for(int i = 0; i < level.size()/2; i++){
            if(level[i] != level[level.size()-1-i]) return false;
        }
        
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur;
        int levelCount = 0;
        vector<int> level;
        
        q.push(root);
        levelCount = 1;
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur != NULL) level.push_back(cur->val);
            else level.push_back(INT_MIN);
            
            levelCount--;
            
            //we should also consider null node because it affect tree structure
            if(cur != NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
            
            if(levelCount == 0){
                if(!isLevelSymmetric(level)) return false;
                levelCount = q.size();
                level.clear();
            }
        }
        
        return true;
    }
};
