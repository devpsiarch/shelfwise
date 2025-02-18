SRC := $(wildcard backend/src/*.cpp) 
FLAGS := -o2 -Wall -Wextra -lssl -lcrypto -lmariadbcpp -g
HEADER := $(wildcard backend/include/*.h)
# moved here to force you to specify what the you wanna build.

clean:
	rm main
server:$(SRC) $(HEADER)
	g++ $(FLAGS) $(SRC) -o main
run:main
	./main
login:
	./frontend/login/build/Desktop-Debug/login
userpage:
	./frontend/userpage/build/Desktop-Debug/userpage
