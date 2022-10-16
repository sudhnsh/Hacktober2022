class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<map<char, int>> charCounts;
        
        for(string s : A){
            map<char, int> charCount;
            for(char c : s){
                if(charCount.find(c)==charCount.end()){
                    charCount[c] = 1;
                }else{
                    charCount[c] += 1;
                }
            }
            charCounts.push_back(charCount);
        }
        
        map<char, int> charCount0 = charCounts[0];
        for(int i = 1; i < charCounts.size(); i++){
            //compare charCount0 and charCounts[i]
            // cout << i << "th" << endl;
            for(map<char, int>::iterator it=charCount0.begin(); it!=charCount0.end(); it++){
                char c = it->first;
                if(charCounts[i].find(c)==charCounts[i].end()){
                    charCount0[c] = 0;
                }else{
                    charCount0[c] = min(charCount0[c], charCounts[i][c]);
                }
                // cout << c << ": " << charCount0[c] << ", ";
            }
            // cout << endl;
        }
        
        vector<string> ans;
        for(map<char, int>::iterator it=charCount0.begin(); it!=charCount0.end(); it++){
            while(it->second>0){
                ans.push_back(string(1,it->first));
                it->second-=1;
            }
        }
        
        return ans;
    }
};
