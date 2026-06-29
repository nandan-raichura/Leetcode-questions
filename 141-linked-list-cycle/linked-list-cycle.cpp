/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:// tortoise and hare algo
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            // if it any state(fast and slow) both combines /colides then the cycle exist we are makein slow move by one and fast by two and then at evry iteration the distance between them get reduced by one, so they will definetly meet

            if(slow==fast){
                return true;
            }
        }

        return false;
    }
};
