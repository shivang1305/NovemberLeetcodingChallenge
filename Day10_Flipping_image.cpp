/*
    Day 10: Flip and Invert the given matrix                                Date: 10-Nov-2020

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
*/

class Solution {
public:
    vector<int> flipHorizontal(vector<int> row) {
        reverse(row.begin(), row.end());
        return row;
    }
    
    vector<int> invertRow(vector<int> row) {
        for(int i = 0; i < row.size(); i++) {
            if(row[i] == 0)
                row[i] = 1;
            else
                row[i] = 0;
        }
        return row;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++) {
            A[i] = flipHorizontal(A[i]);
            A[i] = invertRow(A[i]);
        }
        
        return A;
    }
};