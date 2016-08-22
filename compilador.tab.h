/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    IDENT = 268,
    ATRIBUICAO = 269,
    LABEL = 270,
    TYPE = 271,
    ARRAY = 272,
    OF = 273,
    PROCEDURE = 274,
    FUNCTION = 275,
    GOTO = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    WHILE = 280,
    DO = 281,
    ABRE_CHAVES = 282,
    FECHA_CHAVES = 283,
    ABRE_COLCHETES = 284,
    FECHA_COLCHETES = 285,
    IGUAL = 286,
    DIFERENTE = 287,
    MAIOR = 288,
    MENOR = 289,
    MAIOR_IGUAL = 290,
    MENOR_IGUAL = 291,
    BAND = 292,
    BOR = 293,
    OTHER_BOR = 294,
    BNOT = 295,
    BLSO = 296,
    BRSO = 297,
    SOMA = 298,
    MENOS = 299,
    MULTI = 300,
    MOD = 301,
    DIV = 302,
    OR = 303,
    AND = 304,
    NOT = 305,
    XOR = 306,
    TRUE = 307,
    FALSE = 308,
    WRITE = 309,
    READ = 310,
    NUMERO = 311,
    INTEGER = 312,
    BOOLEAN = 313,
    LOWER_THAN_ELSE = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */
