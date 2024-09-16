#include <iostream>
#include <vector>
#include <set> // Include this for std::set

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;  
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

// Helper function to create a list with or without a cycle
ListNode* createListWithCycle(const vector<int>& values, int pos) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    ListNode* cycleNode = nullptr;

    for (size_t i = 1; i < values.size(); ++i) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
        if (i == pos) {
            cycleNode = tail;
        }
    }

    if (cycleNode) {
        tail->next = cycleNode; // Create a cycle
    }

    return head;
}

// Helper function to test the hasCycle function
void testHasCycle(const vector<int>& values, int pos, bool expected) {
    ListNode* head = createListWithCycle(values, pos);
    Solution solution;
    bool result = solution.hasCycle(head);
    cout << "List: [";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i < values.size() - 1) cout << ", ";
    }
    cout << "]\nCycle position: " << pos << "\nExpected: " << expected << "\nResult: " << (result ? "true" : "false") << endl;

    // Clean up memory
    ListNode* current = head;
    set<ListNode*> visited; // Use std::set
    while (current) {
        if (visited.find(current) != visited.end()) break; // Handle cycle cleanup
        ListNode* next = current->next;
        delete current;
        current = next;
        visited.insert(current);
    }
}

int main() {
    // Test cases
    testHasCycle({3, 2, 0, -4}, 1, true); // List with a cycle
    testHasCycle({1, 2}, -1, false); // List without a cycle
    testHasCycle({1}, -1, false); // Single node without a cycle
    testHasCycle({}, -1, false); // Empty list

    return 0;
}

/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.*/