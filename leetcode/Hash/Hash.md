# 哈希表

# 哈希表的基础

常见的哈希结构：

C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：

| 集合 | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| --- | --- | --- | --- | --- | --- | --- |
| std::set | 红黑树 | 有序 | 否 | 否 | O(log n) | O(log n) |
| std::multiset | 红黑树 | 有序 | 是 | 否 | O(logn) | O(logn) |
| std::unordered_set | 哈希表 | 无序 | 否 | 否 | O(1) | O(1) |

std::unordered_set底层实现为哈希表，std::set 和std::multiset 的底层实现是红黑树，**红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以只能删除和增加。**

| 映射 | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| --- | --- | --- | --- | --- | --- | --- |
| std::map | 红黑树 | key有序 | key不可重复 | key不可修改 | O(logn) | O(logn) |
| std::multimap | 红黑树 | key有序 | key可重复 | key不可修改 | O(log n) | O(log n) |
| std::unordered_map | 哈希表 | key无序 | key不可重复 | key不可修改 | O(1) | O(1) |

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。**同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。**

当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，因为它的查询和增删效率是最优的，如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。

那么再来看一下map ，在map 是一个key value 的数据结构，map中，对key是有限制，对value没有限制的，因为key的存储方式使用红黑树实现的。

# 242.有效的字母异位词

```cpp
class Solution {
public:
	//哈希表的方法
    bool isAnagram(string s, string t) {
        vector<int> hash(26, 0);
        for(int i = 0; i < s.size(); i++){
            ++hash[s[i] - 'a'];
        }
        for(int i = 0; i < t.size(); i++){
            --hash[t[i] - 'a'];
        }
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0){
                return false;
            }
        }
        return true;
    }
//排序的方法
    bool isAnagram1(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

这道题是比较一个单词的字母种类和数量是否相同。

主要有两种方法：

- 哈希表的方法：创建一个包含26个int的数组,分别表示26个字母在第一个单词出现的次数，然后再对第二个单词每个单词进行减去。执行完毕操作以后，如果26个int均为0，则代表两个单词为字母异位词。
- 排序方法。确保长度一致以后排序后再比较。

# **349.两个数组的交集**

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int i : nums2){
            if(hash.find(i) != hash.end()){
                result.insert(i);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};
```

求两个数组的交集。

思路很简单。

主要是unordered_set的使用，需要熟悉，一个月没怎么用C++，对于容器的使用有一些生疏了。

就是先直接把vector用第一个数组的头尾迭代器转换为哈希表，再遍历第二个数组，如果再hash表存在，就放入第二个表~

# 202.**快乐数**

```cpp
class Solution {
public:
    int getsum(int n){
        int sum;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    //哈希表方法
    bool isHappy(int n) {
        unordered_set<int> hash;
        int sum = n;
        while(1){
            sum = getsum(sum);
            if(sum == 1){
                return true;
            }

            if(hash.find(sum) == hash.end()){
                hash.insert(sum);
            }else{
                return false;
            }
        }
    }
    //快慢指针方法
        bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = getsum(slow);
            fast = getsum(fast);
            fast = getsum(fast);
        }while(slow != fast);

        return slow == 1;
    }
};
```

思路很简单。

题目中说了会 **无限循环**，那么也就是说**求和的过程中，sum会重复出现，这对解题很重要！**

**当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了。**

所以这道题目使用哈希法，来判断这个sum是否重复出现，如果重复了就是return false， 否则一直找到sum为1为止。

判断sum是否重复出现就可以使用unordered_set。

**还有一个难点就是求和的过程，如果对取数值各个位上的单数操作不熟悉的话，做这道题也会比较艰难。**

- 时间复杂度: O(logn)
- 空间复杂度: O(logn)

第二种方法更简单，使用链表中判断链表是否有环的快慢指针来做~~~

# 1.**两数之和**

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int i : nums2){
            if(hash.find(i) != hash.end()){
                result.insert(i);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};
```

leetcode第一题。

暴力法不过多赘述。两层for循环即可。

hash表只用一层for循环，时间复杂度低很多。

主要是思路。每次把遍历的值和下标放入hash表，如果本次遍历的目标值之前出现过，就返回。

重点是思路！！