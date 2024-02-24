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
    //双指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* fast = dummy_head;
        ListNode* slow = dummy_head;
        for(int i = 0; i < n+1; i++){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        return dummy_head->next;
    }
    //遍历一遍,先得到长度，再直接定位删除
    int getlength(ListNode* head){
        ListNode* cur = head;
        int length = 0;
        while(cur != nullptr){
            ++length;
            cur = cur->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* cur = dummy_head;
        int length = getlength(head);
        for(int i = 0; i < length - n; ++i){
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        return dummy_head->next;
    }
};



int main(){

}