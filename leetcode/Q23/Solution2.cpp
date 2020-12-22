//Author: Huahua
//Link: https://zxi.mytechroad.com/blog/list/leetcode-23-merge-k-sorted-lists/
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    
    auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
    
    for (ListNode* list : lists) 
      if (list) q.push(list);
    
    while (!q.empty()) {
      cur->next = q.top(); q.pop();      
      cur = cur->next;
      if (cur->next) q.push(cur->next);
    }
    return dummy.next;
  }
};
