/* 이미 방문한 위치에는 표시를 해서 무한루프를 방지한다.
 * 현재위치에서 일정한 규칙으로 다음 위치로 이동한다.
 *      - 북,동,남,서 순서로 검사
 *      - 그 방향으로 갈수 있으면, 즉 아직 안가본 위치면서 벽이 아니면 그방향으로 간다.
 * 아무 방향으로도 갈 수 없으면 그 위치에 오기 직전 위치로 되돌아 간다.
 *
 * 1. 현재 위치는 출발점(0,0) 이다.
 * 2. 다음을 반복한다.
 *     1) 현재 위치에 방문했다는 표시를 한다.
 *     2) 현재 위치가 출구라면 종료한다.
 *     3) 현재 위치에서 북,동,남,서 4방향에 대해서 순서대로
 *          - 그 방향으로 이동 할 수 있는지(즉 벽이아니고, 미로의 외부도 아니고, 이미 방문한위치도 아닌지) 검사한다.
 *          - 만약 갈 수 있으면 현재 위치를 스택에 PUSH하고 그 방향으로 이동한다.
 *     4) 만약 3번에서 4방향 중 어느쪽으로도 갈수 없었다면 스택에서 POP한 후 그 위치로 돌아간다. ( 만약 돌아갈 위치가 없다면 원래 길이 없는 미로이다.)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pos.h"
#include "mazeStack.h"


#define MAZE_SIZE 10
#define PATH 0                  // 지나갈수있는 위치
#define WALL 1                  // 지나갈수 없는 위치
#define VISITED 2               // 이미 방문한 위치
#define BACKTRACKED 3           // 방문했다가 되돌아온 위치

char maze[MAZE_SIZE][MAZE_SIZE] = {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'m', '0', '0', '0', '1', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '1', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '0', '0', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '0', '1', '0', 'X'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};
int n;


void print_maze();

bool movable(Position pos, int dir);

int main() {

    Stack s = create();     // stack to save location
    Position cur;           // current location
    cur.x = 0;
    cur.y = 0;

    while (1) {
        maze[cur.x][cur.y] = VISITED;               // mark current location
        if (cur.x == n - 1 && cur.y == n - 1) {     // if current location is exit.
            printf("Found the Path.\n");
            break;
        }

        bool forwarded = false;                     // mark to success forward
        for (int dir = 0; dir < 4; dir++) {         // 0:N , 1:E , 2:S , 3:W
            if (movable(cur, dir)) {          // dir 방향으로 이동할 수 있는지 검사
                push(s, cur);                       // 현재위치를 stack 에 push
                cur = move_to(cur, dir);       // dir 방향으로 한칸 이동한 위치를 new cur.
                forwarded = true;
                break;
            }
            if (!forwarded) {                       // 4방향중 어느곳으로도 가지 못했다면
                maze[cur.x][cur.y] = BACKTRACKED;   // 왔다가 되돌아간 위치임을 표시
                if (is_empty(s)) {                  // 되돌아갈 위치가 없다면 원래 길이없는 미로.
                    printf("No path exists.\n");
                    break;
                }
                cur = pop(s);           //  스택에서 pop한 위치가 새로운 현재위치가 된다.
            }
        }
    }
    print_maze();
}


void print_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

bool movable(Position pos, int dir) {
    Position next = move_to(pos, dir);
    if ((next.x < 0 || next.x > MAZE_SIZE) || (next.y < 0 || next.y > MAZE_SIZE)){
        return false;
    }
    if (maze[next.x][next.y] != '1') {
        return true;
        if()
    }
}