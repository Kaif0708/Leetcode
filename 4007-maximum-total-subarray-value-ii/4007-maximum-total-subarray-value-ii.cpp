class Solution {
public:
    
    long long maxTotalValue(vector<int>& nums, int k) {
        auto arrCopy = nums;
        int n = arrCopy.size();

        vector<int> prevGreater(n, -1), nextGreater(n, n), prevSmaller(n, -1), nextSmaller(n, n);
        {
            vector<int> st;
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && arrCopy[st.back()] <= arrCopy[i]) st.pop_back();
                prevGreater[i] = st.empty() ? -1 : st.back();
                st.push_back(i);
            }

            st.clear();
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && arrCopy[st.back()] < arrCopy[i]) st.pop_back();
                nextGreater[i] = st.empty() ? n : st.back();
                st.push_back(i);
            }

            st.clear();
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && arrCopy[st.back()] >= arrCopy[i]) st.pop_back();
                prevSmaller[i] = st.empty() ? -1 : st.back();
                st.push_back(i);
            }

            st.clear();
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && arrCopy[st.back()] > arrCopy[i]) st.pop_back();
                nextSmaller[i] = st.empty() ? n : st.back();
                st.push_back(i);
            }
        }

        vector<int> idxMax(n), idxMin(n);
        iota(idxMax.begin(), idxMax.end(), 0);
        iota(idxMin.begin(), idxMin.end(), 0);

        sort(idxMax.begin(), idxMax.end(), [&](int i, int j) {
            return arrCopy[i] != arrCopy[j] ? arrCopy[i] > arrCopy[j] : i < j;
        });
        sort(idxMin.begin(), idxMin.end(), [&](int i, int j) {
            return arrCopy[i] != arrCopy[j] ? arrCopy[i] < arrCopy[j] : i < j;
        });

        auto countSubarrays = [&](int i, int j) -> long long {
            int leftBound = max(prevGreater[i] + 1, prevSmaller[j] + 1);
            int rightBound = min(nextGreater[i] - 1, nextSmaller[j] - 1);
            int L = min(i, j), R = max(i, j);
            long long leftWays = max(0, L - leftBound + 1);
            long long rightWays = max(0, rightBound - R + 1);
            return leftWays * rightWays;
        };

        using State = tuple<long long, int, int>;
        priority_queue<State> pq;
        unordered_set<long long> visited; visited.reserve(k * 4 + 16);

        auto enqueue = [&](int i, int j) {
            if (i >= n || j >= n) return;
            long long key = ((long long)i << 32) | j;
            if (visited.insert(key).second) {
                long long diff = (long long)arrCopy[idxMax[i]] - (long long)arrCopy[idxMin[j]];
                pq.emplace(diff, i, j);
            }
        };

        enqueue(0, 0);
        long long ans = 0;

        while (k > 0 && !pq.empty()) {
            auto [diff, im, jm] = pq.top(); pq.pop();
            int i = idxMax[im], j = idxMin[jm];
            long long count = 0;
            if (arrCopy[i] >= arrCopy[j]) count = countSubarrays(i, j);

            if (count > 0 && diff >= 0) {
                long long take = min<long long>(k, count);
                ans += diff * take;
                k -= (int)take;
                if (k == 0) break;
            }

            enqueue(im + 1, jm);
            enqueue(im, jm + 1);
        }

        return ans;
    }
};