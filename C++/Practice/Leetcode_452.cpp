// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=daily-question&envId=2024-03-18

#include <bits/stdc++.h>
using namespace std;
// static is used over here so as to invoke the function without passing/creating the object.
// lambda function can also be used over here as
/* std::sort(point.begin(),point.end(),[](const vector<int> v0 , const vector<int> v1){
    return v0[0] < v1[0]
    });
})*/

static bool customsort(const vector<int> &v1, const vector<int> &v2)
{
    return (v1[0] < v2[0]);
}

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), customsort);
    int count = 1;
    for (auto &it : points)
    {
        for (auto &cs : it)
        {
            std::cout << cs << " ";
        }
        std::cout << std::endl;
    }
    auto it = points.begin();
    int min_end = it->at(1);
    while (it != points.end())
    {
        if (it->at(0) > min_end)
        {
            count++;
            min_end = it->at(1);
        }
        else
        {
            min_end = std::min(min_end, it->at(1));
        }
        it++;
    }
    return count;
}

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    std::cout << findMinArrowShots(points);
}