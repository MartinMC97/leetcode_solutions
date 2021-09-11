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
        ListNode* res = new ListNode();
        
        ListNode* pl1 = l1, *pl2 = l2, *pres = res;
        
        bool flag = false;
        int temp = 0;
        while(pl1 != NULL && pl2 != NULL){
            // calculate sum
            temp = pl1 -> val + pl2 -> val + ((flag) ? 1: 0);
            
            // check flag
            if(temp >= 10){
                flag = true;
                temp -= 10;
            }else{
                flag = false;
            }
            
            // new node 
            pres -> next = new ListNode(temp);
            pres = pres -> next;
            
            //move to next
            pl1 = pl1 -> next;
            pl2 = pl2 -> next;
        }
        
        if(pl1 != NULL){
            int temp;
            while(pl1 != NULL){
                temp = pl1 -> val + ((flag)? 1: 0);
                if(temp >= 10){
                    temp -= 10;
                    flag = true;
                }else{
                    flag = false;
                }
                pres -> next = new ListNode(temp);
                pres = pres -> next;
                pl1 = pl1 -> next;
            }
        }
        
        if(pl2 != NULL){
            int temp;
            while(pl2 != NULL){
                temp = pl2 -> val + ((flag)? 1: 0);
                if(temp >= 10){
                    temp -= 10;
                    flag = true;
                }else{
                    flag = false;
                }
                pres -> next = new ListNode(temp);
                pres = pres -> next;
                pl2 = pl2 -> next;
            }
        }
        
        if(flag){
            pres -> next = new ListNode(1);
            flag = false;
        }
        
        return res -> next;
    }
};