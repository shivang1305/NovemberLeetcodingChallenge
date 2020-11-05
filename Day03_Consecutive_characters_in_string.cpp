/*                                                                                    Date: 05-Nov-2020
Day 03 : November Leetcoding challenge problems solution (Calculate the max number of consecutive characters in the string)

Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 
Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
*/

class Solution {
public:
    int maxPower(string str) {
        int count = 0, ct = 0;
        
        //traversal of the string
        for(int i=1; str[i]!=NULL; i++) {
            if(str[i] == str[i-1])
                ct++;
            else {
                count = max(count, ct); //greedy approach
                ct = 0;
            }
        }
        count = max(count, ct);
        ct = 0;
        
        return count+1;
    }
};