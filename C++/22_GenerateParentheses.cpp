class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string output="";
        generate(output,0,n,0,0);
        return ans;
    }
    void generate(string output,int i,int n,int open,int closed){
        if(i==2*n){
            ans.push_back(output);
            return;
        }
        if(open<n){
            generate(output+'(',i+1,n,open+1,closed);
        }
        if(closed<open){
            generate(output+')',i+1,n,open,closed+1);
        }
    }
};
