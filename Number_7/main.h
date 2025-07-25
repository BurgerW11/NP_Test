/* 
    7. Implement an advanced log system, which is required to meet the following requirements:

    a. Use macro definition to implement log output interface.

        i. Such as: LOGD(), LOGI(), LOGW(), LOGE()

    b. Support log level printing:

        i. Log levels: DEBUG, INFO, WARN, ERROR

        ii. Log levels priority: ERROR > WARN > INFO > DEBUG

    c. Use a macro definition (such as LOG_LEVEL) to control the lowest log level of the current output, and logs below this level will not be output;

    d. When each log is printed, it must include the current timestamp, log level, source file name, function name and code line number information, and print the following informations:
        i. Format: [hour.minute.second:millisecond] [log level] [file name:function name:line number] log

        ii. Accuracy of timestamp up to three digits milliseconds.

    e. Sample for log output format:

        i. [13.12.12:256] [ERROR] [filename.c:main():56] report error!

    f. Support log output to standard output, console, file, kernel.

    @brief  referred to:    https://www.geeksforgeeks.org/c/macros-and-its-types-in-c-cpp/
                            https://www.geeksforgeeks.org/c/printing-source-code-c-program/
                            https://www.includehelp.com/c-programs/print-the-line-number-in-source-code-with-filename-and-function-name.aspx
                            https://stackoverflow.com/questions/64318331/how-to-print-logs-on-both-console-and-file-in-c-language
                            https://stackoverflow.com/questions/25493774/how-to-write-a-logging-function-or-macro-that-can-append-callers-name-to-the-lo
                            https://pubs.opengroup.org/onlinepubs/7908799/xsh/syslog.h.html
                            https://www.w3schools.com/c/ref_stdio_snprintf.php



    @remark
        __FILE__        : print file name (string)
        __LINE__        : get current line (integer)
        __FUNCTION__    : get current func name (string)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> //able to provide time with millisecond accuracy
#include <time.h> //to get time of the day (date and seconds since Epoch) and localtime (convert to readable format)
#include <syslog.h>


#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3

#define FILE_PATH "/home/hanwei/workspace/NP_Test_2025/Number_7"

typedef enum{

    E_LOG_LEVEL_DEBUG = LOG_LEVEL_DEBUG,
    E_LOG_LEVEL_INFO = LOG_LEVEL_INFO,
    E_LOG_LEVEL_WARNING = LOG_LEVEL_WARNING,
    E_LOG_LEVEL_ERROR = LOG_LEVEL_ERROR
}E_LOG_LEVEL;

typedef struct{

    int S_TIME_INFO_hour;
    int S_TIME_INFO_minutes;
    int S_TIME_INFO_seconds;
    int S_TIME_INFO_milliseconds;

}S_TIME_INFO;

S_TIME_INFO time_info;
FILE *logfile;

void PrintTimeStamp(char *buffer, size_t size);

#define LOGD(fmt,...) do { \
    syslog(LOG_DEBUG,"Debugging"); \
    char cTimeStamp[20]; \
    PrintTimeStamp(cTimeStamp, sizeof(cTimeStamp)); \
    const char *ptr = cTimeStamp;\
    printf ("%s [DEBUG] - Printing at std output [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(stdout, "%s [DEBUG] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(logfile, "%s [DEBUG] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    }while(0)
    
#define LOGI(fmt,...) do { \
    char cTimeStamp[20]; \
    PrintTimeStamp(cTimeStamp, sizeof(cTimeStamp)); \
    const char *ptr = cTimeStamp;\
    printf ("%s [INFO] - Printing at std output [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(stdout, "%s [INFO] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(logfile, "%s [INFO] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    }while(0)

#define LOGW(fmt,...) do { \
    char cTimeStamp[20]; \
    PrintTimeStamp(cTimeStamp, sizeof(cTimeStamp)); \
    const char *ptr = cTimeStamp;\
    printf ("%s [WARNING] - Printing at std output [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(stdout, "%s [WARNING] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(logfile, "%s [WARNING] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    }while(0)

#define LOGE(fmt,...) do { \
    char cTimeStamp[20]; \
    PrintTimeStamp(cTimeStamp, sizeof(cTimeStamp)); \
    const char *ptr = cTimeStamp;\
    printf ("%s [ERROR] - Printing at std output [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(stdout, "%s [ERROR] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    fprintf(logfile, "%s [ERROR] [%s.%s:%d] " fmt "\n", ptr, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    }while(0)




