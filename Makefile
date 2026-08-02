build:
	g++ -std=c++11 -O2 -Wall -Wextra ./src/*.cpp -o app

run:
	./app

clean:
	rm -f app app.i

prep:
	g++ -E -std=c++11 ./src/*.cpp > app.i