#!/bin/bash

read -p 'Enter X: ' x
read -p 'Enter Y: ' y
read -p 'Enter file name: ' fileName

for (( i=x; i<=y; i++ ))
do
    sed -n $i'p' $filename
done

# #!/bin/bash
# for arg in "$@"; do
#    grep -R "$arg" *
# done