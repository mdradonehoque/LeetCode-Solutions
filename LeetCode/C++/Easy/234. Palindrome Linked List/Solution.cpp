class Solution {
public:
    void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
        ListNode* newnode = new ListNode(val);
        if(head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        ListNode* tmp = head;
        
        while(tmp != NULL){
            insert_at_tail(newhead, newtail, tmp->val);
            tmp = tmp->next;
        }
        
        newhead = reverseList(newhead);
        
        ListNode* p1 = head;
        ListNode* p2 = newhead;
    
        while(p1 != NULL && p2 != NULL){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};