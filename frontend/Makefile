src = $(wildcard ./src/*.cpp)
socket = $(wildcard ../socket/socket.cpp)
main:main.cpp $(src) $(socket)
	g++ main.cpp $(src) $(socket) -o main
run:main
	./main 
clean:
	rm main
