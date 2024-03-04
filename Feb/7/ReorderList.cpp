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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;

        if (head == NULL) return;

        ListNode* temp = head;

        while (temp->next != NULL){
            arr.push_back(temp);
            temp = temp->next;
        }
        arr.push_back(temp);
        int pos = 0, n = arr.size();
        if (n <= 2) return;
        while(pos <= n/2){
            if ( pos == 0 ){
                temp->next = arr[pos]->next;
                arr[pos]->next = temp;
                temp = temp->next;
            }
            else{
                arr[n-pos-1]->next = temp->next;
                temp->next = arr[n-pos-1];
                temp = temp->next->next;
            }
            pos ++;
        }

        temp -> next = NULL;
    }
};
