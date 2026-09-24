// https://level.goorm.io/exam/195094/quartet/quiz/1
/*
---- 문제 해결 방법 ----

# 인접 다중 리스트 자료구조를 사용하는 법을 배운다 #

1. 인접 다중 리스트를 처리하는 구조를 구상한다.
	- 저장; 구조체 이용하여 호출
	- 처리; Queue나 Stack.. Stack이 좋은 방법같음

2. 모든 쌍을 2,3번 자리에 배치해서 조화도가 max인 경우를
   모두 테스트한다. (전수조사)

-- 문제 조건 --
학생 수 N(4-200,000), 시너지 수M(0-300,000)가 주어짐.
첫 줄에 N M이 주어지고 다음 줄부터 M개의 u v d(0-10e9)가 주어짐.
*/

#include <stdio.h>

#define MAX_N 200005
#define MAX_M 300005
#define MAX_E 600005
#define K 3

typedef struct {
    int u;
    int v;
    long long w;
} InputEdge;

typedef struct {
    int to;
    long long w;
    int next;
} Edge;

typedef struct {
    int to;
    long long w;
} Neighbor;

InputEdge input[MAX_M];
Edge edges[MAX_E];
Neighbor best[MAX_N][K];

int head[MAX_N];
int best_cnt[MAX_N];
int edge_cnt;

void add_edge(int u, int v, long long w);
void insert_best(int u, int v, long long w);
void build_best(int n);

long long solve_path3(int n);
long long solve_path2(int n);
long long solve_matching2(int m);

int main(void)
{
    int n, m;
    long long answer = 0;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        scanf("%d %d %lld", &u, &v, &w);

        input[i].u = u;
        input[i].v = v;
        input[i].w = w;

        add_edge(u, v, w);

        if (w > answer)
            answer = w;
    }

    build_best(n);

    long long value;

    value = solve_path3(n);
    if (value > answer)
        answer = value;

    value = solve_path2(n);
    if (value > answer)
        answer = value;

    value = solve_matching2(m);
    if (value > answer)
        answer = value;

    printf("%lld\n", answer);

    return 0;
}

void add_edge(int u, int v, long long w)
{
    edges[edge_cnt].to = v;
    edges[edge_cnt].w = w;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;

    edges[edge_cnt].to = u;
    edges[edge_cnt].w = w;
    edges[edge_cnt].next = head[v];
    head[v] = edge_cnt++;
}

void insert_best(int u, int v, long long w)
{
    int pos = -1;

    for (int i = 0; i < best_cnt[u]; i++) {
        if (best[u][i].to == v) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        if (w <= best[u][pos].w)
            return;

        best[u][pos].w = w;
    }
    else {
        if (best_cnt[u] < K) {
            pos = best_cnt[u];
            best_cnt[u]++;
        }
        else {
            int min_pos = 0;

            for (int i = 1; i < K; i++) {
                if (best[u][i].w < best[u][min_pos].w)
                    min_pos = i;
            }

            if (w <= best[u][min_pos].w)
                return;

            pos = min_pos;
        }

        best[u][pos].to = v;
        best[u][pos].w = w;
    }

    while (pos > 0 && best[u][pos].w > best[u][pos - 1].w) {
        Neighbor temp = best[u][pos];
        best[u][pos] = best[u][pos - 1];
        best[u][pos - 1] = temp;
        pos--;
    }
}

void build_best(int n)
{
    for (int i = 1; i <= n; i++)
        best_cnt[i] = 0;

    for (int u = 1; u <= n; u++) {
        for (int e = head[u]; e != -1; e = edges[e].next)
            insert_best(u, edges[e].to, edges[e].w);
    }
}

long long solve_path3(int n)
{
    long long answer = 0;

    for (int u = 1; u <= n; u++) {
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            long long middle = edges[e].w;

            for (int i = 0; i < best_cnt[u]; i++) {
                int a = best[u][i].to;
                long long left = best[u][i].w;

                if (a == v)
                    continue;

                for (int j = 0; j < best_cnt[v]; j++) {
                    int b = best[v][j].to;
                    long long right = best[v][j].w;

                    if (b == u)
                        continue;

                    if (a == b)
                        continue;

                    long long sum = left + middle + right;

                    if (sum > answer)
                        answer = sum;
                }
            }
        }
    }

    return answer;
}

long long solve_path2(int n)
{
    long long answer = 0;

    for (int u = 1; u <= n; u++) {
        long long first = 0;
        long long second = 0;

        for (int i = 0; i < best_cnt[u]; i++) {
            long long w = best[u][i].w;

            if (w > first) {
                second = first;
                first = w;
            }
            else if (w > second) {
                second = w;
            }
        }

        long long sum = first + second;

        if (sum > answer)
            answer = sum;
    }

    return answer;
}

long long solve_matching2(int m)
{
    if (m < 2)
        return 0;

    int max_edge = 0;

    for (int i = 1; i < m; i++) {
        if (input[i].w > input[max_edge].w)
            max_edge = i;
    }

    int u = input[max_edge].u;
    int v = input[max_edge].v;

    long long answer = 0;

    for (int i = 0; i < m; i++) {
        if (i == max_edge)
            continue;

        int a = input[i].u;
        int b = input[i].v;

        if (a == u || a == v || b == u || b == v)
            continue;

        long long sum = input[max_edge].w + input[i].w;

        if (sum > answer)
            answer = sum;
    }

    for (int i = 0; i < best_cnt[u]; i++) {
        int x = best[u][i].to;

        if (x == v)
            continue;

        for (int j = 0; j < best_cnt[v]; j++) {
            int y = best[v][j].to;

            if (y == u)
                continue;

            if (x == y)
                continue;

            long long sum = best[u][i].w + best[v][j].w;

            if (sum > answer)
                answer = sum;
        }
    }

    return answer;
}