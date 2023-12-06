#!/usr/bin/bash

# If/Elif/Else

if [ ${1,,} = "cesar" ]; then
  echo "Oh, you're the boss here. Welcome!"
elif [ ${1,,} = "help" ]; then
  echo "Just enter your username!"
else
  echo "Mr. ${1:-unknown} ${2:-unknown}, I don't know who you are. But you're not the boss here!"
fi