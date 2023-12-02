#pragma once

#include <cstdint>
#include <filesystem>
#include <string>

namespace ccwc {
struct Arguments {
  std::string program_name;
  bool help = false;
  bool bytes = false;
  bool lines = false;
  bool words = false;
  bool chars = false;
  std::filesystem::path file_name;
  Arguments(int argc, char **argv);
};

struct Statistics {
  std::uintmax_t lines = 0;
  std::uintmax_t words = 0;
  std::uintmax_t bytes = 0;
  std::uintmax_t chars = 0;
};

void printUsage(const Arguments &arguments);
auto calculateStatistics(const std::filesystem::path &path) -> Statistics;
void printResult(const Arguments &arguments, const Statistics &stats);

} // namespace ccwc
