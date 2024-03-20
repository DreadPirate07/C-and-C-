// https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14

#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int l = 0;
    int r = 0;
    int sum = 0;
    int count = 0;

    for (l = 0; l < nums.size(); l++)
    {
        for (r = l; r < nums.size(); r++)
        {
            sum = 0;
            for (int i = l; i <= r; i++)
            {
                sum += nums[i];
            }
            // std::cout << "Sum : " << sum << std::endl;
            if (sum == goal)
                count++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    std::cout << &nums << std::endl;
    int goal = 2;
    std::cout << numSubarraysWithSum(nums, goal) << std::endl;
}