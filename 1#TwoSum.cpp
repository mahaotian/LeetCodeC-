#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
            if (result.size() > 0)
                break;
        }
        return result;
    }
};

int main() {
    int nums[] = {2, 7, 11, 15}, target = 9;
    size_t count = sizeof(nums) / sizeof(int);
    vector<int> ivec(nums, nums + count);
    Solution solution;
    vector<int> result = solution.twoSum(ivec, target);
    for (int i = 0; i < result.size(); i++) {
        if (i != 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}
