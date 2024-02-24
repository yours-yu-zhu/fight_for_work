#include <iostream>
#include <vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class Solution {
public:
//迭代法
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
//递归法
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == nullptr){
            return pre;
        }
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
int main(){

}