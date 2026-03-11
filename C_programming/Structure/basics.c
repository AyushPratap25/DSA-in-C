#include <stdio.h>

struct time 
{
    int hour;
    int min;
    int sec;
} t1;

int main() {
    // assign values
    t1.hour = 16;
    t1.min = 40;
    t1.sec = 51;

    // print in HH:MM:SS format
    printf("%02d:%02d:%02d\n", t1.hour, t1.min, t1.sec);

    return 0;
}
