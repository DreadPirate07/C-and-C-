// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/solutions/128952/java-c-python-one-pass-o-n/?envType=list&envId=xlep8di5

#include <bits/stdc++.h>
using namespace std;

int uniqueLetterString(string s)
{
    int size = s.size();
    vector<string> sub_str_arr;
    int count = 0;

    // creating sub-strings and pushing to vector
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j <= s.size(); j++)
        {
            if (1)
            {
                string str = s.substr(i, j - i);
                sub_str_arr.push_back(str);
            }
        }
    }

    for (string str : sub_str_arr)
        std::cout << str << " ";

    // // debugging
    // for (auto &it : sub_str_arr)
    // {
    //     std::cout << it << std::endl;
    // }

    for (auto &it : sub_str_arr)
    {
        vector<int> al_arr(26, 0);
        int sub_str_size = it.size();
        // std::cout << "Inside Array : " << it << " " << sub_str_size << std::endl;

        for (int i = 0; i < sub_str_size; i++)
        {
            // std::cout << "Inside array" << (static_cast<int>(it[i] - 'A')) << std::endl;
            if (al_arr[it[i] - 'A'] >= 0)
            {
                al_arr[it[i] - 'A']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (al_arr[i] == 1)
                count++;
        }
    }

    return count;
}

int main()
{
    string s = "LEETCODE";
    int count = uniqueLetterString(s);
    std::cout << count << std::endl;
}