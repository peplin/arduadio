BOARD_TAG    = diecimila
ARDUINO_LIBS = librtty

USER_LIB_PATH = .

SERIAL_PORT = /dev/ttyUSB*

include arduino.mk/Arduino.mk

flash: upload
