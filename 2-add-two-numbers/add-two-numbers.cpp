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
        
        int carry1 = 0;
        ListNode* head = NULL;
        ListNode* prev = NULL;
    
        while(l1!=NULL || l2!=NULL || carry1){
            int num1 = 0; //init to 0 each loop so we can still calc when 1 list is longer than the other.
            int num2 = 0;

            if(l1!=NULL)
                num1 = l1->val;
            if(l2!=NULL)
                num2 = l2->val;
            
            int sum = num1 + num2 + carry1;

            if (sum >= 10){// dealing with carried 1
                carry1 = 1;
                sum = sum - 10;
            }else{
                carry1 = 0;
            }

            if (prev == NULL){//first element.
                head = new ListNode(sum); // create the node for head.
                prev = head;
            }else{// otherwise link the prev to the new node created.
                prev->next = new ListNode(sum);
                prev = prev->next;
            }
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
                
        }
        // here both of the lists are now NULL so we can say the prev pointers next is null, 
        // but the constructor set that for us automatically
        return head;
    }
};