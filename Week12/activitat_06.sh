#!/bin/bash

check_proc(){

if [ $1 ]; then
    echo [$1] $(date +'%A, %d de %B de %Y, %T %Z')
    else
    echo [$$] $(date +'%A, %d de %B de %Y, %T %Z')
fi

}

check_proc

check_proc "1"