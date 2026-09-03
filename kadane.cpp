#include <bits/stdc++.h>
using namespace std;
// Brute Force O(N^2)
// int Kadanes(vector<int> &arr)
// {
//     int n=arr.size();

//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++)
//     {   int sum=0;
//         for(int j=i;j<n;j++)
//         {
//             sum+=arr[j];
//             maxi=max(sum,maxi);
//         }
//     }

//     return maxi;

// }

// Optimal Approach (Kadane's Algorithm)
int Kadanes(vector<int> &arr)
{
    int n = arr.size();

    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        
        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    // int n;
    // cin >> n;
    vector<int> arr = {5, 4, 1, 7, 8};

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    int maxiSum = Kadanes(arr);
    cout << maxiSum;
    return 0;
}