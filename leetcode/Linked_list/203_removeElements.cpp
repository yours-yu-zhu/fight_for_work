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
    ListNode* removeElements(ListNode* head, int val) {
        //初始化一个虚拟头节点
        ListNode *beg = new ListNode(-1, head);
        for(ListNode *cur = beg; cur->next != nullptr;){
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp; 
            }else{
                cur = cur->next
            }
        }
        head = beg->next;
        delete beg;
        return head;
    }
};

int main(){
    Solution s;
    //初始化一个一串链表
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for(int i = 2; i < 7; i++){
        ListNode *tmp = new ListNode(i);
        cur->next = tmp;
        cur = cur->next;
    }   
    //调用函数
    ListNode *res = s.removeElements(head, 6);
    //打印结果
    for(ListNode *cur = res; cur != nullptr; cur = cur->next){
        cout << cur->val << " ";
    }

}