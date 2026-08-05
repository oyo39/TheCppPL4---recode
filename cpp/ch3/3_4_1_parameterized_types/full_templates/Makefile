build:
	g++ -std=c++11 -O2 -Wall -Wextra ./*.cpp -o app

run:
	./app < input.txt

clean:
	rm -f app app.i

prep:
	g++ -E -std=c++11 ./*.cpp > app.i