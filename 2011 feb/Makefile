izvrsni: lex.yy.o parser.o skup.o
	g++ -Wall -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp skup.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex 
	flex $<
parser.o: parser.tab.cpp parser.tab.hpp skup.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
skup.o: skup.cpp skup.hpp
	g++ -Wall -c -o $@ $<
	
.PHONY: clean

clean:
	rm -f *~ *.tab.* lex.yy.c *.o izvrsni *.output
