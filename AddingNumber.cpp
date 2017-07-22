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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode res(0), *r = &res;
        
        if(!l1) {
            return l2;
        } else if(!l2) {
            return l1;
        }
        
        while(l1 || l2 || carry) {
            if(l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            r->next = new ListNode(carry % 10);
            r = r->next;
            carry /= 10;
        }
        return res.next;
    }
};
