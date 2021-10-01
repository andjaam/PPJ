%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include <cstdlib>
#include <set>
#include "skup.hpp"

using namespace std;

#include "parser.tab.hpp"
%}


%%
[A-Z]+ {
    yylval.c = *yytext;
    return id_token;
}
(-?[0-9])+ {
    yylval.i = atoi(yytext);
    return num_token;
}
".." {
    return dve_tacke_token;
}
"print" {
    return print_token;
}
"check" {
    return check_token;
}
"card" {
    return card_token;
}
"UniversalSet" {
    return universal_token;
}
[~={},;\n<:] {
    return *yytext;
}
[ \t] {

}
"\\/" {
    return unija_token;
}
"/\\" {
    return presek_token;
}
"\\" {
    return razlika_token;
}
. {
    cerr << "Leksicka greska: neprepoznat karakter " << *yytext << endl;
    exit(EXIT_FAILURE);
}
%%
