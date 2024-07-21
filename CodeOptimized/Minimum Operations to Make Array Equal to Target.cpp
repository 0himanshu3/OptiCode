// Minimum Operations to Make Array Equal to Target

// Problem Link->(https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/)

// Beats 100% in time and 100% in memory||Recursion

// Solution Link->(https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/solutions/5511062/beats-100-in-time-and-100-in-memoryrecursion/)

// Approach
// Here we need minimum operations for converting it into target array.
// I have taken a vec array which has (target[i] - nums[i])
// Now our task to make all elements of this array 0. So we use a recursive approach to calculate minimum operations to evaluate this by grouping positive deviations and negative deviations leaving the ones which are already zero.
// In a group we can at max do operations till one element becomes 0 and again doing recursive call.

// Finally in main function we call the increment and decrement functions when needed taking care to avoid elements which are zero.

// Complexity
// Time complexity:
// O(n^2) at worst case
// Space complexity: O(n)

// Code:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void increment(vector<int>& vec, long long& ans, int l, int r) {
        if (l > r) return;
        int mini = INT_MAX;

        for (int i = l; i <= r; i++) {
            if (vec[i] < mini){
            mini = vec[i];
            }
        }

        ans += mini;
        for (int i = l; i <= r; i++) {
            vec[i] -= mini;
        }

        int prev = l;
        for (int i = l; i <= r; i++) {
            if (vec[i] == 0) {
                increment(vec, ans, prev, i - 1);
                prev = i + 1;
            }
        }
        increment(vec, ans, prev, r);
    }

    void decrement(vector<int>& vec, long long& ans, int l, int r) {
        if (l > r) return;
        int maxi = INT_MIN;

        for (int i = l; i <= r; i++) {
            if (vec[i] > maxi) {
                maxi = vec[i];
            }
        }

        ans += abs(maxi);
        for (int i = l; i <= r; i++) {
            vec[i] -= maxi;
        }

        int prev = l;
        for (int i = l; i <= r; i++) {
            if (vec[i] == 0) {
                decrement(vec, ans, prev, i - 1);
                prev = i + 1;
            }
        }
        decrement(vec, ans, prev, r);
    }

    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int n = nums.size();
        vector<int> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = target[i] - nums[i];
        }

        int i = 0;
        while (i < n && vec[i] == 0) {
            i++;
        }

        if (i == n) return 0;

        int prev = i;
        bool flag = vec[i] > 0;
        i++;

        while (i < n) {
            if (vec[i] == 0) {
                if (flag==1) {
                    increment(vec, ans, prev, i - 1);
                } 
                else {
                    decrement(vec, ans, prev, i - 1);
                }
                while (i < n && vec[i] == 0) {
                    i++;
                }
                prev = i;
                if (i < n) flag = vec[i] > 0;
            } 
            else if(vec[i]<0 && flag==1){
                increment(vec, ans, prev, i - 1);
                flag=0;
            }
            else if (vec[i] > 0 && flag==0) {
                decrement(vec, ans, prev, i - 1);
                prev = i;
                flag =1;
            }
            i++;
        }

        if (prev < n) {
            if (flag==1) {
                increment(vec, ans, prev, n - 1);
            } 
            else {
                decrement(vec, ans, prev, n - 1);
            }
        }

        return ans;
    }
};