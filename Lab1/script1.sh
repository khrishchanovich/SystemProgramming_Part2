#!/bin/bash

rows=10
columns=30

main() {
    while true; do
        local x=$((RANDOM % columns))
        local y=$((RANDOM % rows))
        
        local time_str=$(date +%T)
        
        clear
        
        tput cup 0 0
        echo "+$(printf '%*s' $columns | tr ' ' -)+"
        
        for ((i=1; i<=rows; i++)); do
            tput cup $i 0
            echo "|"
            tput cup $i $((columns + 1))
            echo "|"
        done
       
        tput cup $rows 0
        echo "+$(printf '%*s' $columns | tr ' ' -)+"
        
        tput cup $y $x
        echo "$time_str"
    
        sleep 1
    done
}

main