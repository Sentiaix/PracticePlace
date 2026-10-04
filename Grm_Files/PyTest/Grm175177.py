# https://level.goorm.io/exam/175177/%EA%B1%B0%EC%8A%A4%EB%A6%84-%EB%8F%88/quiz/1
# Date: 2026-10-03 22:44:04

"""
            :: 거스름 돈 구하기 ::
    1 | 5 | 10 | 20 | 40 단위의 화폐가 있다.
    금액 N(1-10^9)이 주어졌을때, 화폐를 가장 적게
    사용하여 거스름돈을 표현해라.
"""

charge = int(input())

amount = 0 # 화폐 개수

for coins in [40, 20, 10, 5, 1]:
    amount += charge // coins # '//' 정수형 몫만 반환
    charge %= coins

print(amount)