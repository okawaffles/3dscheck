# this is a small script i made to easily make and send programs to my 3ds'es
# feel free to use it.
#rm 3DSCheck.*
make
PATH=$PATH:/opt/devkitpro/tools/bin # << VERY IMPORTANT FOR WINDOWS MSYS2, COMMENT OUT IF YOU ARE ON REAL LINUX!
3dslink -a 192.168.1.71 3DSCheck.3dsx # << Replace with your 3DS's IP.
#3dslink -a 192.168.1.54 3DSCheck.3dsx
#3dslink -a 192.168.1.48 3DSCheck.3dsx
make clean