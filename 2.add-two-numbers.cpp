/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
#ifndef LISTNODE_H
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
#endif
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr){
                tail->val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                tail->val += l2->val;
                l2 = l2->next;
            }

            tail->next = new ListNode(tail->val / 10);
            tail->val %= 10;
            if(l1 != nullptr || l2 != nullptr || tail->next->val != 0)
                tail = tail->next;
            else
                tail->next = nullptr;
        }
        
        return head;
    }
};
// @lc code=end