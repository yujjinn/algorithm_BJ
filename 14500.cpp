//14500
#include<iostream>
#include<algorithm>
using namespace std;

int arr[500][500];
int visited[500][500] = { 0,};
int N, M;
int max_num = 0;

typedef struct{
	int x,y;
}Dir;

Dir moveD[4]= { {1,0},{-1,0},{0,1},{0,-1} };

bool isrange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}


// ㅗ shape
void checkExpt(int x, int y) {
	int cnt =  0;
	
	int sum = arr[x][y]; int min= 987654321;
	for (int i = 0; i < 4; i++) {
		int nx = x + moveD[i].x;
		int ny = y + moveD[i].y;
		if (!isrange(nx, ny)) continue;
		
		sum += arr[nx][ny];
		cnt++;
		if (min > arr[nx][ny]) { min = arr[nx][ny]; }
		
		if (cnt == 4)
		{
			sum -= min;
			max_num = max(sum, max_num);
		}
	}
	
	max_num = max(sum, max_num);
}

void solution(int x, int y, int cnt, int cur_sum) {
	if (cnt == 4) {
		max_num = max(cur_sum, max_num);
		return;
	}
	visited[x][y] = 1; // 방문 경험 있음
	
	
	for (int i = 0; i < 4; i++) 
	{
		int nx = x + moveD[i].x;
		int ny = y + moveD[i].y;

		if (!isrange(nx,ny))continue;
		if( visited[nx][ny] == 0) 
		{ // 방문 경험이 없다면
			solution(nx, ny,cnt+1,cur_sum+arr[x][y]);
		}
	}

	visited[x][y] = 0;//방문 흔적 초기화

}


int main() {
	
	cin >> N >> M;
	if (N*M < 4) return 0; // 최소 칸 수가 4칸 조차 되지 않으면 break
	
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
				
				solution(i, j,0,0);
				
				checkExpt(i,j);
		}
	}
	cout << " max " << max_num << endl;

}