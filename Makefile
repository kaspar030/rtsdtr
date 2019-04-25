all: dtr rts

dtr: dtr.c
	$(CC) -Wall -Os $< -o $@

rts: rts.c
	$(CC) -Wall -Os $< -o $@
