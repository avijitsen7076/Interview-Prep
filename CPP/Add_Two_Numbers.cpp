//2. Add Two Numbers
//https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(0);
        ListNode* curr=res, *p=l1, *q=l2;
        
        
        int carry=0;
        while(p!=NULL || q!=NULL){
            
            int x=0;
            if(p!=NULL)
                x=p->val;
            
            int y=0;
            if(q!=NULL)
                y=q->val;
            
            int sum=carry+x+y;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            
            carry=sum/10;
            
            if(p!=NULL)
                p=p->next;
            if(q!=NULL)
                q=q->next;
        }
        
        if(carry>0)
            curr->next=new ListNode(carry);
    
        return res->next;
    }
};