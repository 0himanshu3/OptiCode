// House_Robber

// Problem-link -> (https://leetcode.com/problems/house-robber/description/)


// Solution link -> (https://leetcode.com/problems/house-robber/solutions/5345620/beats-100-easy-c-solution-tabulation/)
// Beats 100% time


// Approach 
// (Tabulation)
// We just need create a dp array marked it first element same as nums array
// and second onemax of first and that element.
// Then we traverse and updatte elements if we consider just previous element we dont add current element in sum
//  otherwise if we consider one before curr element sum in it

// Complexity
// Time complexity:
// O(n)

// Space complexity:
// O(n)

// Code:-
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        int first,sec;
        for (int i=2;i<n;i++){
            first=dp[i-2]+nums[i];
            sec=dp[i-1];
            dp[i]=max(first,sec);
        }
       return dp[n-1];
    }
};