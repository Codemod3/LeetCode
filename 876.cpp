#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        int mid;
        ListNode* dup = head;
        while (dup != nullptr) {
            count += 1;
            dup = dup->next;
        }

        mid = count / 2;
        int i = 0;
        while (i < mid) {
            head = head->next;
            i++;
        }
        return head;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode *head = nullptr, *tail = nullptr;
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution solution;
    ListNode* midNode = solution.middleNode(head);

    cout << "Middle node value: " << midNode->val << endl;

    return 0;
}


/*


876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 */