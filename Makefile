BOARD_TAG = mega_pic32
ARDUINO_LIBS = librtty

USER_LIB_PATH = .

ifndef SERIAL_PORT
SERIAL_PORT = /dev/ttyUSB*
endif

include arduino.mk/chipKIT.mk

flash: upload
