build:
	g++ -std=c++11 -O2 -Wall -Wextra ./*.cpp -o app

compile_vector:
	g++ -std=c++11 -O2 -Wall -Wextra -c Vector.cpp -o Vector.o

run:
	./app

clean:
	rm -f app app.i

prep:
	g++ -E -std=c++11 ./*.cpp > app.i