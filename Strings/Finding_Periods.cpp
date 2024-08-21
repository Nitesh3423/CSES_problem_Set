#include "bits/stdc++.h"
using namespace std;

#define ll long long

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pb push_back
#define sz(a) (ll) a.size()
#define sti size_t

void solve()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    vector<int> sums;
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> temp;
        temp.push_back(nums[i]);
        for (int j = i + 1; j < n; j++)
        {
            temp.push_back(temp[temp.size() - 1] + nums[j]);
        }
        sums.insert(sums.end(),temp.begin(),temp.end());
    }
    sums.push_back(nums[n-1]);
    sort(all(sums));
    for(int it:sums){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
