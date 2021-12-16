#!/bin/bash

cat > act10.data << 'EOT'

102

071

210

153

EOT

clear

cat act10.data

declare -i SUM=0

while read X; do

SUM+="${X#"${X%%[!0]*}"}" ##Mitjançant amb el següent regex eliminem els 0 de l'esquerra.

echo "$SUM"
done < act10.data

echo "Suma: $SUM != 536"