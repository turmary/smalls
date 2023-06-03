#!/bin/bash

# https://unix.stackexchange.com/questions/77253/bash-console-progress-dialog-with-command-output

let total=32 #__GET_MAX_COUNT__
let idx=0
let percent=0
let width=$(tput cols)
let height=$(tput lines)
log=$(mktemp --tmpdir dialog-progress.logXXX)
__COMMAND__='echo $idx'

{
for ((i = 0; i <= total; i++)); do
cat <<EOF
XXX
$percent
Converting $index ($percent %)
XXX
EOF
     let idx++
     let "percent = 100 * idx / total"
     eval $__COMMAND__ >> $log
     sleep 0.1
done
} | dialog \
        --title "Dialog example progress with command output" \
        --begin 2 2 \
        --tailboxbg $log $((height - 14)) $((width - 6)) \
        --and-widget \
	--begin $((height - 10)) 2 \
        --gauge "Converting ..." 8 $((width - 6)) 0

reset
