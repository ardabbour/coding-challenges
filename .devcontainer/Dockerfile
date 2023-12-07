FROM ubuntu:22.04

ARG LLVM_VERSION=18
ARG CCACHE_SIZE="10.0G"

ENV CMAKE_GENERATOR=Ninja
ENV PATH="/usr/lib/ccache:${PATH}"
ENV EDITOR=nano
ENV DEFAULT_USER=root

# copy scripts
COPY base-scripts/ /tmp/

# install tools
RUN                                         \
    export DEBIAN_FRONTEND=noninteractive   \
    &&                                      \
    export PYTHONIOENCODING=UTF-8           \
    &&                                      \
    # get the latest list of software
    apt-get update -y                       \
    &&                                      \
    # upgrade to latest versions
    apt-get upgrade -y                      \
    &&                                      \
    # install
    apt-get install -y                      \
    # misc tools
    curl                                    \
    git                                     \
    gnupg2                                  \
    language-pack-en                        \
    nano                                    \
    python3-pip                             \
    wget                                    \
    zsh                                     \
    # non-llvm compilation and debugging tools
    ccache                                  \
    cmake                                   \
    cppcheck                                \
    ninja-build                             \
    valgrind                                \
    &&                                      \
    # install cmakelang
    python3 -m pip install cmakelang        \
    &&                                      \
    # install and configure llvm
    ./tmp/install-llvm.sh ${LLVM_VERSION}   \
    &&                                      \
    # clean up
    rm -rf /var/lib/apt/lists/*

# configure ccache
RUN ccache --max-size="${CCACHE_SIZE}"

# install and configure oh-my-zsh
RUN ./tmp/install-omz.sh

# clean temp directory
RUN rm -rf /tmp/
