#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE [ O(N^2) ]
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

    vector<int> ans = twoSum(n, target,arr);

    for (auto it : ans)
    {
        cout << it<<" ";
    }
    return 0;
}