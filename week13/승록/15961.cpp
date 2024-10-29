// 투 포인터의 변종인 슬라이딩 윈도우를 이용해 범위를 고정하고 이동시켜 가면서 보면 된다.
// 추가로 먹을 수 있는 초밥은 항상 세어주고 나머지는 범위에 따라 넣었다 뻈다 해주자.
#include <bits/stdc++.h>
using namespace std;

int N, D, K, C, rail[3000003], sushi[3003];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> D >> K >> C;
    sushi[C]++;
    for (int i = 0; i < N; i++) cin >> rail[i];

    int cnt = 1;
    for (int i = 0; i < K; i++) {
        if (!sushi[rail[i]]++) cnt++;
    }
    int ans = cnt;
    for (int i = 0; i < N; i++) {
        if (!--sushi[rail[i]]) cnt--;
        if (!sushi[rail[(i + K) % N]]++) cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}