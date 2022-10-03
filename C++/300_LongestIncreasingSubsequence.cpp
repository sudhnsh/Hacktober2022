class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                auto it=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[it]=nums[i];
            }
        }
        return temp.size();
    }
};
