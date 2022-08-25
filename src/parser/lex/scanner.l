m4_changequote()
/*
m4_include(../mit.license)
*/
m4_define(PARSER_NS, ctl)
m4_include(ctl_includes.l)
m4_include(skeleton.l)

m4_include(tokens.l)
uuid [0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}
lloc [Ll][0-9]+

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION  loc.columns(yyleng);
%}

%%
%{
  // A handy shortcut to the location held by the driver.
  ctl::location& loc = drv->location;
  // Code run each time yylex is called.
  loc.step();
%}

"A" return ctl::parser::make_FORALL(loc);
"E" return ctl::parser::make_EXISTS(loc);
"F" return ctl::parser::make_FINALLY(loc);
"G" return ctl::parser::make_GLOBALLY(loc);
"X" return ctl::parser::make_NEXT(loc);
"U" return ctl::parser::make_UNTIL(loc);
"W" return ctl::parser::make_WEAK_UNTIL(loc);
{uuid} return ctl::parser::make_LOCATION(yytext, loc);
{lloc} return ctl::parser::make_LOCATION(yytext, loc);

m4_include(lexer.l)

%%

m4_include(footer.l)
m4_include(ctl_footer.l)
