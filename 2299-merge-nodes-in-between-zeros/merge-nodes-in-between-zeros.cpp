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
    ListNode* mergeNodes(ListNode* head) {
         ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* temp=head;
        ListNode* temp1=head->next;

        while(temp1!=NULL){
            long sum=0;
            if(temp1->val!=NULL){
                if(temp1->val!=NULL && temp1->next!=NULL){
                    while(temp1->val!=0 && temp1->next!=NULL){
                        sum+=temp1->val;
                        temp1=temp1->next;
                    }
                    temp->val=sum;
                    if(temp1->next!=NULL){// so it can be the last terminal zero or the separator zero , so here we use the if else statement and for that we cheack that whthere furthere elment is zero or not 

                    temp->next=temp1;
                    temp=temp1;
                    temp1=temp->next;
                    }else{// this element is last zero 
                    

                    temp->next=NULL;// we want thaat sum pointer to  the null
                    temp1=NULL; 

                    }
                    
                }
            }
        }
            return head;
    }
};