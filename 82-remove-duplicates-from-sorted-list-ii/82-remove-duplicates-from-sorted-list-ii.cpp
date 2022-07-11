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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0,head);
       ListNode *pre=&dummy;
        ListNode* cur=head; 
      
        while(cur!=NULL){
            if(cur->next!=NULL and  (cur->val)==(cur->next->val)){
            while(cur->next!=NULL and  (cur->val)==(cur->next->val)){
                pre->next=cur->next;
                delete cur;
                cur=pre->next;
               
                }
                pre->next=cur->next;   
               
            }
            else{
             
                pre=pre->next; 
            }
               cur=cur->next; 
        }
     
        
        return dummy.next; 
    }
};