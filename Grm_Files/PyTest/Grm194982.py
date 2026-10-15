# https://level.goorm.io/exam/194982/%EC%9E%A5%EB%A7%88/quiz/1
# Date: 2026-10-11 20:02:36

"""
                :: 배수 시스템 구현 ::

    [ 문제 조건 ]
    1번부터 N개의 집이 순서대로 있다.
    집집마다 땅 높이가 달라서, i번째 집의 땅 높이는 ki이다.
    땅 높이 기준은 해수면이기 때문에, 음수도 가능하다.

    장마가 시작되면 M일동안 비가 온다.
    장마가 시작된지 i일이 되는 날에는 si부터 ei번 집까지 비가 내린다.
    비가 한 번 내리면 그 집에는 높이가 1만큼 증가하고,
    배수 시스템이 작동하기 전까지 물은 빠지지 않는다.

    배수 시스템은 장마시작일의 3의 배수날마다, 비가 내리고 작동한다.
    배수 시스템은 작동날짜를 기준으로 2일 이내에 비가 내린 위치에서만 작동한다.
    배수 시스템이 작동하면 그 집에 쌓인 물의 높이가 1 감소한다.
    예) 장마시작 9일째 작동하는 배수 시스템은, 7,8,9일째 비가 내린 집에만 작동.

    위 조건을 맞추어 장마가 온 뒤 집들의 높이를 출력하시오.

    [ 입력 ]
    첫째 줄에 집의 수N과 장마 기간M이 공백을 두고 주어진다.
    둘째 줄에 집 높이 k1,k2, ... ,kN이 공백을 두고 주어진다.
    다음 M개의 줄에는 si, ei가 공백을 두고 주어진다.
    (i번째 날에 si부터 ei번 집에 비가 내렸단 것이다.)

    [ 변수 조건 ]
    N (1 - 1_000) $ M (1 - 100_000) $ ki (-100_000 - 100_000)
    si,ei (1 - N)
    모든 변수는 정수이다.
"""

# 물 높이를 올리는 함수
def add_level(homes, s, e):
    # 집을 1번부터 세므로 list엔 s-1부터 접근해야함.
    for i in range(s - 1, e):
        homes[i] += 1

# 물 높이를 낮추는 함수
def lower_level(homes, rained):
        for i in rained:
            homes[i] -= 1


# 집의 수 N | 장마 기간 M
n, m = map(int, input().split())

# map(자료형, 연속가능한 값) >> Iterator 반환해서 tuple, list로 싸야함
homes = list(map(int, input().split()))

rained = set()

# 첫 날이 1일부터 시작함.
for days in range(1, m + 1):
    s, e = map(int, input().split())

    add_level(homes, s, e)

    # 집 번호가 1부터 시작하므로
    # list접근은 s-1부터 해야함
    for i in range(s - 1, e):
        rained.add(i)

    if days % 3 == 0:
        lower_level(homes, rained)
        rained.clear()

# * << unpacking 연산자
print(*homes)

# 내일 알아볼 것
# packing과 unpacking
# 기본 문자열 함수 다루기
# 기본 자료형 다루기
# list, tuple, set 등의 자료형 배우기