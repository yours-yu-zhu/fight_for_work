# 数组理论基础

## 需要注意的两点

- **数组下标都是从0开始的。**
- **数组内存空间的地址是连续的**

正是**因为数组的在内存空间的地址是连续的，所以我们在删除或者增添元素的时候，就难免要移动其他元素的地址。**

## 704. 二分查找

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

## 27. 移除元素

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
## 977.****有序数组的平方****

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
- 双指针方法，则是抓住**最大的元素一定是在数组的两端这个特点，**除此之外就没有难点了。

自己手撸代码时候出现了if(nums[i] * nums[i] < nums[j] * nums[j])这里刚开始写的没有平方来写
 