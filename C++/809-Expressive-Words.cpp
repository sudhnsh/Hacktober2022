class Solution {
public:
    bool ok(string &a,string &b){
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            int cnt1=1,cnt2=1;
            if(a[i]!=b[j]) return false;
            while(i+1<a.size() and a[i]==a[i+1]) cnt1++,i++;
            while(j+1<b.size() and b[j]==b[j+1]) cnt2++,j++;
            if(cnt2!=cnt1){
                if(cnt1>cnt2) return false;
                if(cnt2<3) return false;
            }
            i++;j++;
        }
        if(i==a.size() and j==b.size()) return true;
        return false;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(ok(words[i],s))
                ans++;
        }
        return ans;
    }
};
