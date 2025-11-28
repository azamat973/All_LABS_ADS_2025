#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll,int>>> add(n + 2);
    vector<vector<int>> rem(n + 2);
    vector<ll> cost(m);
    vector<int> L(m), R(m);

    for (int i = 0; i < m; i++) {
        int l, r;
        ll c;
        cin >> l >> r >> c;

        L[i] = l;
        R[i] = r;
        cost[i] = c;

        if (l <= n) add[l].push_back({c, i});
        if (r <= n) rem[r].push_back(i);
    }

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    vector<char> ended(m, 0);
    ll ans = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int id : rem[i]) ended[id] = 1;
        for (auto &p : add[i]) pq.push(p);

        while (!pq.empty() && ended[pq.top().second])
            pq.pop();

        ans += pq.top().first;
    }

    cout << ans << "\n";
    return 0;
}
