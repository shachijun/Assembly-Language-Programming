all:formula mystery

formula:
	gcc -Wall nCr.s formula.c -m32 -o formula
mystery:
	gcc -Wall mystery.c -o mystery
clean:
	rm formula
	rm mystery
