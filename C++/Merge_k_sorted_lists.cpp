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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        ListNode *l=new ListNode();
        ListNode *head=l;
        ListNode *prev;
        int _empty=1;
        while(1){
            int val=INT_MAX;
            int index=0;
            int possible=0;
            for(int i=0;i<n;i++){
                if(lists[i]!=NULL&&lists[i]->val<val){
                    val=lists[i]->val;
                    index=i;
                }
            }
            // now we have minimum in current
            if(val==INT_MAX){
                break;
            }else{
                // create new node
                _empty=0;
                l->val=val;
                prev=l;
                l->next=new ListNode();
                l=l->next;
                lists[index]=lists[index]->next;
            }
        }
        if(head->next!=NULL){
            prev->next=NULL;
        }
        if(_empty){
            head=NULL;
        }
        return head;
    }
};