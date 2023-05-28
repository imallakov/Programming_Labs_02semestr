#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

void input(int (*data)[WIDTH]);
void output(int (*data)[WIDTH]);
int play(int (*data)[WIDTH]);
int copy(int (*data)[WIDTH], int (*data1)[WIDTH]);
int cnt(int i, int j, int (*data)[WIDTH]);

int main() {
    int time = 100000;
    int data[HEIGHT][WIDTH];
    input(data);
    FILE* file = freopen("/dev/tty", "r", stdin);
    if (file == NULL) printf("ERROR!");
    initscr();
    nodelay(stdscr, true);
    noecho();
    output(data);
    char ch;
    while ((ch = getch()) != 'q') {
        clear();
        if (ch == 'f') {
            if (time >= 100000) time -= 50000;
        }
        if (ch == 's') {
            if (time <= 900000) time += 50000;
        }
        usleep(time);
        int k = play(data);
        if (k == 1) break;
        output(data);
    }
    endwin();
    return 0;
}

void input(int (*data)[WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            char ch;
            scanf("%c", &ch);
            if (ch == 'O')
                data[i][j] = 1;
            else if (ch == '\'')
                data[i][j] = 0;
            else
                --j;
        }
    }
}

void output(int (*data)[WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (data[i][j] == 0) {
                addch('\'');
            } else {
                addch('O');
            }
        }
        addstr("\n");
    }
    refresh();
}

int play(int (*data)[WIDTH]) {
    int data1[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int count = cnt(i, j, data);
            if (data[i][j] == 1 && (count == 2 || count == 3))
                data1[i][j] = 1;
            else {
                if (data[i][j] == 0 && count == 3) {
                    data1[i][j] = 1;
                } else {
                    data1[i][j] = 0;
                }
            }
        }
    }
    int flag = copy(data, data1);
    return flag;
}

int cnt(int i, int j, int (*data)[WIDTH]) {
    int x = i, y = j, count = 0;
    if (x == 0) x = HEIGHT;
    if (y == 0) y = WIDTH;
    if (data[abs((x - 1) % HEIGHT)][abs((y - 1) % WIDTH)] == 1) count++;
    y = j;
    if (data[abs((x - 1) % HEIGHT)][abs((y) % WIDTH)] == 1) count++;
    if (y == WIDTH - 1)
        y = -1;
    else
        y = j;
    if (data[abs((x - 1) % HEIGHT)][abs((y + 1) % WIDTH)] == 1) count++;
    x = i;
    if (y == 0)
        y = WIDTH;
    else
        y = j;
    if (data[x][abs((y - 1) % WIDTH)] == 1) count++;
    if (y == WIDTH - 1)
        y = -1;
    else
        y = j;
    if (data[x][abs((y + 1) % WIDTH)] == 1) count++;
    if (x == HEIGHT - 1)
        x = -1;
    else
        x = i;
    if (y == 0)
        y = WIDTH;
    else
        y = j;
    if (data[abs((x + 1) % HEIGHT)][abs((y - 1) % WIDTH)] == 1) count++;
    y = j;
    if (data[abs((x + 1) % HEIGHT)][abs((y) % WIDTH)] == 1) count++;
    if (y == WIDTH - 1)
        y = -1;
    else
        y = j;
    if (data[abs((x + 1) % HEIGHT)][abs((y + 1) % WIDTH)] == 1) count++;
    return count;
}

int copy(int (*data)[WIDTH], int (*data1)[WIDTH]) {
    int flag = 1;
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            data[i][j] = data1[i][j];
            if (data[i][j] > 0) flag = 0;
        }
    }
    return flag;
}