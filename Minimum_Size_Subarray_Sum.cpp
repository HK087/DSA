#include <bits/stdc++.h>
using namespace std;

// int GetMiniLen(vector<int> arr, int target)
// {
//     int n = arr.size();
//     int minLen = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == target)
//             {
//                 minLen = min(minLen, j - i + 1);
//             }
//         }
//     }

//     return minLen;
// }

// OPTIMAL APPROACH T.C => O()
// int GetMiniLen(vector<int> arr, int target)
// {
//     int n = arr.size();
//     int r, l = 0;
//     int flag = false;
//     int minLen = INT_MAX;
//     int sum = 0;

//     while (r < n)
//     {
        
//         sum += arr[r];
//         while (sum >= target)
//         {
//             minLen=min(minLen,r-l+1);
//             flag= true;
//             sum -= arr[l];
//             l++;
            
//         }
//         r++;
//     }
//     return (flag)?minLen: 0;
// }

int GetMiniLen(const vector<int>& arr, int target)
{
    int n = arr.size();
    int l = 0;
    long long sum = 0;          // long long avoids overflow
    int minLen = INT_MAX;

    for (int r = 0; r < n; r++)
    {
        sum += arr[r];                      // expand window
        while (sum >= target)               // shrink while still valid
        {
            minLen = min(minLen, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}
int main()
{
    int x, target;
    cin >> x >> target;
    vector<int> arr(x);
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }
    int miniLen = GetMiniLen(arr, target);
    cout << miniLen;

    return 0;
}