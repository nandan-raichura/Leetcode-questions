/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mpp;

        Node* temp=head;

        while(temp!=NULL){// making the clone nodes
            Node* cloneNode=new Node(temp->val);
            mpp[temp]=cloneNode;

            temp=temp->next;
        }

        temp=head;

        while(temp!=NULL){// making the next connection and random pointers connection

        Node* cloneNode=mpp[temp];

        cloneNode->random=mpp[temp->random];
        cloneNode->next=mpp[temp->next];
        temp=temp->next;

        }

        return mpp[head];// it will return the cloned lll head;
    }
};