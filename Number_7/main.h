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


    @remark
        __FILE__        : print file name (string)
        __LINE__        : get current line (integer)
        __FUNCTION__    : get current func name (string)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{

    LOG_LEVEL_DEBUG = 0,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR

}LOG_LEVEL_PRIORITY;

void PrintLog(LOG_LEVEL_PRIORITY loglevel, char *file, char *func, int line, char *msg);