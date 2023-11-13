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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* fast = head;

        if(head == NULL || head->next == NULL){// if theres one element or no elements then we return empty.
            return NULL;
        }

        for (int i =0; i< n ; i++){// advances fast to n spots ahead of head.
            fast = fast->next;
        }
        // if fast isnt null then we can advance curr at the same rate as fast 
        // to measure out how far from the end we are.
        if(fast != NULL){
            // ie. [1,2,3,4,5] n=2
            //          c x f
            while (fast->next != NULL){
                curr = curr->next;
                fast = fast->next;
            }
            // since curr->next is the element we want to remove we just jump it.
            curr -> next = curr->next->next;
        }else{//if fast is NULL it means they wanna remove the first element since fast went past the end.
        // this only works assuming n <= list length.
        return head->next;

        }
        

        return head;
    }
};