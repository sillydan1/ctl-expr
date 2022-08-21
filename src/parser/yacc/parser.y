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
  NEXT state_comp                  { $$ = ctl::syntax_tree_t(ctl::quantifier_t::X).concat($2); }
| GLOBALLY state_comp              { $$ = ctl::syntax_tree_t(ctl::quantifier_t::G).concat($2); }
| FINALLY state_comp               { $$ = ctl::syntax_tree_t(ctl::quantifier_t::F).concat($2); }
| state_comp UNTIL state_comp      { $$ = ctl::syntax_tree_t(ctl::quantifier_t::U).concat($1).concat($3); }
| state_comp WEAK_UNTIL state_comp { $$ = ctl::syntax_tree_t(ctl::quantifier_t::W).concat($1).concat($3); }
;

state_comp:
  state OR state            { $$ = BINOP_CTOR(_or,$1,$3); }
| state XOR state           { $$ = BINOP_CTOR(_xor,$1,$3); }
| state IMPLIES state       { $$ = BINOP_CTOR(_implies,$1,$3); }
| state AND state           { $$ = BINOP_CTOR(_and,$1,$3); }
| exp                       { $$ = $1; }
| state                     { $$ = $1; }
;

state:
  "location"                { $$ = LIT_CTOR(ctl::location_t{$1}); }
;

m4_include(exp.y)

%%
