#include <stdio.h>

void GetTime(long SysSecs, int *hours,int *minutes,int *seconds);

int main() {
    long input;
    printf("Enter Device Secs: ");
    scanf("%ld", &input);
    int hours, minutes, seconds;
    GetTime(input, &hours, &minutes, &seconds);
    printf("Time is %d:%d:%d\n",hours,minutes,seconds);

    return 0;
}

void GetTime(long SysSecs, int *hours,int *minutes,int *seconds) {
    *seconds = SysSecs%60;
    *minutes = SysSecs%3600/60;
    *hours   = SysSecs/3600;
}
