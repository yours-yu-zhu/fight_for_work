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
    ListNode *detectCycle(ListNode *head) {
        //快慢指针
        ListNode* fast = head;
        ListNode* slow = head;
        //
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){//判断是否有环
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while(index1 != index2){ //判断环的入口
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;t
    }
};


int main(){

}