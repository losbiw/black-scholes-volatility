build:
	g++ -o out main.cpp option.cpp -std=c++20

test:
	g++ -o out test.cpp option.cpp -std=c++20