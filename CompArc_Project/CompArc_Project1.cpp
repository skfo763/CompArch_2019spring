#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct LOC {
	int x;
	int y;
} loc;

// 주어진 배열에서 최솟값을 찾는 함수 : 대충 짜서 완벽하지 않음..
int findMin(double row[]) {
	double min = 10000;
	
	for(int i=0; i<7; i++) {
		if(row[i] == 0) continue;
		else if(row[i] < min) {
			min = row[i];
		}	
	}
	
	int j;
	for(j=0; j<7; j++) {
		if(row[j] == min) break;
	}
	
	return j;
}

int main(void) {
	double graph[7][7] = {0, };
	int i, j;
	
	// 각 도시의 위치 : (0,0), (8,6), (2,4), (6,7), (1,3), (9,4), (2,3)
	int xVal[7] = {0, 8, 2, 6, 1, 9, 2};
	int yVal[7] = {0, 6, 4, 7, 3, 4, 3};
	double result[100] = { 0, };

	// 각 도시의 x좌표만, y좌표만 저장한 배열을 바탕으로 (x,y)좌표를 표현한 별도 구조체에 도시의 좌표 저장.
	loc* lo_data = (loc*)malloc(sizeof(loc)*7);	
	for(i=0; i<7; i++) {
		loc temp;
		temp.x = xVal[i];
		temp.y = yVal[i];
		
		lo_data[i] = temp;
	}
	
	// 2차원 배열로 표현한 그래프에 각 도시간의 거리를 간선의 값으로 저장.
	for(i=0; i<7; i++) {
		for(j=0; j<7; j++) {
			double powX = pow((lo_data[i].x - lo_data[j].x), 2);
			double powY = pow((lo_data[i].y - lo_data[j].y), 2);
			graph[i][j] = sqrt(powX+powY);
		}
	}
	
	// 이 부분은 배열로 표현된 그래프 출력하는 부분. 실제 보고서엔 지워도 무방함.
	for(i=0; i<7; i++) {
		for(j=0; j<7; j++) {
			printf("%0.2lf   ", graph[i][j]);
		}
		printf("\n");
	}
	
	// 최단거리 찾는 알고리즘 : 그리디 알고리즘으로 (0,0)에서부터 시작해서, 현재 위치한 node에서 가장 가까운 거리를 갖는 다른 vertex으로 이동.
	// 
	int log[7] = { 0, };
	int start = 0;
	for(i=0; i<7; i++) graph[i][0] = 10000;
	
	for(j=1; j<7; j++) {
		int temp = findMin(graph[start]);
		
		for(i=0; i<7; i++) graph[i][temp] = 10000;
		log[j] = temp;
		start = temp;
	}
	
	// 0부터 시작해서 표현된 배열이기 때문에, 1부터 시작하도록 모든 값을 1씩 더해줌.
	for(i=0; i<7; i++) printf("%d ", log[i]+1);
}
	
