// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int length = nums.size();
    int sum = 0;
    int maxval = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    // std::cout << sum << std::endl;
    maxval = sum;
    for (int j = k; j < length; j++)
    {
        sum += nums[j];
        sum -= nums[j - k];
        maxval = max(sum, maxval);
        // std::cout << maxval << std::endl;
    }
    double ans = static_cast<double>(maxval) / k;
    return ans;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double ans = findMaxAverage(nums, k);
    std::cout << ans << std::endl;
}