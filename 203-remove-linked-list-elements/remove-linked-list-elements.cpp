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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            ListNode* deleteNode=head;
            head=head->next;
            delete deleteNode;
        }

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;// we use dumy node becz we waan to prevent the case for the accesing the null, becz if the prev will be null, we cant assing the its next to the head or any other node


        ListNode* currNode=head;
        ListNode* prev=dummy;
        
        prev->next=head;

        while(currNode!=NULL){
            if(currNode->val==val){
                prev->next=currNode->next;
                ListNode* deleteNode = currNode;
                currNode=currNode->next;
                delete deleteNode;
            }
            else{
                prev=currNode;
                currNode=currNode->next;
            }
        }

        return dummy->next;
        
    }
};