#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    vector<TreeNode *> children;
    TreeNode() : val(-1), children({}){};
    TreeNode(int x) : val(x), children({}){};
    TreeNode(int x, vector<TreeNode *> children) : val(x), children(children){};
};

class Generic_Tree
{
public:
    TreeNode *root;
    Generic_Tree(vector<int> tree)
    {
        stack<TreeNode *> s;
        for (auto val : tree)
        {
            if (val == -1)
                s.pop();
            else
            {
                TreeNode *temp = new TreeNode(val);
                if (s.empty())
                    this->root = temp;
                else
                    s.top()->children.push_back(temp);
                s.push(temp);
            }
        }
    }
    void print(vector<int> nums)
    {
        for (auto a : nums)
            cout << a << " ";
        cout << "\n";
    }
    void preOrderPostOrderIterative()
    {
        stack<pair<TreeNode *, int>> s;
        s.push({root, -1});
        vector<int> pre, post;
        while (!s.empty())
        {
            auto curr = s.top();
            if (curr.second == -1)
            {
                pre.push_back(curr.first->val);
                curr.second++;
            }
            else if (curr.second < curr.first->children.size())
            {
                s.push({curr.first->children[curr.second], -1});
                curr.second++;
            }
            else
            {
                post.push_back(curr.first->val);
                s.pop();
            }
        }
        print(pre);
        print(post);
    }
};

void print(TreeNode *root)
{
    if (!root)
        return;
    string level = to_string(root->val) + " -> ";
    for (auto child : root->children)
        level += to_string(child->val) + ", ";
    cout << level << endl;
    for (auto child : root->children)
        print(child);
}

int main()
{
    vector<int> tree = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 170, -1, -1, -1};
    Generic_Tree mtree(tree);
    print(mtree.root);
    return 0;
}
