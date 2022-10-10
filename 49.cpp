class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> answer;
        map<char,int> mp;
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                mp[strs[i][j]]++;
            }
            answer[mp].push_back(strs[i]);
            mp.clear();
        }
        vector<vector<string>> solution;
        for(auto x:answer)
        {
            solution.push_back(x.second);
        }
        return solution;
    }
};
