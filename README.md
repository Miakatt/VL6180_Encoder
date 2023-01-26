# VL6180_Encoder
Reading a VL6180X Lidar range finder, triggered with a 600p/r bi-directional encoder using an ESP8266 D1 Mini.   
Distance counter is reset when the python code running on the laptop is started. 
Change the COM port in read_range.py (look at Device Manager ports section).   

D1 Mini Pin Connections. 
VL6160 SCL --> D1 Mini Pin D1   
VL6180 SDA --> D1 Mini Pin D2   
VL6180 Vcc --> D1 Mini 5V   
VL6180 Gnd --> D1 Mini G   


600 P/R Encoder (https://www.amazon.co.uk/dp/B07R6GS3YY?psc=1&ref=ppx_yo2ov_dt_b_product_details)  
Vcc --> 5V on D1 Mini  
Gnd --> G on D1 Mini  
ChA (Green) pull-up to Vcc with 1k resistor. Fed via a level shifter (or potential divider 1k/2k) to D0  
ChB (Red) pull-up to Vcc with 1k resistor. Fed via a level shifter (or potential divider 1k/2k) to D6  
* ChA and ChB may be the wrong way roung. If forward is backwards, just swap the wires.      
