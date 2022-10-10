class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1)
        {
            return "";
        }
        if(s[0]!='a')
        {
            s[0]='a';
            return s;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='a'&&(i!=s.size()-1-i))
            {
                s[i]='a';
                return s;
            }
        }
        s[s.size()-1]='b';
        return s;
    }
};
