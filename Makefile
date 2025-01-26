SRC := $(wildcard src/*.cpp) 

main:$(SRC)
	g++ $(SRC) -o main
run:main
	./main
clean:
	rm main
