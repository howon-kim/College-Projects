# #1 Preparation

## Environment
* Operating System : Windows 10 Pro (x64)
* IDE : Pycharm (x32)
* Python Version : 2.7
* OpenCV Version : 2.4.13
* Pyserial, Pygame, Numpy : Any Version is Okay

## Installation Guide
### Numpy Installation Guide via [Stack Overflow](http://stackoverflow.com/questions/11200137/installing-numpy-on-64bit-windows-7-with-python-2-7-3)

**STEP 1**

> Assuming you have python 2.7 64bit on your computer and have downloaded numpy from here, follow the steps below (changing numpy-1.9.2+mkl-cp27-none-win_amd64.whl as appropriate).

>Download (by right click and "save target") get-pip to local drive.

>At the command prompt, navigate to the directory containing get-pip.py and run python get-pip.py which creates files in C:\Python27\Scripts, including pip2, pip2.7 and pip.

> Copy the downloaded numpy-1.9.2+mkl-cp27-none-win_amd64.whl into the above directory (C:\Python27\Scripts)

> Still at the command prompt, navigate to the above directory and run:

> pip2.7.exe install "numpy-1.9.2+mkl-cp27-none-win_amd64.whl"


**STEP 2**

> Download numpy-1.9.2+mkl-cp27-none-win32.whl from http://www.lfd.uci.edu/~gohlke/pythonlibs/#numpy .

> Copy the file to C:\Python27\Scripts

> Run cmd from the above location and type

> pip install numpy-1.9.2+mkl-cp27-none-win32.whl
> You will hopefully get the below output:

> Processing c:\python27\scripts\numpy-1.9.2+mkl-cp27-none-win32.whl
> Installing collected packages: numpy
> Successfully installed numpy-1.9.2
> Hope that works for you.

> EDIT 1
> Adding @oneleggedmule 's suggestion:

> You can also run the following command in the cmd:

> pip2.7 install numpy-1.9.2+mkl-cp27-none-win_amd64.whl
> Basically, writing pip alone also works perfectly (as in the original answer). Writing the version 2.7 can also be done for the sake of clarity or specification.

### OpenCV Installation Guide
1. [Download OpenCV v.2.4.13](http://opencv.org/downloads.html)
2. [OpenCV Documentation](http://docs.opencv.org/2.4/doc/tutorials/introduction/windows_install/windows_install.html)
3. [Stack Overflow](http://stackoverflow.com/questions/8941858/how-to-install-opencv-in-win7-64-bit)
