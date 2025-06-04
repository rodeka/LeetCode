/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        int k = lists.size();
        while(k > 1){
            for(int i = 0; i < k / 2; i++){
                lists[i] = merge(lists[i], lists[k - i - 1]);
            }
            k = (k + 1) / 2;
        }
        
        return lists[0];
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head = (l1->val < l2->val) ? l1 : l2;
        ListNode* tail = head;
        if(head == l1) l1 = l1->next;
        else l2 = l2->next;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head;
    }
};
// @lc code=end

