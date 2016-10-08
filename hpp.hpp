#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Sym {										// base data class
	string tag,val;									// T:V pair
	Sym(string,string); Sym(string);				// constructors
	vector<Sym*> nest; void push(Sym*);				// nest[]ed elements
	virtual string head(); string pad(int);			// \ object dump
	virtual string dump(int=0);						// /
};

struct Scalar:Sym { Scalar(string,string); };		// scalars:
struct Str:Scalar { Str(string); string head(); };	// string
struct Doc:Str { Doc(string); };					// docstring

struct Num:Scalar { Num(string); float val;			// numbers:
	string head(); };
struct Int:Scalar { Int(string); int val;			// integer
	string head(); };
struct Hex:Scalar { Num(string); };					// machine hex
struct Bin:Scalar { Num(string); };					// binary string

struct Op:Sym { Op(string); };						// operator

													// \ lexer/parser interace
extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"								// /

#endif // _H_HPP
