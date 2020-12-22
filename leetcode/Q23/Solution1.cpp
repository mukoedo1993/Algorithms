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
//Author: mukoedo1993

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode dummy,*dummy_p=&dummy;
        while(!all_empty(lists))
        {
            int min= 10001;
            int cnt=-1;
         for(int i=0;i<lists.size();i++)
         {
             if(!lists[i])continue;
             if(lists[i]->val<min){
                 cnt=i;
                 min=lists[i]->val;
             }
             
         }
           dummy_p->next=lists[cnt];
            lists[cnt]=lists[cnt]->next;
            dummy_p=dummy_p->next;
        }
        return dummy.next;
    }
    private:
    bool all_empty(const vector<ListNode*>&Lists)
    {
        for(int i=0;i<Lists.size();i++)
            if(Lists[i])return false;
        return true;
    }
};
