/*
    Day 07 : Add two numbers represented by linked lists                             Date: 10-Nov-2020

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/


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
    
    /* APRROACH 1 - Reversing the linked list
    
    ListNode* revList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ptr;

        while(curr != NULL) {
            ptr = curr->next; //to store the address of next element before breaking the link

            curr->next = prev;
            prev = curr;
            curr = ptr; //to move the curr forward in the orignal list
        }

        head = prev; //putting the head of reversed linked list pointing to last element of orignal linked list

        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = revList(l1);
        l2 = revList(l2);
        
        ListNode *ans = new ListNode(0);
        ListNode *ptr1 = l1, *ptr2 = l2, *curr = ans;
        
        int carry = 0;
        
        while(ptr1 != NULL || ptr2 != NULL) {
            int x = (ptr1 != NULL) ? ptr1->val : 0;
            int y = (ptr2 != NULL) ? ptr2->val : 0;
            
            int sum = x + y + carry;
            
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            if(ptr1 != NULL)
                ptr1 = ptr1->next;
            if(ptr2 != NULL)
                ptr2 = ptr2->next;
        }
        
        if(carry != 0) {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        
        return revList(ans->next);
    }
    */
    
    /* APPROACH 2 - Without reversing or modifying the given linked list using stacks */
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //creating two stacks
        stack<int> st1;
        stack<int> st2;
        
        //pushing all the elements of both the linked list into stacks
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0, x = 0, y = 0;
        ListNode *head = NULL;
        
        //untill both the lists are not empty
        while(!st1.empty() || !st2.empty()) {
            //reseting values of x & y to zero so that when one stack is empty the loder values of x or y does not affect the whole sum
            x = 0;
            y = 0;

            if(!st1.empty()) {
                x = st1.top();
                st1.pop();
            }
            
            if(!st2.empty()) {
                y = st2.top();
                st2.pop();
            }
            //obtaining suma & carry
            int sum = x + y + carry;
            carry = sum / 10;
            
            ListNode *node = new ListNode(sum % 10); //create a new node
            
            //add the new node in the front of the new linked list i.e. our ans
            if(head == NULL)
                head = node;
            else {
                node->next = head;
                head = node;
            }
        }
        
        //at the end if carry is there
        if(carry > 0) {
            ListNode *node = new ListNode(carry);
            
            if(head == NULL)
                head = node;
            else {
                node->next = head;
                head = node;
            }
        }
        
        return head;
    }
};