// Subarrays with K Different Integers

// Problem Link->(https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

// Sliding Window||Beats 90% in time and 94% in memory in C++

// Solution Link->(https://leetcode.com/problems/subarrays-with-k-different-integers/solutions/5518630/sliding-windowbeats-90-in-time-and-94-in-memory-in-c/)

// Approach
// Instead Of directly finding subarray with k distinct Integers.
// We Fill find number of subarrays with atmost k different integers and subtract it by number of subarray with atmost k-1 different integers.

// Finding Number of subarrays with atmost k different integers is simple. We Simply traverse and mark integers in a map whenever our size of map increases we start trimming it from front.
// and then update our count . and finally return count.

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
    int func(vector<int>& nums, int k){
         int s=0;
        int e=0;
        int cnt=0;
        unordered_map<int,int> mp;
        while (e<nums.size()){
            mp[nums[e]]++;
            while (mp.size()>k){
                mp[nums[s]]--;
                
                if (mp[nums[s]]==0){
                    mp.erase(nums[s]);
                }
                s++;
            }
            cnt+=(e-s+1);
            e++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return (func(nums,k)-func(nums,k-1));

    }
};