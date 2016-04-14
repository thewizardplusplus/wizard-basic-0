TARGET = nicole
TEMPLATE = lib
CONFIG += staticlib
CONFIG += console
CONFIG -= qt
HEADERS += \
	source/types.h \
	source/os.h \
	source/maths.h \
	source/system.h \
	source/output.h
SOURCES += \
	source/maths.c \
	source/system.c \
	source/output.c
QMAKE_CFLAGS += -Wall -W -pedantic -m32
