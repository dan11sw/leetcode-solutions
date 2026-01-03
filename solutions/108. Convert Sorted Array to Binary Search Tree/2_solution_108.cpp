#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    ~TreeNode() {
        if (left != nullptr) {
            delete left;
            left = nullptr;
        }

        if (right != nullptr) {
            delete right;
            right = nullptr;
        }
    }
};

class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int mid = (l + r) >> 1;
        return new TreeNode(nums[mid], dfs(nums, l, (mid - 1)), dfs(nums, (mid + 1), r));
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};

int main()
{
    std::vector<int> nums1{
        -10,-3,0,5,9
    };

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums1);

    while (root != nullptr) {
        std::cout << root->val << " ";
        root = root->right;
    }

    system("PAUSE");
    return 0;
}
