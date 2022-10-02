class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *test=head;
        int j=0;
        while(j<k){
            if(test==NULL){
                return head;
            }
            test=test->next;
            j++;
        }
        
        
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *temp;
        int cnt=1;
        while(curr!=NULL and cnt<=k){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            cnt++;
        }
        if(temp!=NULL){
            head->next=reverseKGroup(temp,k);
        }
        return prev;
    }
};