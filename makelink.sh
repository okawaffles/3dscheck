#rm 3DSCheck.*
make
PATH=$PATH:/opt/devkitpro/tools/bin
#3dslink -a 192.168.1.71 3DSCheck.3dsx
3dslink -a 192.168.1.54 3DSCheck.3dsx
#3dslink -a 192.168.1.48 3DSCheck.3dsx
make clean