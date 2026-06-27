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
public:// approch (optimal) we will make the all odd indexed node linked to node, and same with even , we will make it link with even node.
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;

        ListNode* fixed=head->next;


        while(even!=NULL && even->next!=NULL){// even will always end before the odd becz itis starting after the odd

       odd->next=even->next;
       odd=odd->next;

       even->next=odd->next;
       even=even->next;



        }

        odd->next=fixed;

        return head;
    }
};