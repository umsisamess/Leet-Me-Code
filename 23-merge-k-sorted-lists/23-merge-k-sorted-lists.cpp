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
    ListNode* merge(ListNode* head, ListNode* list1){
        if(head==NULL) return list1;
        if(list1==NULL) return head;
        if(head->val<=list1->val){
            head->next = merge(head->next,list1);
            return head;
        }else{
            list1->next = merge(head,list1->next);
            return list1;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode* head = lists[0];
        for(int i=1;i<n;i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
};