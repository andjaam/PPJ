izvrsni: lex.yy.o parser.o razlomak.o
	g++ -Wall -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp razlomak.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
parser.o: parser.tab.cpp parser.tab.hpp razlomak.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
razlomak.o: razlomak.cpp razlomak.hpp
	g++ -Wall -c -o $@ $<
	
.PHONY: clean

clean: 
	rm -f *~ *.tab.* lex.yy.c *.o izvrsni *.output
	
