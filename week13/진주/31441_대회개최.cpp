#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 100001;

struct Problem {
	int diff, type;
};

int N, K;
vector<Problem> prbs;
int typeCnt[1001];
int totalTypes = 0;

int main() {
	cin.tie(0)->ios_base::sync_with_stdio(false);
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int d;
			cin >> d;
			prbs.push_back({ d, i });
		}
	}

	sort(prbs.begin(), prbs.end(), [](Problem a, Problem b) {
		return a.diff < b.diff;
	});

	int st = 0;
	int ed = 0;
	int minDiff = MAX;

	while (ed < prbs.size()) {
		if (typeCnt[prbs[ed].type] == 0) totalTypes++;
		typeCnt[prbs[ed].type]++;

		// 모든 type 포함되었을 때, 최소 난이도 차이 구하기
		while (totalTypes == N) {
			minDiff = min(minDiff, prbs[ed].diff - prbs[st].diff);

			typeCnt[prbs[st].type]--;
			if (typeCnt[prbs[st].type] == 0) totalTypes--;
			st++;
		}
		ed++;
	}

	cout << minDiff << "\n";
	return 0;
}
