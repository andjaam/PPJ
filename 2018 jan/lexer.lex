%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include "vektor.hpp"

using namespace std;

#include "parser.tab.hpp"
%}

%%
"print" {
    return print_token;
}
"ugao" {
    return ugao_token;
}
"eqv" {
    return eqv_token;
}
[a-z] {
    yylval.c = *yytext;
    return id_token;
}
":=" {
    return dodela_token;
}
[||<>,;()\n*+-\.] {
    return *yytext;
}
[+-]?[0-9]+\.?[0-9]* {
    yylval.d = stod(yytext);
    return num_token;
}
[ \t] {

}
. {
    cout << "Leksicka greska: neprepoznat karakter " << yytext << endl;
    exit(EXIT_FAILURE);
}

%%

