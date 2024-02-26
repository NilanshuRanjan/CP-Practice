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
    long long adding(ListNode* l1, ListNode* l2) {
        long long n = 1, n1 = 0, n2 = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while (temp1 != NULL){
            n1 += n*(temp1->val);
            n *= 10;
            temp1 = temp1->next;
        }
        n = 1;
        while (temp2 != NULL){
            n2 += n*(temp2->val);
            n *= 10;
            temp2 = temp2->next;
        }
        cout << n1 << " and " << n2 << endl;
        return n1 + n2;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;

        int c = 0, sum = 0;
        while (l1 != NULL || l2 != NULL || c){
            if (l1 != NULL && l2 == NULL){
                sum = l1->val + c;
                l1 = l1->next;
            }
            else if (l1 == NULL && l2 != NULL){
                sum = l2->val + c;  
                l2 = l2->next;       
            }
            else if (l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + c;
                l1 = l1->next;
                l2 = l2->next;
            }
            else{
                sum = c;
            }
            c = sum/10;
            ListNode* nod = new ListNode(sum%10);
            temp->next = nod;
            temp = temp->next;
        }
        return head->next;
    }
};
