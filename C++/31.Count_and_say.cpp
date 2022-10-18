class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for (int i = 0; i < n - 1; ++i)
        {
            string temp;
            
            for (int index = 0; index < res.size(); ++index)
            {
                int count = 1;
                
                while (index < res.size() - 1 and res[index] == res[index + 1])
                {
                    ++index;
                    ++count;
                }
                temp.push_back(count + '0');
                temp.push_back(res[index]);
            }
            res = temp;
        }
        return res;
    }
};