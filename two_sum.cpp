#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE T.C =>[ O(N^2) ]
vector<int> twoSum(int n, int target,vector<int>arr)
{
    for(int i =0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return {i,j};
            }
        }
    }
    return {-1};
}

//OPTIMISED APPROACH  T.C => [ O(N) ]
vector<int> twoSum(int n, int target, vector<int> arr)
{
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];

        if (seen.count(complement))
        {
            return {seen[complement], i};
        }
        seen[arr[i]] = i;
    }
    return {-1};
}

int main()
{
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = twoSum(n, target, arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}