#!/bin/bash

series=($(awk -F: '{ print $1 }' series.db)) # Totes les series.
s_o=($(printf "%s\n" "${series[@]}" | sort -u)) # Ordenem les series, eliminem duplicats i les guardem.


actors_0=($(awk -F: '( $1 == "'${s_o[0]}'" ) { print $2 }' series.db)) # Actors d'una serie.

actors_0_o=($(printf "%s\n" "${actors_0[@]}" | sort -u)) # Actors ordenats.


actor_0_d=$(awk -F: '( $1 == "'${s_o[0]}'" && $2 == "'${actors_0_o[0]}'" ) { print $3  }' series.db) # Frases d'un actor.
echo ${actor_0_d[0]}

#actor_0_d_arr=($(awk -F. '))

actor_0_d_o=($(printf "%s\n" "${actor_0_d[@]}" | sort -u))



echo ${actor_0_d[1]}