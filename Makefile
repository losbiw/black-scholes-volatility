build:
	g++ -o out main.cpp option.cpp math.cpp -std=c++20

test:
	g++ -o out test.cpp option.cpp math.cpp -std=c++20