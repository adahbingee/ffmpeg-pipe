g++ -O3 main.cpp
del output.mp4
a.exe | ffmpeg -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -i - -pix_fmt yuv420p output.mp4
pause