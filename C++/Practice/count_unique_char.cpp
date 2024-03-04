#include <bits/stdc++.h>
using namespace std;

int uniqueLetterString(string s)
{
    int size = s.size();
    vector<string> sub_str_arr;
    int count = 0;

    // creating sub-strings and pushing to vector
    for (int i = 1; i < s.size(); i++)
    {

        for (int j = 0; j < s.size() - i; j++)
        {
            if (i-j !=0)
            {
                string str = s.substr(,i);
                sub_str_arr.push_back(str);
            }
        }
    }

    // debugging
    for (auto &it : sub_str_arr)
    {
        std::cout << it << std::endl;
    }

    for (auto &it : sub_str_arr)
    {
        vector<int> al_arr(26, 0);
        int sub_str_size = it.size();
        for (int i = 0; i < sub_str_size; i++)
        {
            if (al_arr[it[i] - 'a'] == 0)
            {
                al_arr[it[i] - 'a']++;
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
    string s = "ABC";
    int count = uniqueLetterString(s);
    // std::cout << count << std::endl;
}