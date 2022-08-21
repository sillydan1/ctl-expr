m4_changequote()
/*
m4_include(../mit.license)
*/

m4_include(ctl_includes.l)
m4_include(skeleton.l)

m4_include(tokens.l)
uuid [0-9a-fA-F]{8}\b-[0-9a-fA-F]{4}\b-[0-9a-fA-F]{4}\b-[0-9a-fA-F]{4}\b-[0-9a-fA-F]{12}
lloc [Ll][0-9]+

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION  loc.columns(yyleng);
%}

%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv->location;
  // Code run each time yylex is called.
  loc.step();
%}

"A" return yy::parser::make_FORALL(loc);
"E" return yy::parser::make_EXISTS(loc);
"F" return yy::parser::make_FINALLY(loc);
"G" return yy::parser::make_GLOBALLY(loc);
"X" return yy::parser::make_NEXT(loc);
"U" return yy::parser::make_UNTIL(loc);
"W" return yy::parser::make_WEAK_UNTIL(loc);
{uuid} return yy::parser::make_LOCATION(yytext, loc);
{lloc} return yy::parser::make_LOCATION(yytext, loc);

m4_include(lexer.l)

%%

m4_include(footer.l)
m4_include(ctl_footer.l)
