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
     //function for reversing the Linked List
    void reverse(ListNode** head){
        ListNode* curr=*head,*prev=0,*nxt;
        while(curr){
		     nxt=curr->next;
			 curr->next=prev;
			 prev=curr;
			 curr=nxt;
		}	 
        *head=prev;  
    }

    int pairSum(ListNode* head){

        //get mid and sepearte them
        ListNode* prev=0, *slow=head, *fast=head;
        while(fast and fast->next){
	       prev=slow;
		   slow=slow->next;
		   fast=fast->next->next;
        }
        prev->next=0;      //seperate them
        reverse(&slow);
   
        //get the max sum of twins
        int sum=0;
        ListNode *ptr1=head, *ptr2=slow;
    
	    while(ptr1){
	      sum=max(sum, ptr1->val+ptr2->val );
		  ptr1=ptr1->next ;
		  ptr2=ptr2->next;
        }
 
        
   
        return sum;
    }
};