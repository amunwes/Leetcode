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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL){
            return NULL;
        }
        
        ListNode* curr = head; 
        ListNode* dummy = new ListNode();
        // dummy->next = head;

        ListNode* currhead = head;
        ListNode* prevtail = dummy;

        int count = 0;

        while(curr != NULL){
            count++;
            if (count == k){
                count = 0;
                ListNode* temp = curr->next;
                curr->next = NULL;
                prevtail->next = reverseList(currhead);// prev tail links to head of reversed 
                prevtail = currhead; //after reversal the current head is the tail.
                curr = temp; // now move onto the next group.
                currhead->next = curr;
                currhead = curr;
            }else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = head; 
        ListNode* prev = NULL;

        
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};