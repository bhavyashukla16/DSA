//https://leetcode.com/problems/add-two-numbers/

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

//Numbers r given in reverse order

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=NULL; //the head node of the list to be returned
        ListNode *temp, *prev=NULL;
        int carry=0, sum=0;
        while(l1!=NULL || l2!=NULL) //till both the numbers r completed
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            
            carry = (sum>=10) ? 1 : 0;
            sum%=10; //remove carry from sum
            temp = new ListNode(sum);
            
            if(res == NULL) //if it's the first node of linked list put temp in head i.e. res
                res = temp;
            else
                prev->next = temp; //else make the previous node point to temp
            
            prev = temp; //make current node as previous for the next iteration
            
            if(l1) // move to next node only when currently not on NULL
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(carry>0) //if carry is left make a new node with value carry and make the curr node point to this new node
           prev->next = new ListNode(carry); 
        return res;
    }