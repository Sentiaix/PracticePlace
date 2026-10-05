# // https://level.goorm.io/exam/174760/%EB%8B%A8%EC%96%B4-%ED%95%84%ED%84%B0/quiz/1
# Date: 2026-10-04 22:27:07

"""
                :: 단어 필터 만들기 ::
	첫째 줄에 검열할 단어 S의 길이와
	수신한 메세지 E의 길이가 공백을 두고 주어진다.

	둘째 줄에 단어 S가, 마지막 줄엔 메세지 E가 주어진다.

	이때 메세지 E에 검열단어 S가 포함된 경우,
	메세지 E에서 단어 S만 제거한 후 남은 글자들만 출력한다.

	(1 - S - E - 10_000), S와 E는 알파벳 대소문자만 사용한다.
"""

n, m = map(int, input().split())
s = input()
e = input()

answer = [] # 정답이 들어감


for letter in e:
    answer.append(letter)

    if len(answer) >= n:
        # ''.join() 사용법
        # '[구분자]'.join(list)
        if ''.join(answer[-n:]) == s:
            answer = answer[:-n]

if len(answer) == 0:
    print("EMPTY")
else :
    print(''.join(answer))