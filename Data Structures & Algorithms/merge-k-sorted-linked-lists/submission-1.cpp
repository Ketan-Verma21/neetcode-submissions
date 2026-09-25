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
    struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])pq.push(lists[i]);
        }
        if(pq.empty()) return nullptr;
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode* top= pq.top();
            pq.pop();
            temp->next=top;
            if(top->next)pq.push(top->next);
            temp=temp->next;
        }
        return dummy->next;
    }
};
