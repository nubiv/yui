#include "scraper.h"

using namespace std::chrono;

static inline size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                                   void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

CURL *InitCurl(std::string &csv) {
  CURL *curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &csv);

    std::cout << "successfully init curl" << std::endl;
  }

  return curl;
}

CURLcode DownloadCSV(CURL *curl, std::string &url) {
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

  return curl_easy_perform(curl);
}

std::string GenerateURL(const std::string &symbol_str,
                        const system_clock::time_point &starting_tp,
                        const system_clock::time_point &ending_tp,
                        const std::string &interval) {
  auto date_start_str = std::to_string(
      duration_cast<seconds>(starting_tp.time_since_epoch()).count());
  auto date_end_str = std::to_string(
      duration_cast<seconds>(ending_tp.time_since_epoch()).count());

  std::string url = "https://query1.finance.yahoo.com/v7/finance/download/" +
                    symbol_str + "?period1=" + date_start_str +
                    "&period2=" + date_end_str + "&interval=" + interval +
                    "&events=history";

  return url;
}