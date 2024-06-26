﻿#include "TempCleaner.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

TempCleaner& TempCleaner::getInstance() {
    static TempCleaner instance;
    return instance;
}

void TempCleaner::clearTempFolder(TempFolder folder) {
    std::string path = getFolderPath(folder);
    if (!path.empty()) {
        clearFolder(path);
    }
    else {
        std::cerr << "Invalid folder type." << std::endl;
    }
}

std::string TempCleaner::getFolderPath(TempFolder folder) {
    char* envPath = nullptr;
    switch (folder) {
    case TempFolder::WINDOWS_TEMP:
        envPath = std::getenv("TEMP");
        break;
    case TempFolder::CURRENT_USER_TEMP:
        envPath = std::getenv("TEMP");
        break;
    case TempFolder::ALL_USER_TEMP:
        return "C:\\Windows\\Temp";
    case TempFolder::PREFETCH:
        return "C:\\Windows\\Prefetch";
    case TempFolder::COOKIES:
        return std::string(std::getenv("USERPROFILE")) + "\\AppData\\Local\\Microsoft\\Windows\\INetCookies";
    case TempFolder::TEMP_INTERNET_FILES:
        return std::string(std::getenv("USERPROFILE")) + "\\AppData\\Local\\Microsoft\\Windows\\INetCache";
    case TempFolder::HISTORY:
        return std::string(std::getenv("USERPROFILE")) + "\\AppData\\Local\\Microsoft\\Windows\\History";
    case TempFolder::JAVA_CACHE:
        return std::string(std::getenv("USERPROFILE")) + "\\AppData\\LocalLow\\Sun\\Java\\Deployment\\cache";
    default:
        return "";
    }
    return envPath ? envPath : "";
}

void TempCleaner::clearFolder(const std::string& path) {
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            try {
                fs::remove_all(entry);
                std::cout << "Cleared: " << entry.path() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error clearing file or directory: " << entry.path() << ": " << e.what() << std::endl;
            }
        }
        std::cout << "Cleared folder: " << path << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error iterating folder: " << e.what() << std::endl;
    }
}
