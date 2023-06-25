CXX=clang++

esaulbe: main.o build.o rebuild.o exec.o clean.o buildiso.o vm.o vmdbg.o config.o version.o
	clang++ -o EsaulBE $^

clean:
	rm -f EsaulBE *.o
