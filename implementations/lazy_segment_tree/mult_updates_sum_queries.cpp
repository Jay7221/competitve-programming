struct LazySegmentTree {
    int n;
    vector<ll> L, R, lazy, val;

    LazySegmentTree(int sz) {
        n = 4 * sz;
        L.resize(n);
        R.resize(n);
        lazy.resize(n);
        val.resize(n);
        n >>= 1;
        init(1, 0, sz - 1);
    }

    void init(int node, int l, int r) {
        if (l > r) {
            return;
        }
        L[node] = l;
        R[node] = r;
        if (l < r) {
            int mid = (l + r) / 2;
            init(2 * node, l, mid);
            init(2 * node + 1, mid + 1, r);
        }
    }

    void propagate(int node) {
        if (L[node] < R[node]) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            val[2 * node] += lazy[node] * (R[2 * node] - L[2 * node] + 1);
            val[2 * node + 1] += lazy[node] * (R[2 * node + 1] - L[2 * node + 1] + 1);
            lazy[node] = 0;
        }
    }

    void set(int node, int l, int r, ll x) {
        if (r < L[node] || R[node] < l) {
            return;
        }
        if (l <= L[node] && R[node] <= r) {
            lazy[node] += x;
            val[node] += x * (R[node] - L[node] + 1); // Updating sum for range
        } else {
            propagate(node);
            set(2 * node, l, r, x);
            set(2 * node + 1, l, r, x);
            val[node] = val[2 * node] + val[2 * node + 1];
        }
    }

    ll get(int node, int l, int r) {
        if (r < L[node] || R[node] < l) {
            return 0; // Out of range
        }
        if (l <= L[node] && R[node] <= r) {
            return val[node];
        }
        propagate(node);
        ll left_sum = get(2 * node, l, r);
        ll right_sum = get(2 * node + 1, l, r);
        return left_sum + right_sum;
    }
};

