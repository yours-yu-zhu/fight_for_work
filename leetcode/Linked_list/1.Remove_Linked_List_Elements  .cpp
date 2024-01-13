#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode* tmp = head;
            head = head->next;
        }
    }
};


int main() {
    int target = 7;
    Solution a ;
    vector<vector<int>> result =  a.generateMatrix(3);
    for(int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size();j++)
        {
            cout<<result[i][j];
        }
    }
    return 0;
}
