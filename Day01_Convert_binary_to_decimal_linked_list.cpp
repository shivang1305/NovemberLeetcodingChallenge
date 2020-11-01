/*                                                                      Date: 01-Nov-2020 
Day 01 : Nov Leetcoding Challenge (Convert binary number to decimal number in linked list)                                                                                        

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 
Example 1:  1 --> 0 --> 1

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

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
    int sizeOfList(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        
        return size-1; //to start calculating the size of the list from zero
    }
    int getDecimalValue(ListNode* head) {
        //edge case
        if(!head)
            return -1;
        
        int size = sizeOfList(head);
        int sum = 0;
        
        while(head != NULL) {
            sum += head->val * pow(2, size--); //formula to calculate decimal number from binary digits
            head = head->next;
        }
        
        return sum; 
    }
};