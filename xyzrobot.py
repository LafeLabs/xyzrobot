# open a anaconda prompt, move to c:\xampp\htdocs\xyzrobot and type
# python xyzrobot.py
import time
import serial
import os
ser = serial.Serial('COM6', 9600)
while True:
    f = open("xyzrobot.txt", "r")
    xyzrobotstring = f.read()
    ser.write(bytes(xyzrobotstring + '\n', encoding='utf-8'))
    f.close()
    time.sleep(0.01)