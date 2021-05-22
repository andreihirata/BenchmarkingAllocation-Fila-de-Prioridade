#!/bin/bash

BASE_VALUES=(250000 500000 750000 1000000)

for value in ${BASE_VALUES[@]}; do
    /usr/bin/time -v ./main_enca A  I $value > enca_A_I_$value.txt 2>&1
    /usr/bin/time -v ./main_enca A  R $value > enca_A_R_$value.txt 2>&1
    /usr/bin/time -v ./main_enca CC I $value > enca_CC_I_$value.txt 2>&1
    /usr/bin/time -v ./main_enca CC R $value > enca_CC_R_$value.txt 2>&1
    /usr/bin/time -v ./main_enca CD I $value > enca_CD_I_$value.txt 2>&1
    /usr/bin/time -v ./main_enca CD R $value > enca_CD_R_$value.txt 2>&1
    
    /usr/bin/time -v ./main_heap A  I $value > heap_A_I_$value.txt 2>&1
    /usr/bin/time -v ./main_heap A  R $value > heap_A_R_$value.txt 2>&1
    /usr/bin/time -v ./main_heap CC I $value > heap_CC_I_$value.txt 2>&1
    /usr/bin/time -v ./main_heap CC R $value > heap_CC_R_$value.txt 2>&1
    /usr/bin/time -v ./main_heap CD I $value > heap_CD_I_$value.txt 2>&1
    /usr/bin/time -v ./main_heap CD R $value > heap_CD_R_$value.txt 2>&1
done
