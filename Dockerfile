FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV PYTHONIOENCODING=UTF-8
ENV LLVM_VERSION=18
ENV CMAKE_GENERATOR=Ninja

# install tools
COPY scripts/install_llvm.sh install_llvm.sh
RUN                                         \
    # get the latest list of software
    apt-get update -y                       \
    &&                                      \
    # upgrade to latest versions
    apt-get upgrade -y                      \
    &&                                      \
    # install misc packages
    apt-get install -y                      \
    ccache                                  \
    cmake                                   \
    curl                                    \
    git                                     \
    language-pack-en                        \
    nano                                    \
    ninja-build                             \
    openssh-server                          \
    tmux                                    \
    zsh                                     \
    &&                                      \
    # install llvm
    ./install_llvm.sh                       \
    &&                                      \
    # clean up
    rm -rf                                  \
    /var/lib/apt/lists/*                    \
    install_llvm.sh

# get and configure oh-my-zsh
COPY scripts/install_omz.sh install_omz.sh
RUN ./install_omz.sh                        \
    &&                                      \
    rm -rf install_omz.sh

# create workspace dir and make it default
RUN mkdir /root/workspace
COPY . /root/workspace
WORKDIR /root/workspace
