#!/bin/bash
# -*- coding: utf-8 -*-

# assumes:
# - curl is installed
# - zsh is installed

sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
sed -i -- 's/ZSH_THEME="robbyrussell"/ZSH_THEME="agnoster"/g' /root/.zshrc
SNIPPET="export PROMPT_COMMAND='history -a' && mkdir -p /root/.commandhistory && export HISTFILE=/root/.commandhistory/.zsh_history"
echo "$SNIPPET" >> "/root/.zshrc"
chsh -s $(which zsh)
