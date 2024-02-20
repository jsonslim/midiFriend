The best open source midi foot controller :)

Main advantages:
* TFT displays on each button
* Easily scalable code
* Big touch display to set the device (WT32-SC01, 1st version)
* WEB interface


Displays on the buttons:
TFT Driver  | ST7735
----------- | -----------
TFT_MISO  | N/A
TFT_MOSI  | 23
TFT_SCLK | 18
TFT_CS | differenr for each display
TFT_DC | 2
TFT_RST | 4

Buttons port extender - MCP23017:
* i2c mode
