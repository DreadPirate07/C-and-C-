// https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=list&envId=xlere2g3

#include <bits/stdc++.h>
using namespace std;

// string getAnswers(char a)
// {
//     if (a == '2')
//         return "abc";
//     else if (a == '3')
//         return "def";
//     else if (a = '4')
//         return "ghi";
//     else if (a = '5')
//         return "jkl";
//     else if (a = '6')
//         return "mno";
//     else if (a = '7')
//         return "pqrs";
//     else if (a = '8')
//         return "tuv";
//     else if (a = '9')
//         return "wxyz";
//     return "";
// }

// void return_result(string data, vector<string> &result, int index, string temp)
// {
//     if (index == data.length())
//         result.push_back(temp);

//     string temp_str = getAnswers(data[index]);
//     for (int i = 0; i < temp_str.size(); i++)
//     {
//         return_result(data, result, index + 1, temp + temp_str[i]);
//     }
// }

// vector<string> letterCombinations(string digits)
// {
//     if (digits.length() == 0)
//         return {};
//     vector<string> result;
//     return_result(digits, result, 0, "");
//     return result;
// }

string func1(char x)
{
    if (x == '2')
        return "abc";
    else if (x == '3')
        return "def";
    else if (x == '4')
        return "ghi";
    else if (x == '5')
        return "jkl";
    else if (x == '6')
        return "mno";
    else if (x == '7')
        return "pqrs";
    else if (x == '8')
        return "tuv";
    else if (x == '9')
        return "wxyz";
    return "";
}
void solve(string digits, vector<string> &result, int index, string ans)
{
    if (index == digits.length())
        result.push_back(ans);

    string temp = func1(digits[index]);
    for (int i = 0; i < temp.length(); i++)
    {
        solve(digits, result, index + 1, ans + temp[i]);
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
        return {};
    vector<string> result;
    solve(digits, result, 0, "");
    return result;
}

int main()
{
    string s = "23";
    vector<string> result = letterCombinations(s);
}