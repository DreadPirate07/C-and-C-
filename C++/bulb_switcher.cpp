// https://leetcode.com/problems/bulb-switcher/

#include <bits/stdc++.h>
using namespace std;

int bulbSwitch(int n)
{

    vector<int> bulbs(n, 1);
    int count = 0;

    for (int i = 1; i < n; i += 2)
    {
        bulbs[i] = 0;
    }

    for (int jump = 3; jump <= n - 1; jump++)
    {
        for (int k = jump - 1; k < n; k += jump)
        {
            if (bulbs[k] == 0)
                bulbs[k] = 1;
            else
                bulbs[k] = 0;
        }
    }
    if (bulbs[n - 1] == 1)
    {
        bulbs[n - 1] = 0;
    }
    else
        bulbs[n - 1] = 1;

    for (int i = 0; i < n; i++)
    {
        count += bulbs[i] > 0 ? 1 : 0;
    }
    return count;
}

int main()
{
    std::cout << bulbSwitch(5) << std::endl;
}