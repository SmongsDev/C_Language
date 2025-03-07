TARGET=sum-nbo
CXXFLAGS=-g

all: $(TARGET) thousand.bin five-hundred.bin hundred-seventy-two.bin

$(TARGET): main.cpp
	gcc ${CXXFLAGS} -o ${TARGET} main.cpp

thousand.bin:
	/bin/echo -n -e \\x00\\x00\\x03\\xe8 > $@

five-hundred.bin:
	/bin/echo -n -e \\x00\\x00\\x01\\xf4 > $@

hundred-seventy-two.bin:
	/bin/echo -n -e \\x00\\x00\\x00\\xac > $@

clean:
	rm -f ${TARGET}
	rm -f *.bin
