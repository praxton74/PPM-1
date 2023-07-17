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
    ListNode *th = NULL, *tt = NULL;
public:
    int length(ListNode *head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }
    void addFirst(ListNode *node) {
        if(th == NULL)
            th = tt = node;
        else {
            node->next = th;
            th = node;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1)
            return head;
        int size = length(head);
        ListNode *curr = head;
        ListNode *oh = NULL, *ot = NULL;
        while(size >= k) {
            int temp = k;
            while(temp--) {
                ListNode *N = curr->next;
                curr->next = NULL;
                addFirst(curr);
                curr = N;
            }
            if(!oh) {
                oh = th;
                ot = tt;
            }
            else {
                ot->next = th;
                ot = tt;
            }
            
            th = tt = NULL;
            size -= k;
        }
        if(size)
            ot->next = curr;
        return oh;
    }
};
