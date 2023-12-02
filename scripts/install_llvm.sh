#!/bin/bash
# -*- coding: utf-8 -*-

# assumes:
# - os is ubuntu 22.04 (jammy)
# - apt-get update has been run

llvm_version="18"

apt-get install -y lsb-release wget software-properties-common gnupg

wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
./llvm.sh ${llvm_version}
rm llvm.sh

apt-get install -y *clang*${llvm_version}* *llvm*${llvm_version}*

ln -sf /usr/bin/clang-${llvm_version} /usr/bin/clang
ln -sf /usr/bin/clang++-${llvm_version} /usr/bin/clang++
ln -sf /usr/bin/clangd-${llvm_version} /usr/bin/clangd
ln -sf /usr/bin/clang-cpp-${llvm_version} /usr/bin/clang-cpp
ln -sf /usr/bin/clang-format-${llvm_version} /usr/bin/clang-format
ln -sf /usr/bin/clang-tidy-${llvm_version} /usr/bin/clang-tidy
ln -sf /usr/bin/run-clang-tidy-${llvm_version} /usr/bin/run-clang-tidy

update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100
