// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   ctllex



#include "ctl_parser.hpp"


// Unqualified %code blocks.
#line 58 "/home/agj/git/ctl-expr/Debug/yacc.y"

    #include "ctl_driver.h"
    void ctl ::parser::error (const location_type& l, const std::string& m) {
      std::cerr << l << ": " << m << '\n';
    }

#line 55 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if CTLDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !CTLDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !CTLDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace ctl {
#line 147 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"

  /// Build a parser object.
  parser::parser (ctl::driver* drv_yyarg)
#if CTLDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_query: // query
      case symbol_kind::S_quantifier: // quantifier
      case symbol_kind::S_predicate: // predicate
      case symbol_kind::S_state: // state
        value.YY_MOVE_OR_COPY< ctl::syntax_tree_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CLOCK: // "clk"
        value.YY_MOVE_OR_COPY< expr::clock_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_bin_op: // bin_op
      case symbol_kind::S_mono_op: // mono_op
      case symbol_kind::S_lit: // lit
        value.YY_MOVE_OR_COPY< expr::syntax_tree_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_ACCMOD: // "access_modifier"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_LOCATION: // "location"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_query: // query
      case symbol_kind::S_quantifier: // quantifier
      case symbol_kind::S_predicate: // predicate
      case symbol_kind::S_state: // state
        value.move< ctl::syntax_tree_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CLOCK: // "clk"
        value.move< expr::clock_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_bin_op: // bin_op
      case symbol_kind::S_mono_op: // mono_op
      case symbol_kind::S_lit: // lit
        value.move< expr::syntax_tree_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_ACCMOD: // "access_modifier"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_LOCATION: // "location"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_query: // query
      case symbol_kind::S_quantifier: // quantifier
      case symbol_kind::S_predicate: // predicate
      case symbol_kind::S_state: // state
        value.copy< ctl::syntax_tree_t > (that.value);
        break;

      case symbol_kind::S_CLOCK: // "clk"
        value.copy< expr::clock_t > (that.value);
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_bin_op: // bin_op
      case symbol_kind::S_mono_op: // mono_op
      case symbol_kind::S_lit: // lit
        value.copy< expr::syntax_tree_t > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_ACCMOD: // "access_modifier"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_LOCATION: // "location"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_BOOL: // "bool"
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_query: // query
      case symbol_kind::S_quantifier: // quantifier
      case symbol_kind::S_predicate: // predicate
      case symbol_kind::S_state: // state
        value.move< ctl::syntax_tree_t > (that.value);
        break;

      case symbol_kind::S_CLOCK: // "clk"
        value.move< expr::clock_t > (that.value);
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_bin_op: // bin_op
      case symbol_kind::S_mono_op: // mono_op
      case symbol_kind::S_lit: // lit
        value.move< expr::syntax_tree_t > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.move< float > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_ACCMOD: // "access_modifier"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_LOCATION: // "location"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if CTLDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 447 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_ACCMOD: // "access_modifier"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 453 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_NUMBER: // "number"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < int > (); }
#line 459 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // "float"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < float > (); }
#line 465 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_BOOL: // "bool"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < bool > (); }
#line 471 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_CLOCK: // "clk"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < expr::clock_t > (); }
#line 477 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_STRING: // "string"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 483 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_LOCATION: // "location"
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 489 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_query: // query
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < ctl::syntax_tree_t > (); }
#line 495 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_quantifier: // quantifier
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < ctl::syntax_tree_t > (); }
#line 501 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_predicate: // predicate
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < ctl::syntax_tree_t > (); }
#line 507 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_state: // state
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < ctl::syntax_tree_t > (); }
#line 513 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_exp: // exp
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < expr::syntax_tree_t > (); }
#line 519 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_bin_op: // bin_op
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < expr::syntax_tree_t > (); }
#line 525 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_mono_op: // mono_op
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < expr::syntax_tree_t > (); }
#line 531 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      case symbol_kind::S_lit: // lit
#line 103 "/home/agj/git/ctl-expr/Debug/yacc.y"
                 { yyo << yysym.value.template as < expr::syntax_tree_t > (); }
#line 537 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if CTLDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // CTLDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_BOOL: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_query: // query
      case symbol_kind::S_quantifier: // quantifier
      case symbol_kind::S_predicate: // predicate
      case symbol_kind::S_state: // state
        yylhs.value.emplace< ctl::syntax_tree_t > ();
        break;

      case symbol_kind::S_CLOCK: // "clk"
        yylhs.value.emplace< expr::clock_t > ();
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_bin_op: // bin_op
      case symbol_kind::S_mono_op: // mono_op
      case symbol_kind::S_lit: // lit
        yylhs.value.emplace< expr::syntax_tree_t > ();
        break;

      case symbol_kind::S_FLOAT: // "float"
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_ACCMOD: // "access_modifier"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_LOCATION: // "location"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // queries: query
#line 133 "/home/agj/git/ctl-expr/Debug/yacc.y"
        { drv->add_tree(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 837 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 3: // query: "A" quantifier
#line 137 "/home/agj/git/ctl-expr/Debug/yacc.y"
                    { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::modal_op_t::A).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 843 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 4: // query: "E" quantifier
#line 138 "/home/agj/git/ctl-expr/Debug/yacc.y"
                    { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::modal_op_t::E).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 849 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 5: // quantifier: "X" predicate
#line 142 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                  { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::quantifier_t::X).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 855 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 6: // quantifier: "G" predicate
#line 143 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                  { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::quantifier_t::G).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 861 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 7: // quantifier: "F" predicate
#line 144 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                  { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::quantifier_t::F).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 867 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 8: // quantifier: predicate "U" predicate
#line 145 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                  { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::quantifier_t::U).concat(yystack_[2].value.as < ctl::syntax_tree_t > ()).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 873 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 9: // quantifier: predicate "W" predicate
#line 146 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                  { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(ctl::quantifier_t::W).concat(yystack_[2].value.as < ctl::syntax_tree_t > ()).concat(yystack_[0].value.as < ctl::syntax_tree_t > ()); }
#line 879 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 10: // predicate: "(" query ")" "||" "(" query ")"
#line 150 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = BINOP_CTOR (_or,yystack_[5].value.as < ctl::syntax_tree_t > (),yystack_[1].value.as < ctl::syntax_tree_t > ()); }
#line 885 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 11: // predicate: "(" query ")" "^^" "(" query ")"
#line 151 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = BINOP_CTOR (_xor,yystack_[5].value.as < ctl::syntax_tree_t > (),yystack_[1].value.as < ctl::syntax_tree_t > ()); }
#line 891 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 12: // predicate: "(" query ")" "=>" "(" query ")"
#line 152 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = BINOP_CTOR (_implies,yystack_[5].value.as < ctl::syntax_tree_t > (),yystack_[1].value.as < ctl::syntax_tree_t > ()); }
#line 897 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 13: // predicate: "(" query ")" "&&" "(" query ")"
#line 153 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = BINOP_CTOR (_and,yystack_[5].value.as < ctl::syntax_tree_t > (),yystack_[1].value.as < ctl::syntax_tree_t > ()); }
#line 903 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 14: // predicate: "(" query ")"
#line 154 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = yystack_[1].value.as < ctl::syntax_tree_t > (); }
#line 909 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 15: // predicate: "(" predicate ")"
#line 155 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = yystack_[1].value.as < ctl::syntax_tree_t > (); }
#line 915 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 16: // predicate: state
#line 156 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = yystack_[0].value.as < ctl::syntax_tree_t > (); }
#line 921 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 17: // predicate: exp
#line 157 "/home/agj/git/ctl-expr/Debug/yacc.y"
                                        { yylhs.value.as < ctl::syntax_tree_t > () = ctl::syntax_tree_t(yystack_[0].value.as < expr::syntax_tree_t > ()); }
#line 927 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 18: // state: "location"
#line 161 "/home/agj/git/ctl-expr/Debug/yacc.y"
                            { yylhs.value.as < ctl::syntax_tree_t > () = LIT_CTOR(ctl::location_t{yystack_[0].value.as < std::string > ()}); }
#line 933 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 19: // exp: lit
#line 171 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = yystack_[0].value.as < expr::syntax_tree_t > (); }
#line 939 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 20: // exp: bin_op
#line 172 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = yystack_[0].value.as < expr::syntax_tree_t > (); }
#line 945 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 21: // exp: mono_op
#line 173 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = yystack_[0].value.as < expr::syntax_tree_t > (); }
#line 951 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 22: // bin_op: exp "+" exp
#line 177 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (plus,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());     }
#line 957 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 23: // bin_op: exp "-" exp
#line 178 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (minus,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());    }
#line 963 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 24: // bin_op: exp "*" exp
#line 179 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (star,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());     }
#line 969 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 25: // bin_op: exp "/" exp
#line 180 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (slash,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());    }
#line 975 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 26: // bin_op: exp "%" exp
#line 181 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (percent,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());  }
#line 981 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 27: // bin_op: exp "^" exp
#line 182 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (hat,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());      }
#line 987 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 28: // bin_op: exp ">" exp
#line 183 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (gt,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());       }
#line 993 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 29: // bin_op: exp ">=" exp
#line 184 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (ge,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());       }
#line 999 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 30: // bin_op: exp "==" exp
#line 185 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (ee,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());       }
#line 1005 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 31: // bin_op: exp "!=" exp
#line 186 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (ne,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());       }
#line 1011 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 32: // bin_op: exp "<=" exp
#line 187 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (le,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());       }
#line 1017 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 33: // bin_op: exp "<" exp
#line 188 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (lt,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());       }
#line 1023 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 34: // bin_op: exp "||" exp
#line 189 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (_or,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());      }
#line 1029 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 35: // bin_op: exp "^^" exp
#line 190 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (_xor,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());     }
#line 1035 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 36: // bin_op: exp "=>" exp
#line 191 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (_implies,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ()); }
#line 1041 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 37: // bin_op: exp "&&" exp
#line 192 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_BINOP_CTOR (_and,yystack_[2].value.as < expr::syntax_tree_t > (),yystack_[0].value.as < expr::syntax_tree_t > ());     }
#line 1047 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 38: // mono_op: "!" exp
#line 196 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_MONOOP_CTOR (_not,yystack_[0].value.as < expr::syntax_tree_t > ());        }
#line 1053 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 39: // mono_op: "(" exp ")"
#line 197 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_MONOOP_CTOR (parentheses,yystack_[1].value.as < expr::syntax_tree_t > ()); }
#line 1059 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 40: // lit: "number"
#line 201 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (yystack_[0].value.as < int > ());   }
#line 1065 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 41: // lit: "-" "number"
#line 202 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (-yystack_[0].value.as < int > ());  }
#line 1071 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 42: // lit: "float"
#line 203 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (yystack_[0].value.as < float > ());   }
#line 1077 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 43: // lit: "-" "float"
#line 204 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (-yystack_[0].value.as < float > ());  }
#line 1083 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 44: // lit: "string"
#line 205 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (yystack_[0].value.as < std::string > ());   }
#line 1089 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 45: // lit: "bool"
#line 206 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (yystack_[0].value.as < bool > ());   }
#line 1095 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 46: // lit: "identifier"
#line 207 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_IDENT_CTOR (yystack_[0].value.as < std::string > ()); }
#line 1101 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;

  case 47: // lit: "clk"
#line 208 "/home/agj/git/ctl-expr/Debug/yacc.y"
                        { yylhs.value.as < expr::syntax_tree_t > () = EXP_LIT_CTOR (yystack_[0].value.as < expr::clock_t > ());   }
#line 1107 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"
    break;


#line 1111 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if CTLDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if CTLDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if CTLDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -11;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -10,    53,    53,    19,   -11,    -2,   100,    66,   -11,   -11,
     -11,   -11,   -11,   -11,    87,    87,    87,   -11,   -11,    15,
     -11,   129,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   100,
     -11,    33,    34,     0,   -11,   -11,   -11,    87,    87,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,     0,    21,   -11,   -11,   -11,
     -11,    51,    51,    51,    51,    51,    51,   177,   161,   145,
     -11,    54,    54,    54,    54,    54,    54,    44,    45,    47,
      48,   -10,   -10,   -10,   -10,    49,    50,    58,    79,   -11,
     -11,   -11,   -11
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     2,     0,     0,     0,    46,    40,
      42,    45,    47,    44,     0,     0,     0,    18,     3,     0,
      16,    17,    20,    21,    19,     4,     1,    41,    43,     0,
      38,     0,     0,     0,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    39,     8,
       9,    23,    22,    24,    25,    26,    27,    37,    34,    35,
      36,    28,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      10,    11,    12
  };

  const signed char
  parser::yypgoto_[] =
  {
     -11,   -11,    -7,    99,    13,   -11,    -5,   -11,   -11,   -11
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     4,    18,    19,    20,    21,    22,    23,    24
  };

  const signed char
  parser::yytable_[] =
  {
      31,    30,    33,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    26,
      32,    58,     1,     2,    55,    27,    28,    34,    35,    36,
      77,    78,    79,    80,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      59,    60,    37,    38,    56,    57,     5,    39,    40,    41,
      42,    43,    44,    48,    81,    82,    48,    83,    84,     5,
      89,    90,     6,     7,    85,    86,    87,    88,     8,    91,
       9,    10,    11,    12,    13,     6,     7,    14,    15,    16,
       5,     8,    17,     9,    10,    11,    12,    13,     1,     2,
      92,    25,     0,     5,     0,    17,     6,     7,     0,     0,
       0,     0,     8,     0,     9,    10,    11,    12,    13,     6,
      29,     0,     0,     0,     0,     8,    17,     9,    10,    11,
      12,    13,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    48,    49,    50,
      51,    52,    53,    54,    39,    40,    41,    42,    43,    44,
      45,     0,     0,    48,    49,    50,    51,    52,    53,    54,
      39,    40,    41,    42,    43,    44,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54
  };

  const signed char
  parser::yycheck_[] =
  {
       7,     6,     7,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       7,    21,    32,    33,    29,    27,    28,    14,    15,    16,
       9,    10,    11,    12,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      37,    38,    37,    38,    21,    21,     3,     3,     4,     5,
       6,     7,     8,    12,    20,    20,    12,    20,    20,     3,
      21,    21,    19,    20,    81,    82,    83,    84,    25,    21,
      27,    28,    29,    30,    31,    19,    20,    34,    35,    36,
       3,    25,    39,    27,    28,    29,    30,    31,    32,    33,
      21,     2,    -1,     3,    -1,    39,    19,    20,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    19,
      20,    -1,    -1,    -1,    -1,    25,    39,    27,    28,    29,
      30,    31,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18
  };

  const signed char
  parser::yystos_[] =
  {
       0,    32,    33,    41,    42,     3,    19,    20,    25,    27,
      28,    29,    30,    31,    34,    35,    36,    39,    43,    44,
      45,    46,    47,    48,    49,    43,     0,    27,    28,    20,
      46,    42,    44,    46,    44,    44,    44,    37,    38,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    46,    21,    21,    21,    44,
      44,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,     9,    10,    11,
      12,    20,    20,    20,    20,    42,    42,    42,    42,    21,
      21,    21,    21
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    46,
      46,    46,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    48,    48,
      49,    49,    49,    49,    49,    49,    49,    49
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     3,     3,
       7,     7,     7,     7,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     2,     1,     2,     1,     1,     1,     1
  };


#if CTLDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "YYEOF", "error", "\"invalid token\"", "\"-\"", "\"+\"", "\"*\"",
  "\"/\"", "\"%\"", "\"^\"", "\"&&\"", "\"||\"", "\"^^\"", "\"=>\"",
  "\">\"", "\">=\"", "\"==\"", "\"!=\"", "\"<=\"", "\"<\"", "\"!\"",
  "\"(\"", "\")\"", "\":=\"", "\"type\"", "\";\"", "\"identifier\"",
  "\"access_modifier\"", "\"number\"", "\"float\"", "\"bool\"", "\"clk\"",
  "\"string\"", "\"A\"", "\"E\"", "\"X\"", "\"G\"", "\"F\"", "\"U\"",
  "\"W\"", "\"location\"", "$accept", "queries", "query", "quantifier",
  "predicate", "state", "exp", "bin_op", "mono_op", "lit", YY_NULLPTR
  };
#endif


#if CTLDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   133,   133,   137,   138,   142,   143,   144,   145,   146,
     150,   151,   152,   153,   154,   155,   156,   157,   161,   171,
     172,   173,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   196,   197,
     201,   202,   203,   204,   205,   206,   207,   208
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // CTLDEBUG


} // ctl
#line 1790 "/home/agj/git/ctl-expr/Debug/ctl_parser.cpp"

#line 216 "/home/agj/git/ctl-expr/Debug/yacc.y"

