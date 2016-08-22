#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        int plus = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            res.insert(res.begin(), (digits[i] + plus) % 10);
            plus = (digits[i] + plus) / 10;
        }
        if (plus != 0)
            res.insert(res.begin(), plus);
        return res;
    }
};

int main() {
    int nums[] = {2, 9, 9};
    size_t count = sizeof(nums) / sizeof(int);
    vector<int> ivec(nums, nums + count);
    Solution solution;
    vector<int> res = solution.plusOne(ivec);
    for (int i = 0; i < res.size(); i++) {
        if (i != 0)
            cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}
