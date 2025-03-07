TARGET=sum-nbo
CXXFLAGS=-g
OPTS=-e
FMT= '%b'

all: $(TARGET) thousand.bin five-hundred.bin hundred-seventy-two.bin

$(TARGET): main.cpp
	gcc ${CXXFLAGS} -o ${TARGET} main.cpp

thousand.bin:
	/bin/echo -n $(OPTS) \\x00\\x00\\x03\\xe8 > $@

five-hundred.bin:
	/bin/echo -n $(OPTS) \\x00\\x00\\x01\\xf4 > $@

hundred-seventy-two.bin:
	/bin/echo -n $(OPTS) \\x00\\x00\\x00\\xac > $@

clean:
	rm -f ${TARGET}
	rm -f *.bin
