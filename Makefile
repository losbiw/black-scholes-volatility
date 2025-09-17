build:
	g++ -o out ./src/main.cpp ./src/option.cpp ./src/math.cpp -std=c++20

test:
	g++ -o out ./test/test.cpp ./src/option.cpp ./src/math.cpp -std=c++20

debug:
	g++ -o out ./test/test.cpp ./src/option.cpp ./src/math.cpp -std=c++20 -g