izvrsni: lex.yy.o parser.o lista.o
	g++ -Wall -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp lista.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex 
	flex $<
parser.o: parser.tab.cpp parser.tab.hpp lista.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
lista.o: lista.cpp lista.hpp
	g++ -Wall -c -o $@ $<
	
.PHONY: clean

clean: 
	rm -f *~ *.tab.* lex.yy.c izvrsni *.o *.output
	
