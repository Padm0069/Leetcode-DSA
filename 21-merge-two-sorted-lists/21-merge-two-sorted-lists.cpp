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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // when list1 is empty then 
        // our output will be same as list2
        if(list1 == NULL) return list2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(list2 == NULL) return list1;

        // pointing l1 and l2 to smallest and greatest one
        if(list1->val > list2->val) std::swap(list1,list2);

        // act as head of resultant merged list
        ListNode* res = list1;

        while(list1 != NULL && list2 != NULL) {
 
            ListNode* temp = NULL;

            while(list1 != NULL && list1->val <= list2->val) {

                temp = list1;//storing last sorted node  
                list1 = list1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = list2;
            std::swap(list1,list2);
        }

        return res;
    }
};