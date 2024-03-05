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

# **454.四数相加II**

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        for(auto i : nums1){
            for(auto j : nums2){
                ++hash[i + j];
            }
        }
        int count = 0;
        for(auto i : nums3){
            for(auto j : nums4){
                if(hash.find(-(i + j)) != hash.end()){
                    count += hash[-(i + j)];
                }
            }
        }
        return count;
    }
};
```

相比于简单暴力的四次for循环的O(n^4)的时间复杂度。

我们可以将四个数组分成两部分，A和 B为一组，C和 D为另外一组。

对于 A 和 B，我们使用二重循环对它们进行遍历，得到所有 A[i]+B[j]的值并存入哈希映射中。对于哈希映射中的每个键值对，每个键表示一种 A[i]+B[j]，对应的值为 A[i]+B[j]出现的次数。

对于 C和 D，我们同样使用二重循环对它们进行遍历。当遍历到 C[k]+D[l]时，如果 −(C[k]+D[l])出现在哈希映射中，那么将 −(C[k]+D[l]) 对应的值累加进答案中。

最终即可得到满足 A[i]+B[j]+C[k]+D[l]=0 的四元组数目。

通过分组降低了时间复杂度到O(n^2)

# 383.赎金信

```cpp
    //unoreder_map解法
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for(char c : magazine){
            ++hash[c];
        }
        for(char c : ransomNote){
            --hash[c];
            if(hash[c] < 0){
                return false;
            }
        }
        return true;
    }
    //数组哈希解法
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for(auto c : magazine){
            ++hash[c - 'a'];
        }
        for(auto c : ransomNote){
            --hash[c - 'a'];
            if(hash[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }   
```

题目看起来还是比较简单的。

感觉和242的有效单词异位词题目基本一样，所以思路也是一样的。

把字典magazine变为hash表，再遍历ransomNote，遍历ransomNote的一个单词，就从hash表对应的位置减去1，并判断是否为负数。

主要在于hash的数据结构的选择。

可以用数组可以用map，但是数组更简单，空间复杂度更小，时间复杂度为O(n)。

# 15.三数之和🌟

```cpp
//1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //先排序
        sort(nums.begin(), nums.end());
        //再遍历
        for(int i = 0; i < nums.size(); ++i){
            //必须开头为负数才能相加为0
            if(nums[i] > 0){
                return result;
            }
            //去重
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > 0) --right;
                else if(sum < 0) ++left;
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while(left < right && nums[right] == nums[right - 1]) --right;
                    while(left < right && nums[left] == nums[left + 1]) ++left;
                    // 找到答案时，双指针同时收缩
                    --right;
                    ++left;
                }
            }
        }
        return result;
    }
};
//2
class Solution {
public:
    // 哈希函数
    struct VectorHash {
        size_t operator()(const vector<int>& vec) const {
            size_t hash = 0;
            for (int num : vec) {
                hash ^= hash << 1 ^ num;
            }
            return hash;
        }
    };

    // 相等比较函数
    struct VectorEqual {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a.size() == b.size() && equal(a.begin(), a.end(), b.begin());
        }
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //先排序
        sort(nums.begin(), nums.end());
        //再遍历
        for(int i = 0; i < nums.size(); ++i){
            //必须开头为负数才能相加为0
            if(nums[i] > 0){
                break;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > 0) --right;
                else if(sum < 0) ++left;
                else{
                    //结果排序
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    sort(tmp.begin(), tmp.end());
                    result.push_back(tmp);
                    // 找到答案时，双指针同时收缩
                    --right;
                    ++left;
                }
            }
        }
        unordered_set<vector<int>, VectorHash, VectorEqual> s(result.begin(), result.end());
        vector<vector<int>> f(s.begin(), s.end());
        return f;
    }
};
```

这道题感觉很不好做，第一次做基本看不懂的。

因为用hash表是十分不好做的。而且要去重，就是必须不能重复。

所以用双指针+排序要稍微好理解一点。

要多看这种题，其中去重的操作也有很多细节，包括i的去重，left和right的去重等等！！！

第二种方法，采用set来去重，但是有一个会超时。仅供参考学习。

# 18.四数之和🌟

```cpp

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        // 双指针要排序
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) { // 第一层循环
            // 对第一个i进行剪枝
            if (nums[i] > target && target > 0)
                break;
            // 去重i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 二层循环
            for (int j = i + 1; j < nums.size(); ++j) {
                // 第二次剪枝
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                    break;
                // 去重j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // 开始双指针
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    //这里必须变为long，否则要溢出
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                        --right;
                    else if (sum < target)
                        ++left;
                    else {
                        result.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        // right去重
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        // left去重
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        // push_back以后还有缩小双指针范围
                        --right;
                        ++left;
                    }
                }
            }
        }
        return result;
    }
};
```

和15题三数之和基本差不多，就是多了一层循环以及多了一层剪枝。

要多看！

# 49. **字母异位词分组**

```cpp
class Solution {
public:
    //自己想的方法
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        //每个字符串排序后作为key，原字符串作为value
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        //再把hash表的value放到result中
        vector<vector<string>> result;
        for(const auto &pair : hash){
            result.push_back(pair.second);
        }
        return result;
    }
    //第二种方法，大体思路差不多，但是用了一个sub来记录要插入result的位置，就不用再遍历hash表了
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        int sub = 0;
        vector<vector<string>> result;
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if(hash.find(tmp) == hash.end()){
                hash[tmp] = sub++;
                result.push_back({s});
            }else{
                result[hash[tmp]].push_back(s);
            }
        }
        return result;
    }
};
```

因为要找组成一样的单词，如何判断？
最简单的，一排序，如果是同一个单词，那么就是组成一样的
比如 “eat” "tea" 排序后都为 “aet”
只要引入一个hash表，索引是排序后的单词，值为结果vector的下标，循环一遍就好了

# 438.找到字符串中的所有字母**异位词**

```cpp
class Solution {
public:
    bool isequal(const vector<int> &a, const vector<int> &b){
        if(a.size() != b.size())
            return false;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> s_count(26,0);
        vector<int> p_count(26,0);
        vector<int> result({});
        if(s.size() < p.size()) return result;
        //构建哈希表p_count和滑动窗口
        for(int i = 0; i < p.size(); ++i){
            ++p_count[p[i] - 'a'];
            ++s_count[s[i] - 'a'];
        }
        //判断第一个窗口
        if(isequal(s_count, p_count)) result.push_back(0);     
        //开始滑动窗口，fast < s.size() - 1。防止越界
        for(int slow = 0, fast = p.size() - 1; fast < s.size() - 1;){
            s_count[s[slow++] - 'a']--;
            s_count[s[++fast] - 'a']++;
            if(isequal(s_count, p_count)){
                result.push_back(slow);
            }       
        }
        return result;

    }
};
```

滑动窗口+哈希表的映射方法。

全部自己写的。