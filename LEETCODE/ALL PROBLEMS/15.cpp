#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define loop(i, k, n) for (auto i = k; i <= n; ++i)
#define rloop(i, k, n) for (auto i = k; i >= n; --i)
#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
int input()
{
    int temp;
    cin >> temp;
    return temp;
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        map<string, vector<int>> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        string key = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
                        m[key] = {nums[i], nums[j], nums[k]};
                    }
                }
        vector<vector<int>> ans;
        for (auto a : m)
            ans.push_back(a.second);
        return ans;
    }
};

void solve()
{
}


int main()
{
    FAST_IO;
    int tc = input();
    for (int t = 1; t <= tc; t++)
        solve();
    return 0;
}