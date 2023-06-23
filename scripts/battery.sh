#!/bin/bash

# Get battery information using upower
battery_info=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0)

# Extract relevant information
percentage=$(grep -E "percentage" <<< "$battery_info" | awk '{print $2}')
state=$(grep -E "state" <<< "$battery_info" | awk '{print $2}')
time_to_full=$(grep -E "time to full" <<< "$battery_info" | awk '{print $4}')
time_to_empty=$(grep -E "time to empty" <<< "$battery_info" | awk '{print $4}')
battery_icon=$(grep -E "icon-name" <<< "$battery_info" | awk '{print $2}')

# Determine whether to display time to empty or time to full
if [ "$state" = "charging" ]; then
  time_info="Time to Full: $time_to_full"
elif [ "$state" = "discharging" ]; then
  time_info="Time to Empty: $time_to_empty"
else
  time_info="N/A"
fi

# Display battery information
echo "Battery Percentage: $percentage"
echo "Battery State: $state"
echo "$time_info"
echo "Battery Icon: $battery_icon"
