/* Day 02 : Nov Leetcoding Challenge                                                   Date: 02-Nov-2020
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* insertionSortList(ListNode* head) {
        //edge cases
        if(!head)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* start = head;
        ListNode* curr = head->next;
        
        while(curr) {
            start = head;
            //taking start from head to curr pointer and compare all the values and swapping the required values
            while(start != curr) {
                if(start->val > curr->val)
                    swap(start->val, curr->val);
                start = start->next;
            }
            curr = curr->next;
        }
        
        return head;
    }
};