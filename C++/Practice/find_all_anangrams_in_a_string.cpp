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
        psize += static_cast<int>(p[i]-'a');
        ssize += static_cast<int>(s[i]-'a');
    }
    std::cout << psize << " " << ssize << std::endl;
    if (psize == ssize)
        answer.push_back(0);
    for (int i = plen; i < slen; i++)
    {
        ssize += (int)(s[i]-'a');
        ssize -= (int)(s[i - plen]-'a');
        std::cout << psize << " " << ssize << std::endl;

        if (ssize == psize)
            answer.push_back(i - plen + 1);
    }
    return answer;
}

int main()
{
    string s = "af", p = "be";
    vector<int> ans = findAnagrams(s, p);
    for (auto &it : ans)
    {
        std::cout << "Elements :";
        std::cout << it << std::endl;
    }
}