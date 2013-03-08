BOARD_TAG    = diecimila
ARDUINO_LIBS =

SERIAL_PORT = /dev/ttyUSB*

include arduino.mk/Arduino.mk

flash: upload
