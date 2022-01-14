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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* finall = head->next;
        head->next = finall->next;
        finall->next = head;
        
        ListNode *prev = head, *curr = head->next,*temp;
        while(curr && curr->next){
            temp = curr->next->next;
            prev->next = curr->next;
            curr->next->next = curr;
            curr->next = temp;
            prev = curr;
            curr = temp;
        }
        return finall;
    }
};