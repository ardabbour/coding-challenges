#!/bin/bash
# -*- coding: utf-8 -*-

# assumes:
# - zsh is installed
# - nano is installed

wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh
echo "export PATH=/usr/lib/ccache:\$PATH" >> /root/.zshrc
echo "alias update-apt='apt update && apt upgrade -y && apt autoremove -y && apt autoclean -y'" >> /root/.zshrc
sed -i -- 's/ZSH_THEME="robbyrussell"/ZSH_THEME="agnoster"/g' /root/.zshrc
echo "export EDITOR=nano" >> /root/.zshrc
echo "export DEFAULT_USER=root" >> /root/.zshrc
SNIPPET="export PROMPT_COMMAND='history -a' && mkdir -p /root/.commandhistory && export HISTFILE=/root/.commandhistory/.zsh_history"
echo "$SNIPPET" >> "/root/.zshrc"
chsh -s $(which zsh) || true
