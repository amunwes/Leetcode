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
    ListNode* reverseList(ListNode* head) {

        // if the current element is null or if the next element is NULL then we are at the end of the list 
        // this deals with edge cases of single item list.
        if(head == NULL || head->next == NULL){
            return head;
        }
        //record the current and previous ptrs. prev is where we store the ptr we came from, the old curr.
        ListNode* curr = head; 
        ListNode* prev = NULL;

        //iterate through the linked list stopping at the end where next == NULL
        while(curr != NULL){
            // next is saved in temp.
            ListNode* temp = curr->next;
            // set new next to be prev
            curr->next = prev;
            // new prev is now curr
            prev = curr;
            //new curr is now old next ie temp.
            curr = temp;
        }

        return prev;
    }
};