#include <string.h>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildBinaryTree(const std::vector<int> &nums, int index)
    {
        if (index >= nums.size() || nums[index] == 0)
            return nullptr;

        TreeNode *root = new TreeNode(nums[index]);
        root->left = buildBinaryTree(nums, 2 * index + 1);
        root->right = buildBinaryTree(nums, 2 * index + 2);

        return root;
    }

    int minDepth(TreeNode *root)
    {
        
        return 0;
    }
};

int main()
{
    
    Solution SolutionObj;
    std::vector<int> nums = {3, 9, 20, 0, 0, 15, 7};
    
    SolutionObj.minDepth(SolutionObj.buildBinaryTree(nums, 0));
    return 0;
}