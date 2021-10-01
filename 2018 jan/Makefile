izvrsni: lex.yy.o parser.o vektor.o
	g++ -Wall -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp vektor.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
parser.o: parser.tab.cpp parser.tab.hpp vektor.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
vektor.o: vektor.cpp vektor.hpp
	g++ -Wall -c -o $@ $<
	
.PHONY: clean 

clean: 
	rm -f *~ *.tab.* *.o *.output izvrsni lex.yy.c
	
