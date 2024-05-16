class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //1,为0返回nullptr
        if(preorder.size() == 0) return nullptr; 

        //2.找root的值
        int root_value = *preorder.begin();
        TreeNode* root = new TreeNode(root_value);
        if(preorder.size() == 1) return root;

        //3.在中序列找到
        auto split_index = inorder.begin();
        for(split_index = inorder.begin(); split_index != inorder.end(); ++split_index){
            if(*split_index == root_value) break;
        }

        cout << "split_index: " << root_value << endl;
        //4.切割中序数组
        vector<int> left_inorder(inorder.begin(), split_index);
        vector<int> right_inorder(split_index + 1, inorder.end());

        //5.切割前序数组
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        vector<int> right_preorder(preorder.begin() + left_inorder.size() + 1, preorder.end());

        cout << "_________________________  " << endl;
        cout << "left_inorder: ";
        for(auto i : left_inorder){
            cout << i << " ";
        }
        cout << endl;

        cout << "right_inorder: ";
        for(auto i : right_inorder){
            cout << i << " ";
        }
        cout << endl;

        cout << "left_preorder: ";
        for(auto i : left_preorder){
            cout << i << " ";
        }
        cout << endl;

        cout << "right_preorder: ";
        for(auto i : right_preorder){
            cout << i << " ";
        }
        cout << endl;
        root->left = buildTree(left_inorder, left_preorder);
        root->right = buildTree(right_inorder, right_preorder);

        return root;
    }
};