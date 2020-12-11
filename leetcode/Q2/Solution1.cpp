//A dummy pointer will make the problem much easier.
//original author: Huahua
//modified by: mukoedo1993

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
    
        ListNode dummy, *dummy_=&dummy;
       
        int tmp=0;
        while(l1||l2||tmp){//edge case:  l1 and l2 both are not nullptr, so do not to worry about this question.
            tmp+=(l1?l1->val:0);
            l1=(l1?l1->next:nullptr);
            tmp+=(l2?l2->val:0);
            l2=(l2?l2->next:nullptr);
            dummy_->next=new ListNode(tmp%10);
              dummy_=dummy_->next;
            tmp/=10;
            
        }
        return (&dummy)->next;
    }
};
