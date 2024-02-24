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
//极度巧妙方法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while(A != B){
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
//先获取长度，再直接比较
    ListNode *compare(ListNode *currA, ListNode *currB, int lenA, int lenB){
        // 求长度差
        int gap = lenA - lenB;
         // 让curA【较长的链表】和curB在同一起点上，即让curA先走gap步
        for(; gap > 0; --gap){
            currA = currA->next;
        }
         // 遍历curA 和 curB，遇到相同则直接返回，相交的则为相交节点，后面全部一样
        while(currA != nullptr){
            if(currA == currB){
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;
        int lenA = 0, lenB = 0;
         // 求链表A的长度
        while(currA != nullptr){
            ++lenA;
            currA = currA->next;
        }
        // 求链表B的长度
        while(currB != nullptr){
            ++lenB;
            currB = currB->next;
        }
        currA = headA;
        currB = headB;
        if(lenA > lenB){
            return compare(currA, currB, lenA, lenB);
        }else{
            return compare(currB, currA, lenB, lenA);
        }
    }
};


int main(){

}