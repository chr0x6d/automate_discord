#!/usr/bin/python

import sys
from time import sleep

import pyautogui as pya

# Only run this many times
deletes = int(sys.argv[1])

if not deletes:
    deletes = 999999

# How long in seconds we give discord to change between screens
sleep_time = 0.5

# move mouse to top-left corner fast to force-exit
pya.FAILSAFE = True

pya.click(345, 50)

for i in range(deletes):
    pya.click(500, 1035)
    pya.press('up')
    pya.hotkey('ctrl', 'a')
    pya.press('backspace')
    pya.press('enter')
    pya.press('enter')
    sleep(sleep_time)
