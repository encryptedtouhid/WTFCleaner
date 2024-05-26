#ifndef TEMPCLEANER_H
#define TEMPCLEANER_H

#include <string>

enum class TempFolder {
    WINDOWS_TEMP,
    CURRENT_USER_TEMP,
    ALL_USER_TEMP,
    PREFETCH,
    COOKIES,
    TEMP_INTERNET_FILES,
    HISTORY,
    JAVA_CACHE
};

class TempCleaner {
public:
    static TempCleaner& getInstance();
    void clearTempFolder(TempFolder folder);

private:
    TempCleaner() = default;
    ~TempCleaner() = default;
    TempCleaner(const TempCleaner&) = delete;
    TempCleaner& operator=(const TempCleaner&) = delete;

    std::string getFolderPath(TempFolder folder);
    void clearFolder(const std::string& path);
};

#endif // TEMPCLEANER_H
