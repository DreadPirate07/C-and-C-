// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int slen = s.size();
    int plen = p.size();
    vector<int> answer;
    int psize = 0;
    int ssize = 0;
    int index = 0;

    for (int i = 0; i < plen; i++)
    {
        psize += static_cast<int>(p[i]);
        ssize += static_cast<int>(s[i]);
    }
    if (plen == slen)
        answer.push_back(index);
    for (int i = plen; i < slen; i++)
    {
        ssize += (int)(s[i]);
        ssize -= (int)(s[i - plen]);
        if (ssize == plen)
            answer.push_back(i - plen);
    }
    return answer;
}