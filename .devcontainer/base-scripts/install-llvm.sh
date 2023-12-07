#!/bin/bash
# -*- coding: utf-8 -*-

# assumes:
# - apt-get update has been run

LLVM_VERSION="${$1:-18}"

apt-get install -y lsb-release wget software-properties-common gnupg

wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
./llvm.sh ${LLVM_VERSION}
rm llvm.sh

apt-get install -y *clang*${LLVM_VERSION}* *llvm*${LLVM_VERSION}*

ln -sf /usr/bin/clang-${LLVM_VERSION} /usr/bin/clang
ln -sf /usr/bin/clang++-${LLVM_VERSION} /usr/bin/clang++
ln -sf /usr/bin/clangd-${LLVM_VERSION} /usr/bin/clangd
ln -sf /usr/bin/clang-cpp-${LLVM_VERSION} /usr/bin/clang-cpp
ln -sf /usr/bin/clang-format-${LLVM_VERSION} /usr/bin/clang-format
ln -sf /usr/bin/clang-tidy-${LLVM_VERSION} /usr/bin/clang-tidy
ln -sf /usr/bin/run-clang-tidy-${LLVM_VERSION} /usr/bin/run-clang-tidy

update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100
