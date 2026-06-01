#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
    while (1)
    {
        time_t now;
        struct tm *local;

        now = time(NULL);
        local = localtime(&now);

        system("cls"); //screen clear(Windows)

        // Day names
        char *days[]={
            "Sunday","Monday","Tuesday","Wednesday",
            "Thursday","Friday","Satureday"
        };

        // 12-hour format logic
        int hour = local->tm_hour;
        char *ampm = (hour >= 12) ? "PM" : "AM";
        hour = hour % 12;
        if(hour ==0)hour = 12;

        printf("=== DIGITAL CLOCK ===\n\n");

        // Day
        printf("Day:%s\n", days[local->tm_wday]);

        // Time (12-hour with AM/PM)
        printf("Time:%02d:%02d:%02d%s\n",
            hour,
            local->tm_min,
            local->tm_sec,
            ampm);

        // Date    
        printf("Date:%02d/%02d/%d\n",
           local->tm_mday,
           local->tm_mon + 1,
           local->tm_year + 1900);
           
        Sleep(1000); // 1 second delay  
        }

        return 0;
}