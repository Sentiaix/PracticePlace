# https://level.goorm.io/exam/175018/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98-%EC%88%98/quiz/1
# Date: 2026-10-03 23:22:05

"""
    Fibonacci Sequence를 구현
    피보나치 수열의 n번째 값을 F(n)이라 하면
    F(1) = 0, F(2) = 1,
    F(n) = F(n-1) + F(n-2), (n>2) 이 성립한다.

    이때 K(1-100_000)이 주어지면 F(K)를
    "1_000_000_007"로 나누어 출력.
"""

MOD = 1_000_000_007

# -- 재귀함수 형식 --
# def f(n):
#     if n <= 2:
#         retrun n - 1

#     return f(n - 1) + f(n - 2)

def f(n):
    if n <= 2:
        return n - 1

    a = 0 # a is F(n+1)
    b = 1 # b is F(n)

    """
        F(N) = F(N-1) + F(N-2)을
        F(N+1) = F(N) + F(N-1)로 변형
    """
    for _ in range(n - 1):
        a, b = b, a + b

    return a


""" _____ main _____ """

k = int(input())

print(f(k) % MOD)