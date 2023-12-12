#!/usr/bin/bash

shouldShowUptime() {
  if [ -z "$1" ]; then
    return 1
  else
    return 0
  fi
}

showuptime() {
    local up=$(uptime -p | cut -c4-)
    local since=$(uptime -s)

cat << EOF
------------------------------------------------
Hello $1 ${2:-unknown}!
This machine has been up for ${up}
It has been running since ${since}
------------------------------------------------
EOF
}

shouldShowUptime $1

if [ $? = 0 ]; then
  showuptime $1 $2
else
  echo "You need to identify yourself to check this information!"
fi