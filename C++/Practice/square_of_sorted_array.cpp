#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    if (nums.size() == 0)
        return {};
    std::cout << "Nums size: " << nums.size() << std::endl;
    vector<int> squaresorted;
    for (int i = 0; i < nums.size(); i++)
    {
        int square = nums[i] * nums[i];
        squaresorted.push_back(square);
        std::cout << square << std::endl;
    }
    sort(squaresorted.begin(), squaresorted.end());
    return squaresorted;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ansarr = sortedSquares(nums);
    for (auto &it : ansarr)
    {
        std::cout << it << std::endl;
    }
}