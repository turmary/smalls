/* tary, 2013-06-06 18:00 */
digit [0-9]
digits {digit}+
whitespace [ \t\n]

%%
"[" { return (OPEN_BRAC); }
"]" { return (CLOSE_BRAC); }
"+" { return (ADDOP); }
"*" { return (MULTOP); }
{digits} { yylval = atoi(yytext); return (NUMBER); }
whitespace;
