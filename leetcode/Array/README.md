# 数组

# 数组理论基础

## 需要注意的两点

- **数组下标都是从0开始的。**
- **数组内存空间的地址是连续的**

正是**因为数组的在内存空间的地址是连续的，所以我们在删除或者增添元素的时候，就难免要移动其他元素的地址。**

# **704. 二分查找**

我写的代码：

```cpp
//区间为左闭右闭区间，不能用size_t，因为size_t是无符号数，当right = 0时，right - 1会溢出
    int search_1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; //起始区间为[0, nums.size() - 1]
        while(left <= right){
            int middle = left + ((right - left) / 2);
            if(nums[middle] > target){
                right = middle - 1; //target在左区间
            }else if(nums[middle] < target){
                left = middle + 1;  //target在右区间
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
    //区间为左闭右开区间，
    int search_2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); //起始区间为[0, nums.size()]
        while(left < right){
            int middle = left + ((right - left) / 2);
            if(nums[middle] > target){
                right = middle ; //target在左区间
            }else if(nums[middle] < target){
                left = middle + 1;  //target在右区间
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
```

二分查找还是挺简单的

主要注意两种写法，左闭右开和左闭右闭两者写法中，left和right的边界条件就可以了。

但是我还是**犯了一个错，就是left和right定义为了size_t，因为size_t是无符号数，当right = 0时，right - 1会溢出，debug调出的bug。**

- 时间复杂度：O(log n)
- 空间复杂度：O(1)

# 27. **移除元素**

```cpp
//库函数法，不能直接用
    int removeElement_ku(vector<int>& nums, int val) {
        for(auto i = nums.begin(); i != nums.end(); i++){
            if(*i == val){
                nums.erase(i);
                i--;
            }
        }
        int size = nums.size();
        return size;
    }
    //暴力的解法，找到以后把后面所有的往前面移动
    int removeElement_baoli(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(nums[i] == val){
                for(int j = i ; j < size; ++j){
                    nums[j] = nums[j + 1];
                }
                --i;    
                --size;
            }
        }
        return size;
    }
    //双指针法,迭代器版本，快慢指针的方法，很巧妙
    int removeElement(vector<int>& nums, int val) {
        auto fast = nums.begin();
        auto slow = nums.begin();
        for(;fast != nums.end(); ++fast){
            if(*fast != val){
                *slow = *fast;
                ++slow;
            }
        }
        return slow - nums.begin();
    }
```

自我练习使用了三种方式。

- 第一种直接迭代器加erase函数，即库函数版本，时间复杂度为O(n)，实际使用会使用这个，但是本体其实是实现erase函数。**这里我犯的错是erase没有保持i不动，即对i进行- -操作，不然会跳过val后面的那个元素。**
- 暴力解法，第一次遍历val，并将这个位置后面的都往后面移动。时间复杂度为O时间复杂度：O(n^2)，空间复杂度：O(1)。
- 双指针法：双指针法（快慢指针法）： **通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。**定义快慢指针：
    - 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
    - 慢指针：指向更新 新数组下标的位置

双指针十分巧妙，主要掌握方法。

# 977.**有序数组的平方**

```cpp
//暴力解法，先平方，再直接调用快速排序
    vector<int> sortedSquares_1(vector<int>& nums) {
        for(auto i = nums.begin(); i != nums.end(); ++i){
            *i *= *i;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
//双指针法，从两端开始遍历，比较两端的平方值，将较大的值放入结果数组的末尾
    vector<int> sortedSquares_2(vector<int>& nums) {
        size_t k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for(size_t i = 0, j = k; i <= j;){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                result[k--] = nums[j] * nums[j];
                --j;
            }else{
                result[k--] = nums[i] * nums[i];
                ++i;
            }
        }
        return result;
    }
```

这道题整体来说还是简单的

- 暴力解法直接就每个元素变为平方，再调用快速排序。O(nlogn)的时间复杂度
- 双指针方法，则是抓住**最大的元素一定是在数组的两端这个特点，**是除此之外就没有难点了。

自己手撸代码时候出现了if(nums[i] * nums[i] < nums[j] * nums[j])这里刚开始写的没有平方来写

# 209.**长度最小的子数组**

```cpp
//暴力解法，时间复杂度O(n^2)
    int minSubArrayLen_1(int target, vector<int>& nums) {
        int sum = 0;
        int length = 0, min = INT32_MAX;
        for(int i = 0; i < nums.size(); ++i){
            sum = 0;
            length = 0;
            for(int j = i; j < nums.size(); ++j){
                sum += nums[j];
                length++;
                if(sum >= target){
                     min = min > length ? length : min;
                     break;
                }
            }
        }
        return min == INT32_MAX ? 0 : min;
    }
    //滑动窗口法，时间复杂度O(n)
    int minSubArrayLen_2(int target, vector<int>& nums) {
        int sum = 0; //滑动创建窗口数组之和
        int length = 0; //滑动创建窗口数组长度
        int min = INT32_MAX; //最小长度
        int i = 0;//滑动窗口起始位置
        for (int j = 0; j < nums.size(); ++j){
            sum += nums[j];
            while(sum >= target){
                length = j - i + 1;
                min = min > length ? length : min;
                sum -= nums[i++];
            }
        }
        return min == INT32_MAX ? 0 : min;

    }
```

也是两种方法

- 第一种暴力解法，两层套循环，遍历两次数组。时间复杂度O(n^2)。实现起来比较简单，但是要注意。**结果的min初始值必须初始化为int的最大值，坚决不能初始化为0**。
- 感觉第二种滑动窗口类似于第一种的简化。只让窗口结束为止遍历整个数组。

为什么两个循环嵌套，时间复杂度为O(n)呢？

> 
> 
> - 外部循环：外部循环通过变量 **`j`** 遍历了一次数组 **`nums`**，因此它的时间复杂度是 O(n)。
> - 内部循环：内部循环通过变量 **`i`** 控制滑动窗口的起始位置。虽然它嵌套在外部循环中，但是对于每个外部循环的迭代，内部循环只能移动一次窗口的起始位置 **`i`**。由于每个元素在整个过程中最多被访问两次（一次添加到窗口的 **`sum`** 中，一次从窗口的 **`sum`** 中移除），因此算法的总操作次数与数组元素的数量成线性关系。即使有两层循环（一个外循环和一个内循环），每个元素仍然只被处理有限次，所以总体时间复杂度是 O(n)。
> 
> 综上所述，尽管代码中有两层循环，但由于内部循环不会对每个外部循环的迭代都执行完整的遍历，总的时间复杂度是线性的，即 O(n)。
> 

# **59.螺旋矩阵II**

```cpp
vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        int offset = 1;
        int startX = 0;
        int startY = 0;
        vector<vector<int>> result(n,vector<int>(n, 0));
        for(int cycle = 0; cycle < (n / 2); ++cycle){
            //上面
            for(; startY < n - offset; ++startY){
                result[startX][startY] = count++;
            }

            //右边
            for(; startX < n - offset; ++startX){
                result[startX][startY] = count++;
            }
            //下边
            for(; startY >=offset ; --startY){
                result[startX][startY] = count++;
            }
            //左边
            for(;startX >= offset; --startX){
                result[startX][startY] = count++;
            }
            ++startX;
            ++startY;
            ++offset;
        }
        if(n % 2 == 1){
            result[n / 2][n / 2] = count;
        }
        return result;
    }
```

其实不难，主要思路就是：

- 确定循环次数。
- 每次循环分为上下左右四次，每次要固定次数，即确定左闭右开的区间。
- 其次就是调一调bug就出来了。

比如我出现的问题就是写右边和下边的代码时，循环退出的条件直接写成了>0，是不对的。

同时注意嵌套vector容器的初始化，vector<vector<int>> result(n,vector<int>(n, 0));【刚开始写错了】

# **35.搜索插入位置**

```cpp
int searchInsert(vector<int>& nums, int target) {
        //左闭右开二分法
        int left = 0;
        int right = nums.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] > target){
                right = middle;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return left;
    }
```

和704二分查找基本没有任何区别，就当复习二分查找了～

# 34.**在排序数组中查找元素的第一个和最后一个位置**

```cpp
class Solution {
public:
    //寻找左右边界
    vector<int> searchRange(vector<int>& nums, int target) {
       int leftbound = binarySearch(nums, target, true);
       int rightbound = binarySearch(nums, target, false); 
       return {leftbound, rightbound};

    }
    //找到一个target后，向左右两边扩展
    vector<int> searchRang_1(vector<int>& nums, int target) {
        int middle = binarySearch(nums, target, true);
        int leftbound = middle, rightbound = middle;
        if(middle == -1){
            return {-1, -1};
        }
        while(leftbound >= 0 && nums[leftbound] == target){
            leftbound--;
        }
        while(rightbound < nums.size() && nums[rightbound] == target){
            rightbound++;
        }
        return {leftbound + 1, rightbound - 1};
    }
private:
//二分法寻找左右边界，flag为true时寻找左边界，flag为false时寻找右边界
    int binarySearch(vector<int>& nums, int target, bool flag){
        int left = 0;
        int right = nums.size();
        int result = -1;
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] > target){
                right = middle;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] == target){
                if (flag == true){
                    right = middle;
                    result = middle;
                }else if(flag == false){
                    left = middle + 1;
                    result = middle;
                }
            }
        }
        return result;
    }
};
```

这道题是二分法的扩展。要寻找所有的符合target的区间，找到左右边界。就有两种思路了。

- 第一种，我定义子函数，**子函数作用为寻找左右边界，flag为true时寻找左边界，flag为false时寻找右边界。**实现过程中就是在二分法过程中，遇到nums[middle] == target，要根据时找左边界还是右边界，把middle所在位置排除在下一次二分法的区间之外，直到找到边界。再主函数调用两次即可。
- 第二种，只调用一次普通二分法。找到一个taget的位置。然后依据这个位置向左右两边扩展，直到找到边界。注意边界可能越界，要加入判断条件。

自我认为第二种比第一种稍快一点。

# 69.x 的平方根

```cpp
int mySqrt_1(int x) {
        double left = 0, right = static_cast<double>(x) + 1;       
        int result = 0;
        if(x == 0){
            return 0;
        }

        while(left < right){
            int middle = left + (right - left) / 2;
            if(middle > x / middle){
                right = middle;
            }else if(middle < x / middle){
                left = middle + 1;
                result = middle;
            }else{
                return middle;
            }
        }
        return result;
    }
    int mySqrt_2(int x) {
        double left = 0, right = static_cast<double>(x) + 1;       
        int result = 0;
        while(left < right){
            int middle = left + (right - left) / 2;
            if(static_cast<double>(middle) * static_cast<double>(middle) > x){
                right = middle;
            }else if(static_cast<double>(middle) * static_cast<double>(middle) < x){
                left = middle + 1;
                result = middle;
            }else if(static_cast<double>(middle) * static_cast<double>(middle) == x){
                return middle;
            }
        }
        return result;
    }
```

这道题思路其实简单，二分法查找，然后比较mid*mid和给定的大小之间的差距，必须是小于等于才行。

问题就在，mid*mid可能超过了int的2的32次方的最大限制，以及x + 1 也可能超过限制（二分法的左闭右开）。

所以要把left 和 right定义为double。

把mid * mid强制转换为double。

还有一种思路就是把mid * mid 与x的判断转化为mid与 x / mid之间的判断。就省去一个的强制类型转换。但是除法耗时很长，以及要排除mid为0的情况~

这道题还是用左闭右闭的二分法写法要好一点感觉~

# 367.**有效的完全平方数**

这道题思路和69基本一样，二分法easy～

# 26.**删除有序数组中的重复项**

```cpp
int removeDuplicates_1(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        auto fast = nums.begin() + 1;
        auto slow = fast;
        int curobj = *(nums.begin());
        for(;fast != nums.end(); ++fast){
            if(*fast != curobj){
                *slow = *fast;
                curobj = *fast;
                ++slow;
            }
        }
        return slow - nums.begin();
    }
    int removeDuplicates_2(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int fast = 1, slow = 1;
        while(fast < n){
            if(nums[fast] != nums[fast - 1]){
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
```

27题目的基本一样的思路，使用双指针可以让时间复杂度降低到O(n)。

我写了迭代器版本和下标访问的版本。

感觉迭代器的空间占用更多。

# 283.移除零

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        int size = nums.size();
        for(; fast < size; ++fast){
            if(nums[fast] != 0){
                swap(nums[fast], nums[slow]);
                ++slow;
            }
        }
    }
};
```

简单的快慢指针法～

但是重点是如何把0移到后面。

最开始我的版本没有swap，后面的先把前面的覆盖，然后再把多余的置为0，应该是多此一举的。

不如直接用swap函数。

# 844.**双指针法比较退格字符串**

```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return clear(s) == clear(t);
    }
    string clear(string s){
        int slow = 0, fast = 0;
        int size = s.size();
        for(; fast < size; ++fast){
            if(s[fast] != '#'){
                s[slow] = s[fast];
                ++slow;
            }else{
                --slow;
            }
        }
        return s.substr(0, slow);
    }
};

/*
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        changestring(s);
        changestring(t);
        return s==t;
    }
    void changestring(string &s)
    {
        int slow=0;
        for(int fast=0;fast<s.size();fast++)
        {
            if(s[fast]!='#')
            s[slow++]=s[fast];
            else if(slow!=0)
                slow--;
        }
        s.resize(slow);
    }
};*/
```

看了官方题解，感觉不如我这个，清洗易懂。

clear函数将string变换为取掉#的格式。

# 904.水果成篮

```cpp
int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        int size = fruits.size();
        //用unordered_map来存储水果的种类和数量
        unordered_map<int, int> basket;
        int result = 0;
        for(; right < size; ++right){
            ++basket[fruits[right]];
            while(basket.size() > 2){
                auto it = basket.find(fruits[left]);
                --it->second;
                if(it->second == 0){
                    basket.erase(it);
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
```

自我觉得这道题有两个难点：

- 第一个就是原题为应用题，而且我总感觉他的题目描述不准确，说都没说清楚。要是转变为求一个数组里的最长子数组，并且这个子数组的元素种类最多为两个，就清洗易懂了。
- 其次就是如何将元素种类进行存储，采用unordered_map十分好，保证了最多篮子有两个。
- 其次就是滑动窗口的思想了。感觉求子数组都可以用滑动窗口。

# 76.**最小覆盖子串**

```cpp
class Solution {
public:
    //检查是否满足left左移条件
    bool check(unordered_map<char, int> &dict){
        for(const auto &p : dict){
            if(p.second > 0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        for(auto &c : t){
            ++dict[c];
        }
        int left = 0, right = 0;//滑动窗口的左右边界
        int size = s.size();//字符串s的长度
        int length = INT32_MAX;//最小子串的长度
        int result = 0;//最小子串的起始位置
        for(; right < size; ++right){
            if(dict.find(s[right]) != dict.end()){
                --dict[s[right]];
            }
            while(check(dict)){
                //每次找到新的最小字串记得保存他的起始位置和长度
                if(length > right - left + 1){
                    length = right - left + 1;
                    result = left;
                }
                if(dict.find(s[left]) != dict.end()){
                    ++dict[s[left]];
                }
                ++left;                
            }
        }
        return length == INT32_MAX ? string() : s.substr(result, length);

    }
};
```

这道题最主要的核心就是也要用一个undermap保存待查找的字串t的所有字符和他的个数。

我犯了一个错误就是没有及时保存符合条件的起始位置。

因为找到当前字串的位置后，滑动窗口的起始位置和结束位置都有可能变化。

第一道困难题，还是ok的。

# 54.螺旋矩阵

```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
				if (array.size() == 0 || array[0].size() == 0) {
				            return {};
				        }
        int row = matrix.size();
        int col = matrix[0].size();
        int startX = 0;
        int startY = 0;
        int offset = 1;
        vector<int> result;
        for(int count = 0; count < row * col;){
            //上边
            for(;startY < col - offset; ++startY){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            //右边
            for(;startX < row - offset; ++startX){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            //下边
            for(;startY >= offset; --startY){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            //左边
            for(;startX >= offset; --startX){
                if(count >= row * col)
                    break;
                result.push_back(matrix[startX][startY]);
                ++count;
            }
            if(col == row && col % 2 == 1 && count == row * col - 1){
                result.push_back(matrix[col / 2][row / 2]);
                ++count;
            }
            ++startX;
            ++startY;
            ++offset;

        }

        return result;
    }
};
```

使用的是代码随想录中59的内容。

- 除了加入判断奇数正方形最后的判断条件。
- 对于每个for循环，都要检查count的次数。
- 加入输入为空的判断～

这两个都是我遗忘的～

# 总结

总的来说，数组主要就是四种类型：

- **二分法**，最经典的我背的是左闭右闭的解法，二分法时间复杂度：O(logn)。包括题目704、35、34、69、367。
- **双指针法**，双指针法（快慢指针法）：**通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。**暴力解法时间复杂度：O(n^2)双指针时间复杂度：O(n)。双指针法（快慢指针法）在数组和链表的操作中是非常常见的，很多考察数组和链表操作的面试题，都使用双指针法。包括题目26、283、844、977。
- **滑动窗口**。暴力解法时间复杂度：O(n^2)滑动窗口时间复杂度：O(n)。**滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将O(n^2)的暴力解法降为O(n)。滑动窗口感觉本质上也是一种特殊的双指针。**包括题目904、76
- **模拟行为。**最经典的螺旋矩阵，建议背下来。包括题目54。