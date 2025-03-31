build/main : main.cpp get_flags.cpp flags.h
	rm -rf ./build
	mkdir ./build
	g++ main.cpp -o build/main