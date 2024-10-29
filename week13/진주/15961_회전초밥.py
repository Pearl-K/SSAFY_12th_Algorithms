import sys
input = sys.stdin.readline

N, D, K, C = map(int, input().split())
arr = []

for i in range(N):
    arr.append(int(input()))

def solve():
    vst = [0] * (D+1)
    res, cnt = 0, 0

    for i in range(0, K):
        if vst[arr[i]] == 0:
            cnt += 1
        vst[arr[i]] += 1
    res = cnt

    for l in range(N):
        r = (l + K) % N
        front, back = arr[l], arr[r]

        vst[front] -= 1
        if vst[front] == 0:
            cnt -= 1
        vst[back] += 1
        if vst[back] == 1:
            cnt += 1

        if vst[C] == 0:
            res = max(res, cnt + 1)
        else:
            res = max(res, cnt)
        if res == K + 1:
            return res
    return res

print(solve())
