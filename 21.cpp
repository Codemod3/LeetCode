#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
   int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* s = new ListNode(-1);
        ListNode* dum = s;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                s->next = list1;
                list1 = list1->next;
            } else {
                s->next = list2;
                list2 = list2->next;
            }
            s = s->next;
        }
        if (list1 != nullptr) {
            s->next = list1;
        } else {
            s->next = list2;
        }
        return dum->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case
    vector<int> list1_vals = {1, 2, 4};
    vector<int> list2_vals = {1, 3, 4};
    
    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);
    
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]*/