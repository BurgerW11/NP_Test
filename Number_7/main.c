    
/* 

    NOT COMPLETED YET
    WORKING IN PROGRESS

    NOT COMPLETED YET
    WORKING IN PROGRESS

    NOT COMPLETED YET
    WORKING IN PROGRESS

    NOT COMPLETED YET
    WORKING IN PROGRESS

    NOT COMPLETED YET
    WORKING IN PROGRESS

            
    SAMPLE OUTPUT :         i. [13.12.12:256] [ERROR] [filename.c:main():56] report error

*/


#include "main.h"


void PrintTimeStamp(char *buffer, size_t size)
{
    struct timeval tv;
    struct tm *tm_info;

    gettimeofday(&tv, NULL); //get the data and time in seconds and microseconds
    tm_info = localtime(&tv.tv_sec); //convert to readable format

    time_info.S_TIME_INFO_milliseconds = (tv.tv_usec / 1000); //convert micro to milli
    time_info.S_TIME_INFO_hour = tm_info->tm_hour;
    time_info.S_TIME_INFO_minutes = tm_info->tm_min;       
    time_info.S_TIME_INFO_seconds = tm_info->tm_sec;

    snprintf (buffer, size, "[%02d:%02d:%02d:%d]", time_info.S_TIME_INFO_hour, time_info.S_TIME_INFO_minutes,time_info.S_TIME_INFO_seconds,time_info.S_TIME_INFO_milliseconds);
}       

int main()              
{       

    logfile = fopen("/home/hanwei/workspace/NP_Test_2025/Number_7/log.txt", "a"); //append so that it always write continuously, not overwriting existing data
    openlog("debug_log", LOG_PID | LOG_CONS, LOG_USER);

    if (logfile == NULL){

        perror("Problem opening file \n");
        return -1;
    }

    for (int i = 0; i < sizeof(E_LOG_LEVEL); i++){

        switch (i){
            
            case LOG_LEVEL_DEBUG:
            
            LOGD("Debugging");
            break;

            case LOG_LEVEL_INFO:
                
            LOGI("Information");
            break;

            case LOG_LEVEL_WARNING:
                
            LOGW("WARNING");
            break;

            case LOG_LEVEL_ERROR:
                
            LOGE("ERROR");
            break;
        }
    }

    fclose(logfile);

    return 0;
}