CC=/usr/bin/gcc

SRC=.

.PHONY: clean

all: .PHONY
	$(CC) -c $(SRC)/*.c 

debug: .PHONY
	$(CC) $(SRC)/*.c -o ./ll -D__DEBUG__ -g

clean:
	@rm -f $(SRC)/*.o
	@rm -f $(SRC)/ll
