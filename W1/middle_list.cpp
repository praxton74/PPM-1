

struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode *middleNode(ListNode *head) {
    ListNode *slow = head; 
    ListNode *fast = head;
    if(head || head->next)
        return head;
    
    while(fast && fast->next) {
        slow = slow->next; 
        fast = fast->next->next; 
    }
    return slow;
}
