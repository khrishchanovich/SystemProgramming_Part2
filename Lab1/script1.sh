#!/bin/bash

ROWS=10
COLUMNS=30

main() {
    while true; do
        local x=$((RANDOM % COLUMNS))
        local y=$((RANDOM % ROWS))
        
        local time_str=$(date +%T)
        
        clear
        
        tput cup 0 0
        echo "+$(printf '%*s' $COLUMNS | tr ' ' -)+"
        
        for ((i=1; i<=ROWS; i++)); do
            tput cup $i 0
            echo "|"
            tput cup $i $((COLUMNS + 1))
            echo "|"
        done
       
        tput cup $ROWS 0
        echo "+$(printf '%*s' $COLUMNS | tr ' ' -)+"
        
        tput cup $y $x
        echo "$time_str"
    
        sleep 1
    done
}

main