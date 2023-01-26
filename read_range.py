""" Python code to plot range from VL6180X.
Set the COM port as necessary

Miakatt - 26-01-2023
Free to use. Please let me know of any improvements!

"""


import serial
from collections import deque
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import csv
import time
# Reads the data from the serial line and plots it on a scrolling axis.
import winsound

def animate(i):
    try:
        global x
        if ser.inWaiting():
            y_str = ser.readline(ser.in_waiting)
            data_in = (y_str.decode('utf-8')).strip().split(sep=',')
            x = data_in[0]
            y = data_in[1]

            data.append((float(x), float(y)))
            ax.relim()
            ax.autoscale_view()
            line.set_data(*zip(*data))
        append_to_csv(x, y)  # Optional write data to a csv file.
    except ValueError:
        print("Error")
    except IndexError:
        print("Waiting for data...")

# Write to CSV. 
def append_to_csv(x, y):
    with open('range.csv', 'a') as fd:
        fd.write(x + "," + y + "\n")


# Set up serial port to ESP8266
ser = serial.Serial(
    port='COM6',       # Set the COM port to whatever it shows in Device Properties.
    baudrate=115200,
    timeout=1)
time.sleep(3)

# Send reset distance to ESP32
ser.write(bytes(b'R'))
time.sleep(0.1)
print(ser.readline())  # Should return 'Resetting Distance'.

# Set up a plot figure
fig, ax = plt.subplots(figsize=(16,5))
x = 1
y = np.random.randn()
data = deque([(x, y)], maxlen=100)
line, = ax.plot(*zip(*data), c='red')

# Animate figure as the encoder rotates.
ani = animation.FuncAnimation(fig, animate, interval=1)
plt.show()
