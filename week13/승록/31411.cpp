// 어차피 문제의 순서의 경우엔 임의의 순서대로 정렬이 된다.
// 주어진 식에 의하면, 그 값을 최소화하는 것은 난이도 순으로 정렬했을 때 x_n - x_1 을 최소화하는 것과 동치이다.
// 따라서, 모든 문제들을 난이도에 따라 정렬한 뒤, 종류별로 모든 문제를 포함하는지를 기준으로 투 포인터를 이용해 순회한다.
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> v, vis(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int x; cin >> x;
            v.push_back(x * N + i);
        }
    }
    sort(v.begin(), v.end());
    // 모든 문제에 대해 순회
    int cnt = 0, ans = 1e9 + 7;
    int l = 0, r = 0;
    while (r < N * K) {
        // 문제 종류별로 다 없을 때는 계속 r포인터 늘림
        while (r < N * K && cnt < N) {
            int xx = v[r] / N, ii = v[r] % N;
            if (!vis[ii]++) cnt++;
            r++;
        }
        // 갱신
        if (cnt >= N) ans = min(ans, v[r - 1] / N - v[l] / N);
        cnt -= !--vis[v[l++] % N];
    }

    cout << ans;
}