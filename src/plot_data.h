#ifndef PLOT_DATA
#define PLOT_DATA

#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "date.h"

struct TradingData {
  double open;
  double close;
  double high;
  double low;
};

void ParseTradingData(
    const std::string &csv,
    std::map<std::chrono::system_clock::time_point, TradingData> &plot_data);

#endif