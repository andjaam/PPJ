izvrsni: lex.yy.o parser.o formula.o
	g++ -Wall -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp formula.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
parser.o: parser.tab.cpp parser.tab.hpp formula.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
formula.o: formula.cpp formula.hpp
	g++ -Wall -c -o $@ $<
	
.PHONY: clean

clean: 
	rm -f *~ *.tab.* lex.yy.c izvrsni *.o *.output
	
