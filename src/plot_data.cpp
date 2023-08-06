#include "plot_data.h"

void ParseTradingData(
    const std::string &csv,
    std::map<std::chrono::system_clock::time_point, TradingData> &plot_data) {
  std::istringstream csv_stream(csv);
  std::string line;

  std::getline(csv_stream, line);
  while (std::getline(csv_stream, line)) {
    const std::regex regex{"((?:[^\\\\,]|\\\\.)*?)(?:,|$)"};
    std::vector<std::string> vector{
        std::sregex_token_iterator(line.begin(), line.end(), regex, 1),
        std::sregex_token_iterator()};

    if (vector[0] != "null" && vector[1] != "null") {
      std::istringstream in{vector[0]};
      std::chrono::system_clock::time_point time_point;
      in >> date::parse("%F", time_point);

      TradingData trading_data;
      trading_data.open = std::stod(vector[1]);
      trading_data.high = std::stod(vector[2]);
      trading_data.low = std::stod(vector[3]);
      trading_data.close = std::stod(vector[4]);

      plot_data.emplace(time_point, trading_data);
    }
  }
}
