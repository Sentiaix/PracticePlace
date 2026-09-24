// https://level.goorm.io/exam/352707/abcd-%EC%A0%95%EB%A0%AC/quiz/1
/*
	1. 매치한 알파벳 제거
	2. mismatch한 알파벳 케이스 분류
		1) 두 알파벳끼리 교체할 때, 둘 다 match되는 경우
		2) 두 알파벳끼리 교체할 때, 하나만 match하는 경우	
		- 케이스 분류해야하는 이유
		  : 만약 case1인 경우, s1[0]을 잡고 s2에 전수조사를 할 때

	CASE1: 서로 교체.
	CASE2: 3상 교체. 
		( A -> B )
		( B -> C )
		( C -> A )
	----
	1. 일치하는 알파벳 제거 함수 구현
	2. 글자 교체 함수 구현
		ㄴ 케이스 1번 실행 후, 없는 경우 2회를 실행해야 최소 연산을 할 수 있음.
	----
	
	8
	BCBADACA
	CDAABBCA

	BCBDA > BCADB (CASE 1)
	CDABB > CDABB

	BCD > CBD (CASE 2)
	CDB > CDB

	BD > DB (CASE 1)
	DB > DB

	Total 3

	---

	BCBDA > DCBBA
	CDABB > CDABB

	DCBA > CDAB (2회 수행함)
	CDAB > CDAB

*/
#include <stdio.h>
#include <string.h>

void solve(){
	
	int len = 0;
	scanf("%d", &len);
	
	char s1[len + 1];
	char s2[len + 1];

	scanf("%s", s1); // string의 value name은
	scanf("%s", s2); // 메모리 주소 헤더를 포함함

	/* 글자를 위아래로 짝지어서 세트를 만든 후,
	반대되는 것들끼리 상쇄시킬것임.
	예:
	ABC
	CBA인 경우, A->C | B->B | C->A이므로,
	A->C랑 C->A는 서로 상쇄 (1회) 됨. */

	// mat[s1의 글자][s2에 같은줄 글자]
	int mat[4][4] = {{0,},};

	// 1. 테이블 만들기
	// 4x4 행렬에 ABCD*ABCD불일치 자리 저장
	for (int i = 0; i < len; i++){
		if(s1[i] != s2[i]){
			int u = s1[i] - 'A'; // 저장된 값은 ASCII이므로,
			int v = s2[i] - 'A'; // ABCD에 -'A'를 함으로써 0123으로 바꿈.
			mat[u][v]++;
		}
	}

	// 2. 같은것끼리 상쇄시키기 (Case1)
	// 서로 양방향 동일한 케이스를 제거하여
	// 테이블 수정
	int count = 0;

	for (int i = 0; i < 4; i++){
		for (int j = i + 1; j < 4; j++){         // 좌상단 직각삼각형 부분만 탐색.
			int diff = (mat[i][j] < mat[j][i] ?   // 예) A->B인 부분과 B->A인 부분 비교.
						  mat[i][j] : mat[j][i]);  // 작은 쪽을 기준으로 잡고, 양방향에 그 양만큼을 뺌.
			count += diff;
			mat[i][j] -= diff;
			mat[j][i] -= diff;
		}
	}


	// ---------------------------------- Ai 이용함 ------------------------------------------//
	// 3. Case 2: 3상 및 4상 순환 교체(사이클) 처리
	while (1) {
		int start = -1;

		// 남아있는 간선이 있는 시작점 찾기
		for (int i = 0; i < 4; i++) {
			int has_out = 0;
			for (int j = 0; j < 4; j++) {
				if (mat[i][j] > 0) {
					has_out = 1;
					break;
				}
			}
			if (has_out) {
				start = i;
				break;
			}
		}

		// 더 이상 처리할 불일치가 없다면 종료
		if (start == -1) break;

		// 사이클 경로 추적
		int visited[4] = {0, };
		int route[5];
		int r_len = 0;
		
		int temp_curr = start;
		while (temp_curr != -1 && !visited[temp_curr]) {
			visited[temp_curr] = 1;
			route[r_len++] = temp_curr;
			
			int next = -1;
			for (int j = 0; j < 4; j++) {
				if (mat[temp_curr][j] > 0) {
					next = j;
					break;
				}
			}
			temp_curr = next;
		}

		// 사이클이 완성된 경우
		if (temp_curr != -1 && visited[temp_curr]) {
			int cycle_start_idx = 0;
			for (int i = 0; i < r_len; i++) {
				if (route[i] == temp_curr) {
					cycle_start_idx = i;
					break;
				}
			}
			
			int actual_cycle_len = r_len - cycle_start_idx;
			
			// [수정 포인트] 마지막 복귀 간선을 포함하여 사이클의 모든 간선 탐색
			int min_val = 1e9; // 10^9 = 1,000,000,000 (int +- 2,147,483,648 - 1)
			for (int i = 0; i < actual_cycle_len; i++) {
				int u_node = route[cycle_start_idx + i];
				int v_node = route[cycle_start_idx + (i + 1) % actual_cycle_len];
				if (mat[u_node][v_node] < min_val) {
					min_val = mat[u_node][v_node];
				}
			}
			
			// 사이클 적용: (길이 - 1) * min_val 만큼 연산 횟수 증가
			count += min_val * (actual_cycle_len - 1);
			
			// [수정 포인트] 마지막 복귀 간선까지 포함해서 행렬 차감
			for (int i = 0; i < actual_cycle_len; i++) {
				int u_node = route[cycle_start_idx + i];
				int v_node = route[cycle_start_idx + (i + 1) % actual_cycle_len];
				mat[u_node][v_node] -= min_val;
			}
		} else {
			break;
		}
	}

	// ------------------------------------------------------------------------------------//

    printf("%d\n", count);
}

int main(){
	solve();
	return 0;
}