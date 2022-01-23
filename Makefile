clear:
	del *.exe
	del .\bin\*.o

all: clear
	g++ -c src/DeltaTime/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ -c src/Asset/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ -c src/Animation/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ -c src/Sprite/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ -c src/Input/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include
	move *.o bin
	g++ bin/*.o -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

run:
	main.exe
	
