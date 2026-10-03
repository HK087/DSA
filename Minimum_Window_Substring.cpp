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

    // Getting the characters in t mapped to the hash vector.

    int count = 0, l = 0, r = 0;
    int minLen = INT_MAX, startIndex = -1;

    while (r < n)
    {
        if (hash[s[r]] > 0)
            count++;
        hash[s[r]]--;

        while (count == m)
        { // 1. Record the smallest valid window found so far.
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                startIndex = l;
            }
            // 2. Remove s[l] from the window by moving left pointer forward.
            hash[s[l]]++; // <-- KEY: "put back" the character.
            if (hash[s[l]] > 0) // <-- KEY: did we now need this char again?
                count--; //     if so, window is no longer valid
            l++; // move left pointer forward
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
