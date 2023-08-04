#ifndef scraper
#define scraper

#include <string>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp);

int Fetch_data(void);

#endif