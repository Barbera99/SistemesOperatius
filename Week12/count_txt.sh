#!/bin/bash

#num_dir=`ls ./*.txt | wc -l` 
num_dir=$(ls ./*.txt | wc -l) 

echo $num_dir
