class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        for (vector<int>::iterator i = height.begin(); i < height.end(); i++)
        {
            // find l and r max
            int lMax = *max_element(height.begin(), i + 1);
            int rMax = *max_element(i, height.end());

            // up ans
            ans += min(lMax, rMax) - *i;
        }

        return ans;
    }
};
