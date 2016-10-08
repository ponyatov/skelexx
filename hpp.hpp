#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

struct Sym {										// base data class
	string tag,val;									// T:V pair
	Sym(string,string); Sym(string);				// constructors
	virtual string head(); string pad(int);			// \ object dump
	virtual string dump(int=0);						// /
};

													// \ lexer/parser interace
extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"								// /

#endif // _H_HPP
