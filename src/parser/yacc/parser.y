m4_changequote()
/*
m4_include(../mit.license)
*/

m4_include(ctl_skeleton.y)

m4_include(tokens.y)
m4_include(ctl_tokens.y)
m4_include(ctl_token_types.y)

%%
%start queries;
queries:
  query { drv->add_tree($1); }
;

query:
  FORALL quantifier { $$ = ctl::syntax_tree_t(ctl::modal_op_t::A).concat($2); }
| EXISTS quantifier { $$ = ctl::syntax_tree_t(ctl::modal_op_t::E).concat($2); }
;

quantifier:
  NEXT predicate                  { $$ = ctl::syntax_tree_t(ctl::quantifier_t::X).concat($2); }
| GLOBALLY predicate              { $$ = ctl::syntax_tree_t(ctl::quantifier_t::G).concat($2); }
| FINALLY predicate               { $$ = ctl::syntax_tree_t(ctl::quantifier_t::F).concat($2); }
| predicate UNTIL predicate       { $$ = ctl::syntax_tree_t(ctl::quantifier_t::U).concat($1).concat($3); }
| predicate WEAK_UNTIL predicate  { $$ = ctl::syntax_tree_t(ctl::quantifier_t::W).concat($1).concat($3); }
;

predicate:
  "(" query ")" OR "(" query ")"        { $$ = BINOP_CTOR(_or,$2,$6); }
| "(" query ")" XOR "(" query ")"       { $$ = BINOP_CTOR(_xor,$2,$6); }
| "(" query ")" IMPLIES "(" query ")"   { $$ = BINOP_CTOR(_implies,$2,$6); }
| "(" query ")" AND "(" query ")"       { $$ = BINOP_CTOR(_and,$2,$6); }
| "(" query ")"                         { $$ = $2; }
| "(" predicate ")"                     { $$ = $2; }
| state                                 { $$ = $1; }
| exp                                   { $$ = $1; }
;

state:
  "location"                { $$ = LIT_CTOR(ctl::location_t{$1}); }
;

m4_include(exp.y)

%%
