// Add Two Numbers
//Question Link->https://leetcode.com/problems/add-two-numbers/description/

// Easy And Recursive Approach to solve this question

// solution link (https://leetcode.com/problems/add-two-numbers/solutions/5355926/beats-93-time-and-86-memory-recursive-and-easy-solution/)


//Beats Beats 93% in time and 86% in memory 

// Approach
//We will start from the begining by taking our carry as 0
// then we will initialize first and sec (value of curr node of first and second list)as 0 and update it if it exists
// then we will call for next step giving number for present as value&10 and updating carry as val/10
// this recursive solution will finally provide the desired ans


//Time complexity:
// O(n) n=max(length(l1),length(l2))

//Space complecity:
//O(n)

/*Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2,int carry=0){
        if(l1==NULL && l2==NULL && carry==0) return NULL;

        int first=0;
        int sec=0;
        if(l1!=NULL){
            first=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sec=l2->val;
            l2=l2->next;
        }
        int val=first+sec+carry;
        ListNode* ans=new ListNode(val%10,solve(l1,l2,val/10));
        return ans;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            return solve(l1,l2,0);
    }
};
