#!/bin/bash
name=$(basename $1)
x=$(pidof -x $(basename $1))

if [ $x ]; then

    echo "[ERROR]: Aquest script ja s’esta executant amb pid $x"

    echo "[INFO]: Eliminant procés amb pid $x"

    kill -9 $x

fi

echo "[INFO]: Executant el script amb nom $name amb el següent PID: $$."

/bin/bash $name


