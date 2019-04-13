#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct LOC {
	int x;
	int y;
} loc;

// �־��� �迭���� �ּڰ��� ã�� �Լ� : ���� ¥�� �Ϻ����� ����..
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
	
	// �� ������ ��ġ : (0,0), (8,6), (2,4), (6,7), (1,3), (9,4), (2,3)
	int xVal[7] = {0, 8, 2, 6, 1, 9, 2};
	int yVal[7] = {0, 6, 4, 7, 3, 4, 3};
	double result[100] = { 0, };

	// �� ������ x��ǥ��, y��ǥ�� ������ �迭�� �������� (x,y)��ǥ�� ǥ���� ���� ����ü�� ������ ��ǥ ����.
	loc* lo_data = (loc*)malloc(sizeof(loc)*7);	
	for(i=0; i<7; i++) {
		loc temp;
		temp.x = xVal[i];
		temp.y = yVal[i];
		
		lo_data[i] = temp;
	}
	
	// 2���� �迭�� ǥ���� �׷����� �� ���ð��� �Ÿ��� ������ ������ ����.
	for(i=0; i<7; i++) {
		for(j=0; j<7; j++) {
			double powX = pow((lo_data[i].x - lo_data[j].x), 2);
			double powY = pow((lo_data[i].y - lo_data[j].y), 2);
			graph[i][j] = sqrt(powX+powY);
		}
	}
	
	// �� �κ��� �迭�� ǥ���� �׷��� ����ϴ� �κ�. ���� ������ ������ ������.
	for(i=0; i<7; i++) {
		for(j=0; j<7; j++) {
			printf("%0.2lf   ", graph[i][j]);
		}
		printf("\n");
	}
	
	// �ִܰŸ� ã�� �˰��� : �׸��� �˰������� (0,0)�������� �����ؼ�, ���� ��ġ�� node���� ���� ����� �Ÿ��� ���� �ٸ� vertex���� �̵�.
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
	
	// 0���� �����ؼ� ǥ���� �迭�̱� ������, 1���� �����ϵ��� ��� ���� 1�� ������.
	for(i=0; i<7; i++) printf("%d ", log[i]+1);
}
	
