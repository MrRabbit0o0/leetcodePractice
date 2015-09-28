class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        return addTwoNumbersRecursion(l1, l2, 0);
    }
private:
    ListNode* addTwoNumbersRecursion(ListNode* l1, ListNode* l2, int n){
        ListNode* one;
        if (n != 0){
            one = new ListNode(n);
        } else {
            one = nullptr;
        }
        if (l1 == nullptr && l2 == nullptr){
            return one;
        }
        if (l1 == nullptr){
            if (n != 0){
                return addTwoNumbersRecursion(l2, one, 0);
            } else {
                return l2;
            }
        }
        if (l2 == nullptr){
            if (n != 0){
                return addTwoNumbersRecursion(l1, one, 0);
            } else {
                return l1;
            }
        }
        ListNode* p = new ListNode(0);
        int sum = l1->val + l2->val + n;
        int current = sum % 10;
        if (sum >= 10){
            n = 1;
        } else {
            n = 0;
        }
        p->val = current;
        p->next = addTwoNumbersRecursion(l1->next, l2->next, n);
        return p;
    }
};
