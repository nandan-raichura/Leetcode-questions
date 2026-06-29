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
    
    ListNode* findMiddle(ListNode* head){// tortosie and hare algo to find the middle
        ListNode* slow=head;
        ListNode* fast=head->next;// we make changes here for the fast becz if the size of the linked list is the  oeven , we want that middle 1 , so for that we have made this changes

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;// slow will stop at the middle of the ll
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

      ListNode* t1=list1;
      ListNode* t2=list2;


      ListNode* dummy = new ListNode(-1);

      ListNode* temp=dummy;


      while(t1!=NULL && t2!=NULL){
        if(t1->val < t2->val){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;

        }
      }  

      if(t1){// it means  t1 is still remaining so we will attach the temp pointer to the t1 (imp edge case)
            temp->next=t1;
      }else{
            temp->next=t2;
      }

      return dummy->next;//dummy node is the main elmenet who have helped to bulit the entire linked list
    }

    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }// base case, when linked will be divided unitl the non sperable part

        ListNode* middle=findMiddle(head);

        // after finding the ,middle , we will divde the ll into the n/2 part

        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;// at this steps we are seprating the ll for the further division 

        middle->next=NULL;// to seprate the left side ll with right side one

        // now calling tthe function itself to compelete the further steps

        leftHead=sortList(leftHead);// this will return the sorted head of the left side
        rightHead= sortList(rightHead);// vice versa

        // those above two recursive step will divide the ll into the parts at each level of the recurssion

       ListNode* newNode= mergeTwoLists(leftHead,rightHead);// will combine both ll into one sorted list

        return newNode;
    }
};