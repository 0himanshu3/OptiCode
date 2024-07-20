// Jump_Game

// Problem Link->(https://leetcode.com/problems/jump-game/description/)

// O(n) time || Beats 98% in memory||Easy explanation||O(1) space

// Solution Link->(https://leetcode.com/problems/jump-game/solutions/5507526/o-n-time-beats-98-in-memory-easy-explanation-o-1-space/)



// Approach
// We just need to know while travelling if we reach a position which is not even possible from the previous jumping or not.

// So we Check for a given index if it hasn't execeded the max position you can be at.

// Complexity
// Time complexity:O(n)
// Space complexity:O(1)
// Code:-
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if(i>maxInd) return false;

            maxInd=max(maxInd,i+nums[i]);
        }
       return true;
    }
};