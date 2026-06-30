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
    
    ListNode* lastNode(ListNode*head,int k){
        ListNode* temp=head;
        int cnt=1;

        while(temp!=NULL){
            if(cnt==k)return temp;

            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==NULL || k==0){
        return head;
       }
       
        ListNode* temp=head;
        int count=1;

        while(temp->next!=NULL){
            temp=temp->next;
            count++;
           
         
        }
       if(k%count==0){
        return head;
       }

        temp->next=head;

        k=k%count;
        

       ListNode* newLastNode=lastNode(head,count-k);

       head=newLastNode->next;
       newLastNode->next=NULL;

       return head;
    }
};