// 제곱수 끼리의 차의 특성을 생각하면, 투 포인터로 처리가 가능하다.
// 범위에 주의해서 long long을 사용한다.
#include <bits/stdc++.h>
using namespace std;

long long G, sq[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> G;
    for (int i = 1; i < 100000; i++) sq[i] = 1LL * i * i;
    // 투 포인터를 이용해 G값을 기준으로 순회하면서 정답 벡터에 넣어준다.
    int l = 1, r = 1;
    vector<int> ans;
    while (r < 100000) {
        while (r < 100000 && sq[r] - sq[l] < G) r++;
        if (sq[r] - sq[l] == G) ans.push_back(r);
        l++;
    }
    
    if (ans.empty()) cout << -1 << '\n';
    for (const int &i: ans) cout << i << '\n';
}