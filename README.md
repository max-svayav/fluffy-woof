# fluffy-woof
MATLAB/Simulink shenanigans

A collection of makeshift scripts/models demonstrating how support packages from Mathworks can be used in [different versions](http://www.mathworks.com/matlabcentral/answers/99769-is-arduino-supported-in-releases-prior-to-r2012a#answer_109117) of MATLAB and Simulink. 

#### Arduino Uno/Mega support package for Simulink
The demo requires [support package](http://www.mathworks.com/hardware-support/arduino-simulink.html) and since S-functions are used to embed arduino code into the model compiler needs to be installed. The latter can be [tricky on modern Windows systems](http://www.mathworks.com/matlabcentral/answers/95039-why-does-the-sdk-7-1-installation-fail-with-an-installation-failed-message-on-my-windows-system#answer_104391). These particular files were tested on R2015a and, although the files may no be runnable on earlier versions, the model could be rebuilt on MATLAB versions starting with 2012a using the same approach.

* [yamashev.slx](yamashev.slx) - Simulink model based on a [draft](http://www.mathworks.com/matlabcentral/mlc-downloads/downloads/submissions/52238/versions/1/screenshot.jpg) suggested by the author of the original blocks for [LED display](http://www.mathworks.com/matlabcentral/fileexchange/52238-arduino-lcd-library) and [DS18B20](http://www.mathworks.com/matlabcentral/fileexchange/52236-arduino-ds-library).  The model has been altered to work with [DS18S20 sensor](http://datasheets.maximintegrated.com/en/ds/DS18S20.pdf) instead.
* [LCD1602_02_custom.cpp](LCD1602_02_custom.cpp) - Support code for LCD display written in C++ and exporting a C function which is used from an S-function builder in the model. The approach is similar to what is described [here](http://mattbilsky.com/mediawiki/index.php?title=Servo_Block_Library_for_Simulink_Arduino_Target&printable=yes#How_it_Works). This has been tested with an [LCD keypad shield](http://www.dfrobot.com/wiki/index.php?title=Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009)) clone. 
* [DS18B20_03_custom.cpp](DS18B20_03_custom.cpp) - Support code for DS18B20 sensor written in C++. Requires [OneWire library](http://www.pjrc.com/teensy/td_libs_OneWire.html) for Arduino.


#### Arduino IO support package for MATLAB
This demo was written and tested on R2015a, but may also work on R2014 versions of MATLAB. It requires [a support package](http://www.mathworks.com/hardware-support/arduino-matlab.html) to be installed.

* [Port13.m](Port13.m) - a script that controls a LED connected to a port of an arduino board in a fashion that resembles an SOS messsage in Morse code. Once run the script will stay in arduion board's memory and will not require MATLAB for the demo to operate.


#### Legacy Arduino support for MATLAB
A demo for legacy systems written and tested on R2010B. Requires a [script package download](http://www.mathworks.com/matlabcentral/fileexchange/32374-legacy-matlab-and-simulink-support-for-arduino) as well as standalone arduino IDE installation (i.e. MATLAB will not install anything for you). 

* [test_arduino.m](test_arduino.m) - script controlling a LED connected to a port of an arduino board causing it to blink. An obligatiry step for this script to work is preloading of a sketch shipped with the download package for Matlab using arduino IDE. This can be done just once before the scrip is run in MATLAB. However unlike with modern MATLAB versions, this script will not stay in board memory once it's been run in MATLAB, only the sketch will.
