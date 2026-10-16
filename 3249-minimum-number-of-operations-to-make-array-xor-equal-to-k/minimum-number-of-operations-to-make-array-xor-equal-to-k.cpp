class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorSum ^= nums[i];
        }

        int diff = xorSum ^ k;
        int count = 0;

        while (diff > 0) {
            count += diff & 1;
            diff >>= 1;
        }

        return count;
    }
};