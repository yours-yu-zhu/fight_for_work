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
    ListNode* swapPairs(ListNode* head) {
        //虚拟头节点
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* cur = dummy_head;
        //注意循环终止的条件,奇数和偶数
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = tmp1->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;
            cur = cur->next->next;
        }
        return dummy_head->next;
    }
};


int main(){

}