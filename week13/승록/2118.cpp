// 거리가 원형 상에 있으므로 두 탑 간의 최대 거리는 전체 거리 합을 N이라 했을 때 N / 2이다.
// 만일 이 거리를 넘어간다면, 반대편의 거리가 다시 최대 거리가 될 것이다.
// 이를 기준으로 투 포인터를 이용해 최댓값을 구한다.
#include <bits/stdc++.h>
using namespace std;

long long N, psum[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> psum[i], psum[i + N] = psum[i];
    for (int i = 1; i <= 2 * N; i++) psum[i] += psum[i - 1];

    long long ans = 0, md = psum[N] / 2, l = 0, r = 0;
    while (r <= 2 * N) {
        while (r - l <= N && psum[r] - psum[l] <= md) {
            ans = max(ans, psum[r] - psum[l]);
            r++;
        }
        l++;
    }

    cout << ans << '\n';
}