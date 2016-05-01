files = main.o tictacclass.o 

TicTacClass : $(files) tictacclass.h 
	g++ $(files) -o TicTacClass

main.o : main.cpp tictacclass.h 
	g++ -c main.cpp

tictacclass.o : tictacclass.cpp tictacclass.h
	g++ -c tictacclass.cpp

clean :
	rm $files TicTacClass
