# Coding Challenges

Solutions to the [Coding Challenges](https://codingchallenges.fyi/challenges/intro).

## Development

### Prerequisites

#### Local

- CMake
- a C++20 compiler

#### Container

- Docker
- Docker Compose

### Instructions

To build the solutions, run:

```bash
cmake -B build
cmake --build build
```

If you want to use the containerized development environment, run:

```bash
docker compose up -d
```

then log into the container in any way you like, for example:

```bash
docker exec -it coding-challenges-devenv-1 zsh
```


## Challenges

- [Write Your Own wc Tool](./001-wc-tool/)

## License

[MIT](./LICENSE)
