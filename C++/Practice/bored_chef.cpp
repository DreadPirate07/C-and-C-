#include <bits/stdc++.h>
using namespace std;
int boredChef(int n, int k, string s)
{
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        std::cout << count[i];
    }

    std::cout << "\n";
    for (int i = 0; i < 26; i++)
    {
        if (count[i] >= k)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string s = "zzzzz";
    int n = boredChef(5, 3, s);
    cout << n << endl;
}