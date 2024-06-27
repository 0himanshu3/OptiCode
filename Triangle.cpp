//Triangle

// Problemlink->(https://leetcode.com/problems/triangle/description/)

// Easy C++ solution |Beats 100% | O(n) Extra Space
// Solution link->(https://leetcode.com/problems/triangle/solutions/5344264/easy-c-solution-beats-100-o-n-extra-space/)


// Approach
// Using the concept of dp we move from the last row to the top row of column
// updating values in dp vector as per the conditino for minimum path sum.

// Time Complexity:-O(n^2)
// Space Complexity:-Extra Space O(n)

// Code:-
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int func(vector<vector<int>>& triangle){
        int n=triangle.size();


        vector<int> dp(n);
        for (int i=0;i<n;i++) dp[i]=triangle[n-1][i];

  
        for (int i=n-2;i>=0;i--){
            for (int j=0;j<=i;j++){
                int first=dp[j];
                int sec=dp[j+1];
                dp[j]=triangle[i][j]+min(first,sec);
            }
        }
        return dp[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return func(triangle);
        
    }
};