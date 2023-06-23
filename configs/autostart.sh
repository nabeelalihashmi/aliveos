#!/bin/bash
lxpolkit &
nitrogen --restore &
slstatus &
dunst &
picom &
copyq &
setxkbmap -layout us,pk
setxkbmap -option 'grp:alt_shift_toggle'
