SRC := $(wildcard src/*.cpp) 
# We use he ssl libary to compute the sha256 of user passwords to fetch them on db
FLAGS := -o2 -Wall -Wextra -lssl -lcrypto -lmariadbcpp -g


main:$(SRC)
	g++ $(FLAGS) $(SRC) -o main
run:main
	./main
clean:
	rm main


front:
	./login/build/Desktop-Debug/login
