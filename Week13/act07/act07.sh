#!/bin/bash

output="mem_lliure.lst"
a_T=$(date +"%s")

# Comprovem si existeix el fitxer, en cas contrari el creem.
if [ ! -e $output ]; then
    touch $output
    printf "%20s \t %12s \t %12s \t %12s \n" "Time" "MemFree" "MemTotal" "MemAvailable" >> $output
fi
# Executem tant de temps com l'indicat.
if [ -z "$1" ]
then
      t=60
else
      t=$1
      duration=$(($a_T + $1))
fi

temps=$(date +"%s")
while [ "$(date +"%s")" != "$duration" ]
do
    if [ "$(date +"%s")" == $temps ]
    then
        memfree=$(awk '( $1 == "MemFree:" ) { print $2/1048576 }' /proc/meminfo)
        memtotal=$(awk '( $1 == "MemTotal:" ) { print $2/1048576 }' /proc/meminfo)
        memavailable=$(awk '( $1 == "MemAvailable:" ) { print $2/1048576 }' /proc/meminfo)
        actual_time=$(date +"%Y-%m-%d:%T")
        printf "%6s \t %12s \t %12s \t %12s \n" $actual_time $memfree $memtotal $memavailable >> $output
        temps=$(($temps + 1))
    fi
done
