class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0)
            {
                nums[i]=nums.size()+1;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])>0&&abs(nums[i])<(nums.size()+1))
            {
                int temp=abs(nums[i]);
                nums[temp-1]=abs(nums[temp-1])*(-1);
            }
        }
        
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<' ';
            if(nums[i]>0)
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
