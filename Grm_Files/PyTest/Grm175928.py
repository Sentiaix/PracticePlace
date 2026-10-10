# https://level.goorm.io/exam/175928/%EA%B7%9C%EC%B9%99-%EC%88%AB%EC%9E%90-%EC%95%BC%EA%B5%AC/quiz/1
# Date: 2026-10-09 16:25:04

# https://swexpertacademy.com/main/main.do 

"""
                        :: 규칙 숫자 야구 ::
    기존 숫자 야구와 다르게,
    4자리 숫자를 입력받아 정답인
    4자리 숫자와 동일하게 만든다.
    그 과정은 아래에 정해진 규칙에 따라
    수행하여야 하며, 총 동작수를 출력한다.

                        = 정렬 알고리즘 =
    1. 정답과 입력을 비교하여 S/B/F중 어떤 상태인지 확인한다.
        이 과정에서 정답과 일치하다면 결과를 출력하고 코드를 중지한다.
    2. 현재 입력의 가장 왼쪽 자리부터 순서대로 아래를 반복한다.
            1. 현재 자리가 Strike라면 pass
            2. 현재 자리의 값(v)이 Fail이라면,
                    v = (v + 1) % 10 를 수행한다.
                    만약 새 v가 다른 자리에 존재한다면, 존재하지 않을때가지 한다.
    3. 2번 과정에서 Ball이 있었다면, 판단 결과 중에서 Strike를
        제외한 나머지 자리를 모두 오른쪽으로 1칸 옮긴다.
        옮길 자리가 없는 경우, Strike가 아닌 가장 왼쪽 자리로 옮긴다.

    [ 입력 ]
    첫째 줄에 정답이 주어진다.
    둘째 줄에 초기입력이 주어진다.
    (모든 입력은 서로 다른 수로 구성된 4자리 정수이며
    , 0이상 9이하 숫자들로 구성된다.)

    [ 변수 조건 ]

"""

def shift(arr, status):
    # arr1: 정답
    # arr2: 현재 입력

    idx = [i for i in range(4) if status[i] != 'S']

    if len(idx) <= 1:
        return

    temp = arr[:] # shallow copy

    for k in range(len(idx)):
        arr[idx[(k + 1) % len(idx)]] = temp[idx[k]]



answer = list(map(int, input()))
userInput = list(map(int, input()))

Reps = 0 # 동작 횟수 저장

while True:
    Reps += 1

    # 정답이면 종료
    if answer == userInput:
            break

    # 작업1: 현재 입력상태 확인
    status = []

    for i in range(4):
        if answer[i] == userInput[i]:
            status.append('S')
        elif userInput[i] in answer:
            status.append('B')
        else:
            status.append('F')

    # 작업 2: Ball이 있다면 Strike아닌 자리이동시키기 작업 수행
    hasBall = 'B' in status

    for i in range(4):
        if status[i] == 'S':
            continue
        if status[i] == 'F':
            while True:
                userInput[i] = (userInput[i] + 1) % 10

                if all(
                    userInput[i] != userInput[j]
                    for j in range(4)
                    if i != j
                ):
                    break

    if hasBall:
        shift(userInput, status)
                        

print(Reps)