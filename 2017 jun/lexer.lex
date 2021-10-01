%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include <string>
#include "lista.hpp"

using namespace std;

#include "parser.tab.hpp"
%}

%%
[+-]?[0-9]+ {
    yylval.i = atoi(yytext);
    return num_token;
}
[\n\[\].,;()] {
    return *yytext;
}
[ \t] {

}
"print" {
    return print_token;
}
"head" {
    return head_token;
}
"tail" {
    return tail_token;
}
"sort" {
    return sort_token;
}
"number" {
    return number_token;
}
"scalar" {
    return scalar_token;
}
[a-z][a-zA-Z0-9]{0,7} {
    yylval.s = new string(yytext);
    return id_token;
}
"==" {
    return jednakost_token;
}
"=" {
    return *yytext;
}
. {
    cout << "Leksicka greska: neprepoznat karakter " << yytext << endl;
    exit(EXIT_FAILURE);
}


%%

