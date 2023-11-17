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
        
        // covering edge cases of the lists starting out empty.
        if(list1 == NULL && list2 == NULL)
            return NULL;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        // assigning a pointer for the start of our new list.
        ListNode* start = NULL;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        if(list2->val < list1->val){
            start = list2;
            curr2 = list2->next;
        }else{
            start = list1;
            curr1 = list1->next;
        }
        
        // setting some workable pointers we can use for iterating.
        ListNode* prev = start;

        while(curr1 != NULL && curr2 != NULL){
            
            if(curr1->val <= curr2->val){
                prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;

            }
            else if(curr1->val > curr2->val){
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
        }
        //covers end of list behavior, whatever list didn't hit null should takeover.
        // shouldnt be any way for both pointers to become null in the same loop so this should cover end behavior.
        if (curr1 == NULL)
            prev->next = curr2;
        else if (curr2 == NULL)
            prev->next = curr1;

        return start;
    }
};