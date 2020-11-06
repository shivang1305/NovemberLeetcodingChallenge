/*
            Day 06: Find the smallest divisor given a threshold                   Date: 06-Nov-2020

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
Example 3:

Input: nums = [19], threshold = 5
Output: 4
*/


class Solution {
public:
   
    int sumOfArray(vector<int>& nums, int k) {
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++) 
            sum += ceil((float)nums[i]/k);
        
        return sum;
    }
    /* BRUTE FORCE APPROACH 
    int smallestDivisor(vector<int>& nums, int threshold) {
        //obtain the max value inside the array
        int m = INT_MIN;
        for(int i=0; i<nums.size(); i++) 
            m = max(m, nums[i]);
        
        
        int sum, i;
        for(i=1; i<=m; i++) {
            sum = sumOfArray(nums, i);
            if(sum <= threshold)
                return i;
        }
         
        return -1;
    }
    */
    
    /* Optimized Approach - applying binary search */
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        //sorting the array first 
        sort(nums.begin(), nums.end());
        
        int lo = 1;
        int hi = nums[nums.size() - 1];
        
        int ans;
        
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(sumOfArray(nums, mid) > threshold)
                lo = mid+1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};