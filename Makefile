
arpp: Main.o Utils.o Error.o Lexer.o
	g++ Main.o Utils.o Error.o Lexer.o -o arpp

Main.o:
	g++ -c ./src/Main.cpp

Utils.o:
	g++ -c ./src/Utils.cpp

Error.o:
	g++ -c ./src/Errorhandle.cpp -o Error.o

Lexer.o:
	g++ -c ./src/Lexer.cpp -o Lexer.o
clean:
	rm *.o arpp.exe