#!/bin/bash 

ffmpeg -i V_20200405_101037.mp4 -vsync 0 "colorframes/%03d.png"

./color_to_bw colorframes/*

mkdir bwframes
mv *.png bwframes
