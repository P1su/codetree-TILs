#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int dx[2] = {0, 1}; // 우측으로 이동
int dy[2] = {1, 0}; // 하단으로 이동
bool flag = 0; // 도달 여부를 판단
bool visited[100][100];

void DFS(int x, int y){
    visited[x][y] = 1;

    if(x == n-1 && y == m-1){ // 목표 지점에 도달
        flag = 1;
        return ;
    }

    for(int i = 0 ; i < 2 ; i++){ // 현재 지점으로부터 우측, 하단 탐색
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(grid[nx][ny] == 0 || visited[nx][ny]){ // 다음 경로가 0인 지점이나 이미 방문했다면 건너뜀
            continue;
        }
        if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 경로를 이탈하면 건너뜀
            continue;
        }

        DFS(nx, ny); // 모든 조건을 만족한다면 해당 경로로 이동
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    
    DFS(0, 0);

    if(flag){
        cout<< 1;
    }else{
        cout<< 0;
    }

    return 0;
}
