class Solution {
public:
    unordered_map<string,bool> dp; 
    bool isScramble(string s1, string s2) {
        if(s1.size()<1) return false;
        if(s1==s2) return true;
        string str=s1+s2;
        if(dp.find(str)!=dp.end()) return dp[str];
        int n=s1.size();
        for(int i=0;i<s1.size();i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i),s2.substr(i)))
                return dp[str]=true;
            if(isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i)))
                return dp[str]= true;
        }
        return dp[str]=false;
    }
};
