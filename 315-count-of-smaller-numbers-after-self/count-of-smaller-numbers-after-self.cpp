class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        mergeSort(arr, result, 0, n - 1);

        return result;
    }

private:
    void mergeSort(vector<pair<int, int>>& arr,
                   vector<int>& result,
                   int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, result, left, mid);
        mergeSort(arr, result, mid + 1, right);

        merge(arr, result, left, mid, right);
    }

    void merge(vector<pair<int, int>>& arr,
               vector<int>& result,
               int left, int mid, int right) {
        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;
        int rightSmaller = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                rightSmaller++;
                j++;
            } else {
                result[arr[i].second] += rightSmaller;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            result[arr[i].second] += rightSmaller;
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }
};