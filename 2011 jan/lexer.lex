%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include <cstdlib>
#include <string>
#include "razlomak.hpp"

using namespace std;

#include "parser.tab.hpp"
%}

%%
[+-]?[0-9]+ {
    yylval.i = atoi(yytext);
    return num_token;
}
"+=" {
    return dodaj_token;
}
"-=" {
    return oduzmi_token;
}
"*=" {
    return pomnozi_token;
}
"/=" {
    return podeli_token;
}
"==" {
    return jednako_token;
}
[=;\n(),+*/-] {
    return *yytext;
}
\[|\] {
    return *yytext;
}
"fraction" {
    return fraction_token;
}
"print" {
    return print_token;
}
"check" {
    return check_token;
}
"numerator" {
    return numerator_token;
}
"denominator" {
    return denominator_token;
}
"double" {
    return double_token;
}
[a-z][a-zA-Z0-9]* {
    yylval.s = new string(yytext);
    return id_token;
}
[ \t] {

}
. {
    cout << "Leksicka greska: neprepoznat karakter " << *yytext << endl;
    exit(EXIT_FAILURE);
}
%%
