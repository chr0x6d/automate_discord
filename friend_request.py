#!/usr/bin/python

import sys
from random import randint
from time import sleep

import pyautogui as pya

# Only run this many times
reqs_to_be_sent = int(sys.argv[1])

if not reqs_to_be_sent:
    reqs_to_be_sent = 999999

# How long in seconds we give discord to change between screens
sleep_time = 1

# scroll "clicks" on initial scroll, -25 should be enough for most servers
first_scroll = -25

# move mouse to top-left corner fast to force-exit
pya.FAILSAFE = True

pya.click(30, 128) # Highest discord server 1920x1080 fullscreen
pya.moveTo(1800, 550) # Hit user-list on right side
pya.scroll(first_scroll) # Scroll down from the admin and bot accounts
sleep(sleep_time+1)

for i in range(reqs_to_be_sent):
    pya.rightClick(1800, 550)
    sleep(sleep_time)
    pya.click(1655, 880)

    # Continue scrolling
    pya.click(1550, 300)
    pya.moveTo(1800, 800)
    pya.scroll(first_scroll - (randint(i+1, i+25)))
    # +1 because scrolling takes a long time to update
    sleep(sleep_time+1)
