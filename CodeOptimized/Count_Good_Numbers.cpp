// Count Good Numbers

// Problem link->(https://leetcode.com/problems/count-good-numbers/description/)

// Beats 100% || Best solution||Using Bitwise operator for faster exponentiation

// Code Link->(https://leetcode.com/problems/count-good-numbers/solutions/5330622/beats-100-best-solutionusing-bitwise-operator-for-faster-exponentiation/)


// Approach
// Using Bitwise Operator for faster exponentiation.

// 1.Using & to check whther it is odd or even.
// 2. if it is odd multiplying ans by base

// if it is even multiplying base itself
// right shift of n until it becomes 0
// Complexity
// Time complexity:
// O(logn)

// Space complexity:
// O(1)
// Code:-
#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long mod=1e9+7;
public:
    long long power(long long x,long long n){
        long long ans=1;
        while(n!=0){
            if (n&1)
                ans=(ans*x)%mod;
            x=(x*x)%mod;
            n=n>>1;       
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even=(n/2)+(n%2);
        long long odd=n/2;
        long long evenx=power(5,even);
        long long oddx=power(4,odd);
        return (evenx*oddx)%mod;
        
    }
};