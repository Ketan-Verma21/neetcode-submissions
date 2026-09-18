class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (char c : s1) {
            cnt1[c - 'a']++;
        }

        int l = 0;

        for (int r = 0; r < m; r++) {
            cnt2[s2[r] - 'a']++;

            if (r - l + 1 > n) {
                cnt2[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == n && cnt1 == cnt2) {
                return true;
            }
        }

        return false;
    }
};
