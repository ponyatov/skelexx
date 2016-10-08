" bI concept/programming dymanic language
syntax match Comment	"\v#[^\n]*"
syntax match Type		"\v[\(\)\[\]\{\}\=\@\|\:]"
syntax match Operator	"\v[\+\-\*\/\^\%\<\>]"
syntax match Constant	"\v(MODULE|TITLE|ABOUT|AUTHOR|LICENSE|GITHUB|LOGO)"
syntax region Special	start="\"" end="\""
syntax region String	start="'" end="'"
syntax match Type		"\v(sym|num|str|doc|op|fn)"
syntax match COmment	"\v\@0x[0-9a-f]+"
