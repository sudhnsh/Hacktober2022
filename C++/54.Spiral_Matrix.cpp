// Leetcode 54. Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int elementsTraversed = 0;
        int totalElements = matrix.size()*matrix[0].size();
        int srow = 0, scol = 0, erow = matrix.size() - 1, ecol = matrix[0].size() - 1;
        while(elementsTraversed < totalElements){
            
            /* Print the first row from the remaining rows */
            for(int i = scol; i <= ecol && elementsTraversed < totalElements; i++){
                ans.push_back(matrix[srow][i]);
                elementsTraversed++;
            }
            srow++; //moves to next row
            
            /* Print the last column from the remaining columns*/
            for(int i = srow; i <= erow && elementsTraversed < totalElements; i++){
                ans.push_back(matrix[i][ecol]);
                elementsTraversed++;
            }
            ecol--; //moves to prev column
            
             /* Print the last row from the remaining rows */
            for(int i = ecol; i >= scol && elementsTraversed < totalElements; i--){
                ans.push_back(matrix[erow][i]);
                elementsTraversed++;
            }
            erow--; //moves to prev row
            
            /* Print the first column from the remaining columns*/
            for(int i = erow; i >= srow && elementsTraversed < totalElements; i--){
                ans.push_back(matrix[i][scol]);
                elementsTraversed++;
            }
            scol++; //moves to next column
            
        }
        return ans;
    }
};