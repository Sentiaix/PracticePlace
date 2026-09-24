// https://level.goorm.io/exam/353644/%EC%8B%9C%ED%97%98-%EC%84%B1%EC%A0%81-2/quiz/1

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int rank_a;
	int rank_b;
	int index;
} Student;

void solve();
void find_C(int* answer, Student* Std, int n);

void update(int* tree, int n, int index);
int query(int* tree, int index);

int compare(const void* a, const void* b);

int main(){

	solve();

	return 0;
}

void solve(){
	int n; // 학생 수
	if (scanf("%d", &n) != 1) return;
	
	Student Std[n];
	int answer[n];

	// answer을 0으로 모두 초기화
	for (int i = 0; i < n; i++){
		answer[i] = 0;
	}

	for (int i = 0; i < n; i++){
		scanf("%d", &Std[i].rank_a);
		Std[i].index = i;
	}

	for (int i = 0; i < n; i++){
		scanf("%d", &Std[i].rank_b);
	}
					  
	find_C(answer, Std, n);

	for (int i = 0; i < n; i++){
		printf("%d ", answer[i]);
	}

	printf("\n");
					  
	return;
}

void find_C(int* answer, Student* Std, int n){

	// rank_a가 큰 순서대로 정렬
	qsort(Std, n, sizeof(Student), compare);

	int tree[n + 1];

	// Fenwick Tree를 0으로 초기화
	for (int i = 0; i <= n; i++){
		tree[i] = 0;
	}

	for (int i = 0; i < n; i++){

		int b = Std[i].rank_b;

		// 지금까지 처리된 학생들은 현재 학생보다 rank_a가 큼
		// 따라서 rank_b가 현재 학생보다 큰 학생만 찾으면 됨
		answer[Std[i].index] = i - query(tree, b);

		// 현재 학생의 rank_b를 Fenwick Tree에 추가
		update(tree, n, b);
	}

	return;
}

void update(int* tree, int n, int index){

	// index에 해당하는 값에 1을 추가
	while (index <= n){
		tree[index]++;
		index += index & -index;
	}
}

int query(int* tree, int index){

	int sum = 0;

	// 1부터 index까지의 누적합을 계산
	while (index > 0){
		sum += tree[index];
		index -= index & -index;
	}

	return sum;
}

int compare(const void* a, const void* b){

	Student* A = (Student*)a;
	Student* B = (Student*)b;

	// rank_a가 큰 순서대로 정렬
	return B->rank_a - A->rank_a;
}