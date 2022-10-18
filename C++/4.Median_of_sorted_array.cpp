
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            }
            else if (i > iMin && nums1[i-1] > nums2[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                if ((m + n) % 2 == 1) { 
                    return maxLeft; 
                }

                int minRight = 0;
                if (i == m) { 
                    minRight = nums2[j]; 
                } else if (j == n) { 
                    minRight = nums1[i]; 
                } else { 
                    minRight = min(nums2[j], nums1[i]); 
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }

    double findMedianSortedArraysOn(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size(), n = nums2.size(), target = (m + n) / 2;
        int i = 0, j = 0;
        double median = 0;
        bool odd = ((m + n) % 2 == 1);
        while (i < m && j < n) {
            // cout << i << " " << j << " " << target << " " << odd << endl;
            if (i + j == target - 1) {
                if (!odd) {
                    median = nums1[i] < nums2[j] ? nums1[i++]: nums2[j++];
                } else {
                    if (nums1[i] < nums2[j]) {
                        i++;
                    } else {
                        j++;
                    }
                }
            } else if (i + j == target) {
                median += nums1[i] < nums2[j] ? nums1[i++]: nums2[j++];
                if (!odd) {
                    median /= 2;
                }
                break;
            } else {
                if (nums1[i] < nums2[j]) {
                    i++;
                } else {
                    j++;
                }
            }            
        }
        while (i < m) {
            if (i + j == target - 1) {
                if (!odd) {
                    median = nums1[i];
                }
            } else if (i + j == target) {
                median += nums1[i];
                if (!odd) {
                    median /= 2;
                }
                break;
            }
            i++;
        }
        while (j < n) {
            if (i + j == target - 1) {
                if (!odd) {
                    median = nums2[j];
                }
            } else if (i + j == target) {
                median += nums2[j];
                if (!odd) {
                    median /= 2;
                }
                break;
            }
            j++;
        }
        return median;
    }
};