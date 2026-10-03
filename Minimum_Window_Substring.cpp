#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();
    if (m > n)
        return "";

    vector<int> hash(256, 0);
    for (char c : t)
        hash[c]++;

    int count = 0, l = 0, r = 0;
    int minLen = INT_MAX, startIndex = -1;

    while (r < n)
    {
        if (hash[s[r]] > 0)
            count++;
        hash[s[r]]--;

        while (count == m)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                startIndex = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0)
                count--;
            l++;
        }
        r++;
    }

    return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << minWindow(s, t) << endl;
    return 0;
}
