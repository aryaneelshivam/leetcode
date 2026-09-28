#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if (count == 0) {
                element = nums[i];
            }
            if (nums[i] == element) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        
        return element;
    }
};
