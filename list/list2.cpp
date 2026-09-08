//给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字0之外，这两个数都不会以0开头。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        int res = 0;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry) {
            int a = 0;
            int b = 0;
            if(l1 != nullptr) {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                b = l2->val;
                l2 = l2->next;
            }
            res = a + b + carry;
            carry = res / 10;
            res %= 10;
            cur->next = new ListNode(res);
            cur = cur->next;
        }
        return head->next;
    }
};