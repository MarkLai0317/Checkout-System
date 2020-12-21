#include <time.h>
#include <sstream>

string getTimeString(){
    time_t t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss<<std::put_time(std::localtime(&t),"%F %X");
    ss.str();
}

time_t StringToDatetime(std::string str)
{
    char *cha = (char*)str.data();                                                  // 將string轉換成char*。
    tm tm_;                                                                         // 定義tm結構體。
    int year, month, day, hour, minute, second;                                     // 定義時間的各個int臨時變量。
    sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second); // 將string存儲的日期時間，轉換為int臨時變量。
    tm_.tm_year = year - 1900;                                                      // 年，由於tm結構體存儲的是從1900年開始的時間，所以tm_year為int臨時變量減去1900。
    tm_.tm_mon = month - 1;                                                         // 月，由於tm結構體的月份存儲範圍為0-11，所以tm_mon為int臨時變量減去1。
    tm_.tm_mday = day;                                                              // 日。
    tm_.tm_hour = hour;                                                             // 時。
    tm_.tm_min = minute;                                                            // 分。
    tm_.tm_sec = second;                                                            // 秒。
    tm_.tm_isdst = 0;                                                               // 非夏令時。
    time_t t_ = mktime(&tm_);                                                       // 將tm結構體轉換成time_t格式。
    return t_;                                                                      // 返回值。
}