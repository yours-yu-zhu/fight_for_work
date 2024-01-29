# 链表

# 203.移除链表元素

```cpp
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
                cur = cur->next;
            }
        }
        head = beg->next;
        delete beg;
        return head;
    }
};
```

经典的学习数据结构的时候，对链表进行增加的题目。

思路是简单的，但是在实现过程中，我们每次操作的是cur的下一个节点，**所以我们当我们进行一次删除的时候，cur的next已经变化了，就不需要在 cur = cur->next。只有没有被删除的时候，才调用 cur = cur->next。**
# 707.设计链表

大一的时候数据结构的题目。

设计自己的链表。

多看几遍就会了，很基础，很经典。