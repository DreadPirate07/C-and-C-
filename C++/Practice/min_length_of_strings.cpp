// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s)
{
    string str = s;
    int l = 0;
    int r = str.size() - 1;
    while (l < r)
    {
        if (str[l] != str[r])
        {
            break;
        }
        else
        {
            while (str[l] == str[r])
            {
                if (r == l)
                    break;
                std::cout << " String: " << l << " " << r << " : " << str.substr(l, r - l + 1) << std::endl;
                std::cout << "Count : " << (r - l + 1) << std::endl;
                if (str[l + 1] == str[r])
                {
                    l++;
                    continue;
                }
                else if (str[l] == str[r - 1])
                {
                    r--;
                    continue;
                }
                l++;
                r--;
            }
        }
    }
    return (r - l );
}

int main()
{
    string s = "cabaabac";
    int x = minimumLength(s);
    std::cout << x << std::endl;
}