#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        ListNode* temp2 = nullptr;

        while (head != nullptr) {
            temp2 = head->next;
            head->next = temp;
            temp = head;
            head = temp2;
        }
        return temp;

        //https://www.youtube.com/watch?v=XgABnoJLtG4 refer this algorithm
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from input values
ListNode* createLinkedList(int n) {
    if (n <= 0) return nullptr;

    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 2; i <= n; ++i) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    return head;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = createLinkedList(n);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed linked list: ";
    printList(reversedHead);

    return 0;
}


/*
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 */