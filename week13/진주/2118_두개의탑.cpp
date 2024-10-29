#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
ll ret = 0;
ll arr[100001];
ll preSum[100001];

int main() {
	cin.tie(0)->ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i+N] = arr[i];
	}

	for (int i = 1; i <= 2 * N; i++) {
		preSum[i] = preSum[i-1] + arr[i];
	}

	int st = 0;
	int ed = 0;
	ll target = preSum[N] / 2;

	while (ed <= 2*N) {
		ll tmp = preSum[ed] - preSum[st];

		while (ed - st <= N && tmp <= target) {
			ret = max(ret, tmp);
			ed++;
			tmp = preSum[ed] - preSum[st]; //tmp 재갱신
		}
		st++;
	}

	cout << ret;
	return 0;
}
