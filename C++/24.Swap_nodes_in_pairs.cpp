
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
    ListNode* swap(ListNode* node){
        //length 0 or 1
        if(!node || !node->next)
            return node;
        
        ListNode* next = node->next;
        node->next = next->next;
        next->next = node;
        
        return next;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        
        dummy->next = head;
        
        ListNode* cur = dummy;
        
        while(cur){
            ListNode* next = swap(cur->next);
            cur->next = next;
            
            cur = cur->next;
            if(cur)cur = cur->next;
        }
        
        return dummy->next;
    }
};