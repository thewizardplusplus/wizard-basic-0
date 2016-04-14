SOURCE = source/
OBJECTS = \
	$(SOURCE)maths.o \
	$(SOURCE)numbers.o \
	$(SOURCE)output.o \
	$(SOURCE)system.o
BUILD = ../build/
CFLAGS += -std=c99 -Wpedantic -Wall -Wextra -O3 -m32

main: $(OBJECTS)
	mkdir -p $(BUILD)
	$(AR) crs $(BUILD)libwb4r.a $(OBJECTS)

clean:
	find . -name "*.o" -type f -delete
