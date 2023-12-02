#include "lib.hpp"
#include <cstdlib>
#include <iostream>

auto main(int argc, char **argv) -> int {
  int result = 0;
  try {
    ccwc::Arguments arguments{argc, argv};
    constexpr ccwc::Statistics expected_statistics{.lines = 7145, .words = 57164, .bytes = 342190, .chars = 339292};
    const auto statistics = ccwc::calculateStatistics(arguments.file_name);
    const auto equivalent =
        statistics.lines == expected_statistics.lines && statistics.words == expected_statistics.words &&
        statistics.bytes == expected_statistics.bytes && statistics.chars == expected_statistics.chars;
    result = equivalent ? EXIT_SUCCESS : EXIT_FAILURE;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return result;
}
