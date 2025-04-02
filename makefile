.PHONY clear:
	rm -rf build
	mkdir ./build
	touch ./build/.gitkeep
build/main : src/main.cpp src/get_flags.cpp src/flags.h src/version.h
	g++ src/main.cpp -o build/main
build/test : build_test/main.cpp
	g++ build_test/main.cpp -o build/test

all: clear build/main build/test