set inputSettings=-f rawvideo -pix_fmt rgb24 -video_size 1920x1080 -r 60
set outputSettings=-vcodec libx264 -x264opts opencl -pix_fmt yuv420p -r 60
set outputFile=output.mp4

del %outputFile%
a.exe 100 2>&1 | ffmpeg %inputSettings%  -i - %outputSettings% %outputFile%
pause