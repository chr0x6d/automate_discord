#!/usr/bin/python

import sys
from time import sleep

import pyautogui as pya

# Only run this many times
msgs_to_be_sent = int(sys.argv[1])
messages = sys.argv[2:]

if not msgs_to_be_sent:
    msgs_to_be_sent = 999999

# How long in seconds we give discord to change between screens
sleep_time = 0.3

# move mouse to top-left corner fast to force-exit
pya.FAILSAFE = True

pya.click(345, 50)

for i in range(msgs_to_be_sent):
    pya.click(500, 1035) # click on message box

    for msg in messages:
        pya.typewrite(msg)
        pya.press('enter') # send the message
        sleep(sleep_time)
