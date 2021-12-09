!#/bin/bash

txt_dir=`ls ./*.txt`

num_dir=`$txt_dir | wc` 

echo $num_dir