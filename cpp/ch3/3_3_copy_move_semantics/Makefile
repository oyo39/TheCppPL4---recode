build_copy:
	g++ -std=c++11 -O2 -Icopy -Wall -Wextra ./*.cpp ./copy/*.cpp -o app

build_move:
	g++ -std=c++11 -O2 -Imove -Wall -Wextra ./*.cpp ./move/*.cpp -o app

run:
	./app < input.txt

clean:
	rm -f app app.i

prep_copy:
	g++ -E -std=c++11 -Icopy ./*.cpp ./copy/*.cpp > app.i

prep_move:
	g++ -E -std=c++11 -Imove ./*.cpp ./move/*.cpp > app.i