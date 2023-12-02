#include "lib.hpp"
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace ccwc {
Arguments::Arguments(int argc, char **argv) {
  program_name = argv[0]; // first arg is program name
  if (argc >= 2) {
    for (int i = 1; i < argc; ++i) {
      std::string arg = argv[i];
      if (arg[0] == '-') { // if arg starts with '-' iterate over the rest of the string
        for (char chr : arg.substr(1)) {
          switch (chr) {
          case 'h':
            help = true;
            break;
          case 'c':
            bytes = true;
            break;
          case 'l':
            lines = true;
            break;
          case 'w':
            words = true;
            break;
          case 'm':
            chars = true;
            break;
          default:
            std::cerr << "Unknown option: -" << chr << '\n';
            break;
          }
        }
      } else { // else treat arg as the filename
        if (file_name.empty()) {
          file_name = arg;
        } else {
          std::cout << "More than one filename given! File name is set to " << file_name.string() << '\n';
        }
      }
    }
  }

  // default behavior is to get bytes, lines and words
  if (!(bytes || lines || words || chars)) {
    bytes = true;
    lines = true;
    words = true;
  }
}

void printUsage(const Arguments &arguments) {
  std::cout
      << "Usage: " << arguments.program_name << " [options] [filename]" << '\n'
      << "Options:" << '\n'
      << "  -h   Display this usage message" << '\n'
      << "  -c   Display number of bytes" << '\n'
      << "  -l   Display number of lines" << '\n'
      << "  -w   Display number of words" << '\n'
      << "  -m   Display number of characters" << '\n'
      << '\n'
      << "Description:" << '\n'
      << "Displays the number of lines, bytes, words, and/or characters in a file. If no file is given, the program "
         "will read from the standard input. If no options are given, the lines, bytes, words are given."
      << '\n';
}

// some chars are multibytes, so char count can be less than byte count; cpp needs a better way to count bytes and chars
auto countCharacters(std::string_view str) -> std::uintmax_t {
  std::uintmax_t char_count = 0;
  std::uintmax_t ind = 0;

  while (str[ind] != '\0') {
    wchar_t wide_char;
    std::uintmax_t bytes_count = mbtowc(&wide_char, &str[ind], MB_CUR_MAX); // NOLINT(concurrency-mt-unsafe)

    if (bytes_count > 0) {
      char_count++;
      ind += bytes_count;
    } else {
      ind++;
    }
  }

  return char_count;
}

auto calculateStatistics(const std::filesystem::path &path) -> Statistics {
  setlocale(LC_ALL, ""); // NOLINT(concurrency-mt-unsafe)
  std::istream *input = nullptr;
  std::ifstream file_stream;

  if (path.empty()) {
    input = &std::cin;
  } else {
    file_stream.open(path, std::ios::binary);
    input = &file_stream;
  }

  Statistics statistics;

  std::string line;
  while (std::getline(*input, line)) {
    statistics.lines++;
    statistics.chars += countCharacters(line);
    statistics.bytes += line.length();
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      statistics.words++;
    }
  }

  // add new lines
  statistics.bytes += statistics.lines;
  statistics.chars += statistics.lines;

  if (!path.empty()) {
    file_stream.close();
  }

  return statistics;
}

void printResult(const Arguments &arguments, const Statistics &stats) {
  std::cout << (arguments.lines ? "lines\t" : "") << (arguments.words ? "words\t" : "")
            << (arguments.bytes ? "bytes\t" : "") << (arguments.chars ? "chars\t" : "") << "source" << '\n';
  std::cout << (arguments.lines ? std::to_string(stats.lines) + '\t' : "")
            << (arguments.words ? std::to_string(stats.words) + '\t' : "")
            << (arguments.bytes ? std::to_string(stats.bytes) + '\t' : "")
            << (arguments.chars ? std::to_string(stats.chars) + '\t' : "")
            << (arguments.file_name.empty() ? "[standard input]"
                                            : std::filesystem::absolute(arguments.file_name).string())
            << '\n';
}
} // namespace ccwc
