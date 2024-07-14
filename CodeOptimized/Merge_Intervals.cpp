// Merge Intervals

// Problem Link->(https://leetcode.com/problems/merge-intervals/description/)

// Beats 90% in time 90% in memory in C++||Easy explanation
// Solution Link->(https://leetcode.com/problems/merge-intervals/solutions/5475870/beats-90-in-time-90-in-memory-in-c-easy-explanation/)


// Approach
// At first We will Sort the array.
// then we would have 2 variables start and end and as we traverse through the array we would check the condition of overlapping.
// We would check the condition that the previous end is greater than the starting of next interval.

// Complexity
// Time complexity:O(nlog(n))
// Space complexity:O(n)
// Code:-
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } 
            else {
                vec.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        vec.push_back({start, end});

        return vec;
        
        
    }
};