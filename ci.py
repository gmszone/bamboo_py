import requests
import xml.etree.cElementTree as ET
import serial
import time

url = ''
s = serial.Serial(port='/dev/tty.usbmodem1451', baudrate=9600)
while(True):
    lastest = requests.get(url)
    if lastest.status_code == 200:
        root = ET.fromstring(lastest.text)
        print root.attrib["state"]
        if str(root.attrib["state"]) == "Successful":
                s.write('S')
        elif str(root.attrib["state"]) == "Fail":
                s.write('F')
        else:
                s.write('U')

    time.sleep(60)