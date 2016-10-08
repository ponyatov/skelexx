" bI concept/programming dymanic language
syntax match Comment	"\v#[^\n]*"
syntax match Type		"\v[\(\)\[\]\{\}\=\@\:]"
syntax match Operator	"\v[\+\-\*\/\^]"
syntax match Constant	"\v(MODULE|TITLE|ABOUT|AUTHOR|LICENSE|GITHUB)"
syntax region Special	start="\"" end="\""
syntax region String	start="'" end="'"
