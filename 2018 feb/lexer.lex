%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include "formula.hpp"

using namespace std;

#include "parser.tab.hpp"
%}


%%
"head" {
    return head_token;
}
"tail" {
    return tail_token;
}
[a-z][a-z0-9]* {
    yylval.s = new string(yytext);
    return id_token;
}
[A-Z][A-Z0-9]* {
    return lista_token;
}
"True" {
    return true_token;
}
"False" {
    return false_token;
}
"Undef" {
    return undef_token;
}
"/\\" {
    return and_token;
}
"\\/" {
    return or_token;
}
"<=>" {
    return eq_token;
}
"=>" {
    return imp_token;
}
":=" {
    return dodela_token;
}
[!()\n\[\],] {
    return *yytext;
}
[ \t] {

}
[0-9]+ {
    return num_token;
}
. {
    cout << "Leksicka greska: neprepoznat karakter " << yytext << endl;
    exit(EXIT_FAILURE);
}


%%

