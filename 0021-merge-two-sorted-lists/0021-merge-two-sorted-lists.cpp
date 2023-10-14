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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the code
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        // Merge the two lists until one of them becomes empty
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // If one list is not empty, append the remaining nodes
        if (list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // The merged list starts from the next of the dummy node
        ListNode* mergedList = dummy->next;

        // Delete the dummy node to avoid memory leak
        delete dummy;

        return mergedList;
    }
};
