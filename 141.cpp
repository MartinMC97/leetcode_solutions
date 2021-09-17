/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *slow = head, *fast = head -> next;

        while(slow != fast){
            if(slow != NULL){
                slow = slow -> next;
            }else{
                break;
            }
            
            if(fast != NULL){
                fast = fast -> next;
                if(fast != NULL){
                    fast = fast -> next;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        
        return (fast != NULL);
    }
};