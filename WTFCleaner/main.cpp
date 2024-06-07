#include "TempCleaner.h"
#include <iostream>

int main() {
    // Get the singleton instance of TempCleaner
    TempCleaner& cleaner = TempCleaner::getInstance();
    cleaner.clearTempFolder(TempFolder::WINDOWS_TEMP);
    cleaner.clearTempFolder(TempFolder::CURRENT_USER_TEMP);
    cleaner.clearTempFolder(TempFolder::PREFETCH);
     cleaner.clearTempFolder(TempFolder::COOKIES);
     cleaner.clearTempFolder(TempFolder::TEMP_INTERNET_FILES);
     cleaner.clearTempFolder(TempFolder::HISTORY);
     cleaner.clearTempFolder(TempFolder::JAVA_CACHE);
    std::cout << "Deletion process is complete." << std::endl;
    return 0;
}
