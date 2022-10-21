class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
     {
        int min=10000;
        int n=strs.size();
        if(n==0)
        return "";
        if(n==1)
        return strs[0];
        for(int  i=0; i<n; i++)
        {
            int size=strs[i].size();
            if(size<min)
            min=size;
        }
        string res="";
        for(int i=0; i<min; i++ )
        {
        char c= strs[0][i];
        for(int j=1; j<n; j++)
        {
            if (c!= strs[j][i])
            return res;
        }
        res+=c;
        }
        return res;
    }
};
