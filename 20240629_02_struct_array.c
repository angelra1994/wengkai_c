#include <stdio.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
};

struct time timeUpdate(struct time);

int main(int argc, char const *argv[]) 
{
    struct time testTimes[5] = {
        {11, 59, 59}, {12, 0, 0}, {1,59,59}, {23,59,59}, {11, 11, 11},
    };
    printf("%i", sizeof(testTimes)/sizeof(struct time));
    int i;
    for (i = 0; i < sizeof(testTimes)/sizeof(struct time); i++)
    {
        printf("Time is %.2i:%.2i:%.2i\n", testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
        testTimes[i] = timeUpdate(testTimes[i]);
        printf("... one second later it's %.2i:%.2i:%.2i\n", testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
    }
    
    return 0;   
}

struct time timeUpdate(struct time now)
{
    ++ now.seconds;
    if (now.seconds == 60) {
        now.seconds =  0;
        ++ now.minutes;
        if (now.minutes == 60) {
            now.minutes = 0;
            ++ now.hour;
            if (now.hour == 24) {
                now.hour = 0;
            }
        }
    }

    return now;
}
