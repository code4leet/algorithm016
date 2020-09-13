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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* p1 = l1->val<l2->val?l1:l2; // 先头
        ListNode* p2 = l1->val<l2->val?l2:l1;
        
        ListNode* pRet = p1;
        ListNode* pCur = p1;
        p1 = p1->next;
        for(;;)
        {
            if(p1 == NULL) 
            {
                pCur->next = p2;
                break;
            }
            if(p2 == NULL)
            {
                pCur->next = p1;
                return pRet;
            }
            
            if(p1->val<=p2->val)
            {
                pCur->next = p1;
                p1 = p1->next;
            }
            else
            {
                pCur->next = p2;
                p2 = p2->next;
            }
            pCur=pCur->next;
        }
        return pRet;
    }
};