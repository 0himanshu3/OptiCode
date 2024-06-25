// Sum root to leaf numbers

// Problem-link -> (https://leetcode.com/problems/sum-root-to-leaf-numbers/description/)


// Solution link -> (https://leetcode.com/problems/sum-root-to-leaf-numbers/solutions/5367709/beats-100-in-time-recursive-and-easy-solution-c/)
// Beats 100% in time


// Approach
// We will be adding the current node value to the sum ans calling for its left and right child node.
// Whenever We reach a node which has no child we eill add the sum to our answer and return
// At last we will subtract the current node value from sum for further executions.

// Complexity
// Time complexity:
// O(n): n=number of nodes

// Space complexity:
// Recursion stack space: O(h) h=height of tree
// Additional Space :O(1)

// Code:-
#include<bits/stdc++.h>
using namespace std;

/*
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void solve(TreeNode* root,int sum,int &ans){
        if (root==NULL)
            return ;
        sum=sum*10+root->val;
        if (root->left==NULL && root->right==NULL){
            ans+=sum;
            return ;
        }
        
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);

        sum-=root->val;
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;

    }
};