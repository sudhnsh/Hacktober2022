#include<bits/stdc++.h>
using namespace std;

string removeDup(string s)
{
    if(s.length()==0){
        return"";
    }
    char chr=s[0];
    string ans = removeDup(s.substr(1));
    if(chr == ans[0]){
        return ans;
    }{
    
        return (chr+ans);
    }

}

int main()
{
    cout<<removeDup("a");
    return 0;
}