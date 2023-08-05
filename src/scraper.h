#ifndef SCRAPER
#define SCRAPER

#include <curl/curl.h>

#include <chrono>
#include <iostream>
#include <string>

static inline size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                                   void *userp);

CURL *InitCurl(std::string &csv);

CURLcode DownloadCSV(CURL *curl, std::string &url);

std::string GenerateURL(const std::string &symbol,
                        const std::chrono::system_clock::time_point &date_start,
                        const std::chrono::system_clock::time_point &date_end,
                        const std::string &interval);

#endif