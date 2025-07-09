#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag = 0;
bool visited[100][100];


// 0, 0에서 출발하여 n-1, m-1에 도달
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    visited[0][0] = 1;

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        if(cur.first == n-1 && cur.second == m-1){
            flag = 1;
            break;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(visited[nx][ny] || a[nx][ny] == 0){ // 이미 방문했거나 뱀이 있는 경우 건너뜀
                continue;
            }
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 범위를 벗어날 경우 건너뜀
                continue;
            }

            Q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    if(flag){
        cout<< 1;
    }else{
        cout<< 0;
    }

    return 0;
}
