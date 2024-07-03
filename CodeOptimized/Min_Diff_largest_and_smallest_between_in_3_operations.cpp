// Minimum Difference Between Largest and Smallest Value in Three Moves

// Problem link-> (https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/)

// Easy Optimal Solution|| time-O(nlogn)||Space-O(1)

// Solution link-> (https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/solutions/5407964/easiest-optimal-solution-time-o-nlogn-space-o-1/)


// Approach
// Since we have three operations we would choose combinations between three smallest and greatest number.
// We know for n<=4 answer will always be four.
// And for rest we have four options choosing->
// 3 largest
// 3 smallest
// 2 largest and 1 smallest
// 2 smallest and 1 largest
// We just have to select between these.
// So will sort the array and select the minimum.

// Complexity
// Time complexity:O(nlogn)
// Space complexity:O(1)

// Code->

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;

        sort(nums.begin(),nums.end());

        int ans=INT_MAX;

        ans=min(ans,nums[n-4]-nums[0]);
        ans=min(ans,nums[n-1]-nums[3]);
        ans=min(ans,nums[n-2]-nums[2]);
        ans=min(ans,nums[n-3]-nums[1]);

        return ans;
    }
};