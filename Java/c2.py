class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1
        ans = 0
        while(l<r):
            area = (r-l)* min(height[l],height[r])
            ans = max(ans,area)
            if height[l]<height[r]:
                l+=1
            elif height[r]<height[l]:
                r-=1
            else:
                if height[l+1]< height[r-1]:
                    r-=1
                else:
                    l+=1
        return ans
