all:
	make -C source all
	make -C tests all
clean:
	make -C source clean
	make -C tests clean
	
test:
	./tests/output/test.exe

