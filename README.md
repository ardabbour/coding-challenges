# Coding Challenges

Solutions to the [Coding Challenges](https://codingchallenges.fyi/challenges/intro).

## Development

### Prerequisites

- CMake
- cppcheck
- clang-tidy
- a C++20 compiler

### Instructions

To build the solutions, run:

```bash
PROJECT_DIR=$(pwd) # assuming you are in the root folder of the project
BUILD_TYPE=Release
BUILD_DIR=$PROJECT_DIR/build
cmake -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE # configure
cmake --build $BUILD_DIR --config $BUILD_TYPE # build
ctest --test-dir $BUILD_DIR -C $BUILD_TYPE # test
cmake --install $BUILD_DIR --config $BUILD_TYPE # install
```

## Challenges

- [Write Your Own wc Tool](./001-wc-tool/)

## License

[MIT](./LICENSE)
