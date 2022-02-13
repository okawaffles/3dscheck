#rm 3DSCheck.*
make
3dslink -a 192.168.1.71 3DSCheck.3dsx
#3dslink -a 192.168.1.48 3DSCheck.3dsx
make clean