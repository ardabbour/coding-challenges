// Coding Challenges, Write Your Own wc Tool: https://codingchallenges.fyi/challenges/challenge-wc
#include "lib.hpp"
#include <iostream>

auto main(int argc, char **argv) -> int {
  try {
    ccwc::Arguments arguments{argc, argv};
    if (arguments.help) {
      ccwc::printUsage(arguments);
    } else {
      ccwc::printResult(arguments, ccwc::calculateStatistics(arguments.file_name));
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
