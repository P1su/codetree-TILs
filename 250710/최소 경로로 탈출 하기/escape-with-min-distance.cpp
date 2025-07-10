#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[100][100];
bool flag = 0;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    visited[0][0] = 1;

    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();
        Q.pop();

        auto[cur_x, cur_y, cur_w] = cur;

        if(cur_x == n-1 && cur_y == m-1){
            flag = 1;
            cout<<cur_w;
            break;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            int nw = cur_w + 1;

            if(visited[nx][ny] || a[nx][ny] == 0){
                continue;
            }
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }

            Q.push({nx, ny, nw});
            visited[nx][ny] = 1;
        }
    }
    
    if(!flag){
        cout<<-1;
    }

    return 0;
}
