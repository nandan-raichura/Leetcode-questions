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

    ListNode* reverseList(ListNode* head) {
        // recursive approch

        if(head==NULL || head->next==NULL){// last stage of the recursion base case
            return head;
        }

        ListNode* newHead=reverseList(head->next);// i will call for an next nodes , so they can solve the problem

        ListNode* front=head->next;// here head is the current head of the recursion level

        front->next=head;

        head->next=NULL;

        return newHead;// new head will remain same till last, becz we have only one head and after reverse it will come form the last recursion call
    }


    ListNode* returnKthNode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }

        return temp;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;

        while(temp!=NULL){
            ListNode* kthNode=returnKthNode(temp,k);// it will return tthe kth node for  the particular node which will be the kth node , 

            if(kthNode==NULL){// if  we dont have the elemetss or nnodes to  form the kth size of  the ll then kthNode will be the NULL
                if(prevNode){
                    prevNode->next=temp;// we will connect the remaining ll with the previous one
                }
                break;
            }
            // otherwise


            ListNode* nextNode=kthNode->next;// point for the next ll after the kth set
            kthNode->next=NULL;// to seprate the ll
             
            reverseList(temp);

            if(temp==head){
                head=kthNode;// kth node will become the head for tehe each ll after the revrsing
            }else{
                prevNode->next=kthNode;// conect prev list with present one
            }

            prevNode=temp;//we move prev to the curent ll temp, so we can have a track of  it
            temp=nextNode;// me move the temp to the head(hypytehtical head of next ll)


        }

        return head;
    }
};