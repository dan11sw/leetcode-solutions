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

static vector<int> slicing(vector<int>& arr, int X, int Y) {
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    vector<int> result(Y - X + 1);
    copy(start, end, result.begin());

    return result;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        std::size_t sizeNums = nums.size();

        std::cout << sizeNums << std::endl;

        if (!sizeNums) {
            return nullptr;
        }
        else if (sizeNums == 1) {
            return new TreeNode(nums.at(0));
        }
        else if (sizeNums == 2) {
            TreeNode* root = nullptr;

            if (nums[0] <= nums[1]) {
                root = new TreeNode(nums.at(0));
                root->right = new TreeNode(nums.at(1));
            }
            else {
                root = new TreeNode(nums.at(0));
                root->left = new TreeNode(nums.at(1));
            }

            return root;
        }

        std::size_t mid = (sizeNums / 2);
        TreeNode* root = new TreeNode(nums.at(mid));

        mid -= 1;
        vector<int> leftItems = slicing(nums, 0, mid);
        vector<int> rightItems = slicing(nums, (mid + 2), (sizeNums - 1));

        root->left = sortedArrayToBST(leftItems);
        root->right = sortedArrayToBST(rightItems);

        return root;
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
