# https://level.goorm.io/exam/174924/%EC%97%B0%EC%86%8D-%EC%A0%90%EC%88%98/quiz/1
# Date: 2026-10-06 21:25:32

'''
					:: 큰 점수 받기 ::
	[ 문제 조건 ]
	N개의 문제를 순서대로 풀 때, 큰 점수를 받는 법을 구한다.
	i번 문제를 맞추면 Si점을 얻는다. 이때 점수를 받는법이 있다.
	1. i번 문제를 해결하고 Si점을 받고 끝낸다.
	2. 번호가 연속하고, 점수도 1씩 연속적으로 증가 할 때,
	   이 문제들을 푼 점수를 모두 받는다.

	[ 입력 ]
	첫째 줄에 N이 주어진다.
	그 다음 줄애 S1, S2, ... , SN이 순서대로 공백을 두고 주어진다.

	[ 변수 조건 ]
	N (1 - 10_000) $ Si (1 - 20_000)
'''

def calc(n, arr):
	max_value = max(arr)

	current = arr[0]
	fvalue = 0
	for i in range(1, n):
		if arr[i] == arr[i - 1] + 1:
			current += arr[i]
		else:
			current = arr[i]

		fvalue = max(fvalue, current)

	# return fvalue < max_value ? max_value : fvalue
	return max_value if max_value > fvalue else fvalue
	


n = int(input())

arr = list(map(int, input().split()))

print(calc(n, arr))
