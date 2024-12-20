struct LazySegmentTree {
    const int LOGMAX = 30;
    int n;
    vector<int> lazy;
    vector<vector<int>> sum;
    vector<int> L, R;

    LazySegmentTree(vector<int>& arr) {
        int sz = arr.size();
        n = 1;
        while (n < sz) n <<= 1;
        lazy.assign(2 * n, 0);
        sum.assign(2 * n, vector<int>(LOGMAX, 0));
        L.assign(2 * n, 0);
        R.assign(2 * n, 0);


        // Initialize the segment tree leaves
        for (int i = 0; i < sz; ++i) {
            for (int k = 0; k < LOGMAX; ++k) {
                sum[i + n][k] = (arr[i] >> k) & 1;
            }
        }
        for(int i = 0; i < n; ++i){
            L[i + n] = R[i + n] = i;
        }

        // Build the segment tree
        for (int i = n - 1; i > 0; --i) {
            for (int k = 0; k < LOGMAX; ++k) {
                sum[i][k] = sum[2 * i][k] + sum[2 * i + 1][k];
            }
            L[i] = L[2 * i];
            R[i] = R[2 * i + 1];
        }
    }

    void apply(int node, int x) {
        for (int k = 0; k < LOGMAX; ++k) {
            if (x & (1 << k)) {
                sum[node][k] = (R[node] - L[node] + 1) - sum[node][k];
            }
        }
        if (node < n) {
            lazy[node] ^= x;
        }
    }

    void propagate(int node) {
        if (lazy[node]) {
            apply(2 * node, lazy[node]);
            apply(2 * node + 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node) {
        for (int k = 0; k < LOGMAX; ++k) {
            sum[node][k] = sum[2 * node][k] + sum[2 * node + 1][k];
        }
    }

    void rangeUpdate(int l, int r, int x) {
        l += n;
        r += n;
        int l0 = l, r0 = r;

        // Apply any existing lazy updates
        for (int i = __lg(n); i >= 1; --i) {
            if ((l >> i) > 0) propagate(l >> i);
            if ((r >> i) > 0) propagate(r >> i);
        }

        // Update the segment tree
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, x);
            if (!(r & 1)) apply(r--, x);
        }

        // Update affected parent nodes
        for (l = l0 >> 1; l > 0; l >>= 1) propagate(l), update(l);
        for (r = r0 >> 1; r > 0; r >>= 1) propagate(r), update(r);
    }


    long long rangeQuery(int l, int r) {
        l += n;
        r += n;
        long long res = 0;

        // Apply any existing lazy updates
        for (int i = __lg(n); i >= 1; --i) {
            if ((l >> i) > 0) propagate(l >> i);
            if ((r >> i) > 0) propagate(r >> i);
        }

        // Query the segment tree
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res += getSum(l++);
            if (!(r & 1)) res += getSum(r--);
        }

        return res;
    }

    long long getSum(int node) {
        long long result = 0;
        for (int k = 0; k < LOGMAX; ++k) {
            result += (1LL << k) * sum[node][k];
        }
        return result;
    }
};
