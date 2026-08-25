class Solution {
public:

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        int m = nums2.size();

        auto solve = [&](int k, vector<int>& a) -> vector<int> {

            int n1 = a.size();

            if (k > n1)
                return {};

            vector<int> ans;

            int drop = n1 - k;

            for (int i = 0; i < n1; i++) {

                while (!ans.empty() &&
                       a[i] > ans.back() &&
                       drop > 0) {

                    ans.pop_back();
                    drop--;
                }

                ans.push_back(a[i]);
            }

            while (ans.size() > k)
                ans.pop_back();

            return ans;
        };

        auto merge = [&](vector<int>& temp,
                         vector<int>& a,
                         vector<int>& b) {

            int n1 = a.size();
            int m1 = b.size();

            int i = 0;
            int j = 0;

            while (i < n1 && j < m1) {

                if (lexicographical_compare(
                        b.begin() + j, b.end(),
                        a.begin() + i, a.end()
                    )) {

                    temp.push_back(a[i]);
                    i++;
                }
                else {
                    temp.push_back(b[j]);
                    j++;
                }
            }

            while (i < n1) {
                temp.push_back(a[i]);
                i++;
            }

            while (j < m1) {
                temp.push_back(b[j]);
                j++;
            }
        };

        vector<int> ans;

        for (int i = max(0, k - m); i <= min(k, n); i++) {

            vector<int> temp1 = solve(i, nums1);

            vector<int> temp2 = solve(k - i, nums2);

            vector<int> temp;

            merge(temp, temp1, temp2);

            ans = max(ans, temp);
        }

        return ans;
    }
};