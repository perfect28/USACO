#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
/*
�������㷨
*/

int stk[1005];
int top;
int N, M, ss, tt;
int mp[1005][1005];

void dfs(int x) {
    stk[top++] = x;
    for (int i = 1; i <= N; ++i) {
        if (mp[x][i]) {
            mp[x][i] = mp[i][x] = 0; // ɾ���˱�
            dfs(i);
            break;
        }
    }
}

void fleury(int ss) {
    int brige;
    top = 0;
    stk[top++] = ss; // ��������Euler·����
    while (top > 0) {
        brige = 1;
        for (int i = 1; i <= N; ++i) { // ��ͼ����һ���߲��Ǹ�ߣ��ţ�
            if (mp[stk[top-1]][i]) {
                brige = 0;
                break;
            }
        }
        if (brige) { // ���û�е������չ���������ջ
            printf("%d ", stk[--top]);
        } else { // �����������ŷ��·��
            dfs(stk[--top]);
        }
    }
}

int main()
{
    freopen("test.in","r",stdin);
    int x, y, deg, num;
    while (scanf("%d %d", &N, &M) != EOF) {
        memset(mp, 0, sizeof (mp));
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &x, &y);
            mp[x][y] = mp[y][x] = 1;
        }
        for (int i = 1; i <= N; ++i) {
            deg = num = 0;
            for (int j = 1; j <= N; ++j) {
                deg += mp[i][j];
            }
            if (deg % 2 == 1) {
                ss = i, ++num;
                printf("%d\n", i);
            }
        }
        if (num == 0 || num == 2) {
            fleury(ss);
        } else {
            puts("No Euler path");
        }
    }
    return 0;
}
