// Insert Interval

// Problem Link->(https://leetcode.com/problems/insert-interval/description/)

// Beats 92% in C++||O(n) Time Complexity ||Easy explanation

// Solution Link->(https://leetcode.com/problems/insert-interval/solutions/5488870/beats-92-in-con-time-complexity-easy-explanation/)

// Approach
// First we will traverse the intervals until we get the intersection with the lower Limit of newInterval and keep it adding it in our ans vector.
// If we get the interval which is intersecting the newInterval we will update our newInterval lower and upper limit until our intersection ends and push the resulting newInterval.
// At last add the remaining intervals.

// Complexity
// Time complexity:O(n)
// Space complexity:O(n) for ans vector. Maximum will be O(n+1) if the newInterval doesn't intersect and is added at last
// Code:-
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};