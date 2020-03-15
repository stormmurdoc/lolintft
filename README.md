# Lolin TFT 2.4"

First test code for the Lolin Wemos 2.4" TFT Display.

## Installation

Run the platformio command to init.

         platformio run

## Set your COM Port

Set in the platformio.ini file the following entty
          upload_port = /dev/ttyUSB0

## Upload code

         platformio run --target upload
