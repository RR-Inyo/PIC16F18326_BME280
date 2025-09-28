## PIC16F18326 and BME280-based CR2032-powered mobile barometer
I built a mobile barometer based on a Microchip PIC16F18326 microcotroller and Bosch Sensortec BME280 temperature/humidity/pressure sendor. It shows the data on a character LCD module based on an ST7032 LCD controller.

I was trying to make the system fancy as shown below.

<img src="DSC00086.JPG" style="width:360px" /> <img src="DSC00112.JPG" style="width:360px" />

I needed to create my code to communicate with the BME280 (partially based on the C code on its datasheet), to control the LCD module, and to convert binary data to decimal strings. They are all included in this repository.

To save the power consumption, the PIC microcontroller runs at 4 MHz and go into deep sleep when the tactile switch is pushed. When the tactile switch pushed again, the system resumes back.
