#!/usr/bin/gnuplot

set termoption enhanced
set terminal svg size 800,600 font "Arial, 16"
set output "ex6_collisions.svg"
set encoding utf8

set style line 1 lc rgb "0xDC143C" lt 1 lw 4 pt 9 ps 1
set style line 2 lc rgb "0x6495ED" lt 1 lw 4 pt 7 ps 1

set border lw 2
set grid
set key top left

set xrange [10000:200000]
set xlabel "Количество элементов в словаре"
set ylabel "Количество коллизий" rotate by 90
set xtics 30000
set mxtics
set format x "%6.0f"
set format y "%6.0f"

plot "colisions_kr_and_add_ex6.dat" using 1:2 title "KRHash" with linespoints ls 1 smooth bezier, \
"colisions_kr_and_add_ex6.dat" using 1:3 title "AddHash" with linespoints ls 2 smooth bezier