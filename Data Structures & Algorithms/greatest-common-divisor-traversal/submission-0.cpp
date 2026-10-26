class DSU {
public:
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unite(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y) return;

        if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return true;

        int maxi = *max_element(nums.begin(), nums.end());

        if (*min_element(nums.begin(), nums.end()) == 1) {
            return false;
        }

        DSU ds(maxi + 1);

        for (int num : nums) {
            int original = num;

            for (int p = 2; p * p <= num; p++) {
                if (num % p == 0) {
                    ds.unite(original, p);

                    while (num % p == 0) {
                        num /= p;
                    }
                }
            }

            if (num > 1) {
                ds.unite(original, num);
            }
        }

        int root = ds.findParent(nums[0]);

        for (int num : nums) {
            if (ds.findParent(num) != root) {
                return false;
            }
        }

        return true;
    }
};