// Relative Sort Array

// Problem link->(https://leetcode.com/problems/relative-sort-array/description/)

// beat 100% relative ordering

// Solution Link->(https://leetcode.com/problems/relative-sort-array/solutions/5292587/beat-100-relative-ordering/)

// Approach
// just store the freq of elements present in arr2 in a unordered_map so that their relative ordering stays same and rest in a vector and sort it finally merge both

// Complexity
// Time complexity:O(nlogn)
// Space complexity:O(n)
// Code

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for (auto z:arr2){
            mp[z]=0;
        }
         vector<int> remain; 

        for (auto z:arr1){
            if(mp.find(z) != mp.end()){
                mp[z]++;
            } else {
                remain.push_back(z);
            }
        }

        int x = 0;
        for (auto z:arr2){
            while(mp[z] > 0){
                arr1[x++] = z;
                mp[z]--;
            }
        }

        sort(remain.begin(), remain.end());

        for (auto z:remain){
            arr1[x++] = z;
        }

        return arr1;
    }
};