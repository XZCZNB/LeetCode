//给你一个链表，删除链表的倒数第n个结点，并且返回链表的头结点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode phead(0, head);
        ListNode* fast = head;
        ListNode* slow = &phead;
        while(n-- > 0 && fast != nullptr) {
            fast = fast->next;
        }
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return phead.next;
    }
};