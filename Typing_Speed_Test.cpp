#include <bits/stdc++.h>
#include <termios.h>

static struct termios old, new1;

/* Initialize new1 terminal i/o settings */
void initTermios(int echo) {
    tcgetattr(0, &old);      /* grab old terminal i/o settings */
    new1 = old;              /* make new1 settings same as old settings */
    new1.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo) {
        new1.c_lflag |= ECHO; /* set echo mode */
    } else {
        new1.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &new1); /* use these new1 terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void) {
    return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
    return getch_(1);
}

using namespace std;

string test[] = {"hello", "alienware", "godrej", "newspaper", "vision", "harvard", "laptop", "computer", "turnball", "notebook", "noodles", "coffee", "pizza", "jacket", "hoodie", "mobile", "stationary", "diary", "staircase", "carbonated",
                 "network", "paint", "internet", "programming", "harmony", "backpack"};
string ans, print;
char temp;

int main() {
start:
    srand(time(NULL));
    print = test[rand() % test->size()];
    fflush(stdout);
    system("clear");
    cout << '\r' << print << endl;
    ans.clear();
    chrono::steady_clock::time_point end = chrono::steady_clock::now() + chrono::seconds(3);

    while (ans != print && chrono::steady_clock::now() < end) {
        temp = getch();
        if ((int)temp == 127)
            ans.erase(ans.end() - 1);
        else
            ans += temp;
        system("clear");
        fflush(stdout);
        cout << print << "\n\r" << ans;
    }

    if (ans == print)
        goto start;

    else {
        fflush(stdout);
        system("clear");
        cout << "Game over!" << endl;
    }
}
