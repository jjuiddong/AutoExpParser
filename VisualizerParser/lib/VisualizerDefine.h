//------------------------------------------------------------------------
// Name:    ScriptDefine.h
// Author:  jjuiddong
// Date:    1/3/2013
// 
// �������� �Ľ̿� ���õ� ����Ʈ����, ��������� ��Ƴ��Ҵ�.
//
// 2013-01-28
//		Inc, Dec �߰�
//
//------------------------------------------------------------------------
#pragma once

#include <string>

namespace visualizer_parser 
{
	enum
	{
		MAX_STRING = 256,
		MAX_ARGUMENT = 10,
	};

	enum Tokentype
	{
		_ERROR, NONE, ENDFILE, ID, NUM, FNUM, STRING, ASSIGN, LPAREN, RPAREN, LBRACE, RBRACE, 
		LBRACKET/* [ */, RBRACKET/* ] */, 
		DOT, COMMA, COLON, SEMICOLON,
		PLUS, MINUS, TIMES, DIV, REMAINDER, REF, ARROW, INC, DEC,
		LT/* < */, RT/* > */, LTEQ/* <= */, RTEQ/* >= */, NEQ/* != */, EQ/* == */, LOGIC_OR/* | */, OR/* || */, AND/* && */, NEG/* ! */, SCOPE/*::*/,

		// special
		IF, ELIF, ELSE, ARRAY, LIST,  TREE, CHILDREN, PREVIEW, STRINGVIEW,
		SHARP_BRACKET, 

	};

	enum NodeKind { Stmt, Exp };
	enum Kind
	{
		ProgramK, TutorialK, RoleTutorialK, TrainingK, PracticeK, StatementK, AIK, EventK, UIEventK, 
		CustomEventK, SuccessK, FailK, AssignK,
		ScriptWaitK, ScriptEndK, ScriptExitK, // statement

		//TypeK, 
		ConditionOpK, ConditionTreeK, OpK, IdK, FuncK, ParamK, ConstIntK, ConstFloatK, ConstStrK, CallK, // exp

		// expression
		CondExprK, AddTermK, MulTermK, FactorK, VariableK, IndirectK, NumberK, StringK, ExpressionK, TypeK, TextK, DispFormatK,

		// statement


	};

	enum { MAXCHILD=8, };

	enum eCONDITION_OP { OP_NONE, OP_AND, OP_OR, OP_NEG, OP_LT, OP_RT, OP_LTEQ, OP_RTEQ, OP_EQ, OP_NEQ };


	typedef struct _sTypeVar
	{
		std::string type;
		std::string var;

	} sTypeVar;

	typedef struct _sArg
	{
		sTypeVar *var;
		_sArg *next;
	} sArg;

	typedef struct _sProtocol
	{
		std::string name;
		sArg *argList;
		_sProtocol *next;
	} sProtocol;

	typedef struct _sRmi
	{
		std::string name;
		int number;
		sProtocol *protocol;
		_sRmi *next;
	} sRmi;


	struct SStatements;

	struct SExpression
	{
		Kind kind;

		Tokentype prefix_op;
		Tokentype varOpkind; //".", "->"
		Tokentype op;

//		union {
		float num;
		std::string str;
		SExpression *lhs;
//		}

		SExpression *rhs;
	};

	struct SType_Stmt;
	struct SType_TemplateArgs
	{
		SType_Stmt *type;
		SType_TemplateArgs *next;
	};

	struct SType_Stmt
	{
		std::string id;
		SType_TemplateArgs *templateArgs;
	};

	struct SType_Stmts
	{
		SType_Stmt *type;
		SType_Stmts *next;
	};


	enum Display_Format
	{
		Disp_D,
		Disp_U,
		Disp_O,
		Disp_X,
		Disp_L,
		Disp_F,
		Disp_E,
		Disp_G,
		Disp_C,
		Disp_S,
		Disp_SU,
		Disp_Auto,
	};

	struct SDisp_Format
	{
		SExpression *text;
		SExpression *exp;
		Display_Format format;
	};

	struct SAutoExp
	{
		SType_Stmts *match_type;
		SDisp_Format *disp_format;
	};

	struct SBracket_Inner_Stmts
	{
		SExpression *expr;
		SExpression *size;
		SExpression *rank;
		SExpression *base;
		SExpression *next ;
		SExpression *left;
		SExpression *right;
		SExpression *skip;
		SExpression *head;
	};

	struct SElif_Stmt
	{
		SExpression *cond;
		SStatements *stmts;
		SElif_Stmt *next;
	};

	struct SIf_Stmt
	{
		SExpression *cond;
		SStatements *stmts;
		SElif_Stmt *elif_stmt;
		SStatements *else_stmts;
	};

	enum VisBracketIteratorKind
	{
		Iter_Array,
		Iter_List,
		Iter_Tree
	};

	struct SVisBracketIterator_Stmt
	{
		VisBracketIteratorKind kind;
		SBracket_Inner_Stmts *stmts;
		SStatements *disp_stmt;
	};

	struct SSimpleExp
	{
		SExpression *text;
		SExpression *expr;
		Display_Format format;
	};

	enum StatementKind
	{
		Stmt_StringLiteral,
		Stmt_Expression,
		Stmt_SimpleExpression,
		Stmt_Preview,
		Stmt_StringView,
		Stmt_Children,
		Stmt_If,
		Stmt_Bracket_Iterator,
	};

	struct SStatements
	{
		StatementKind kind;
		std::string str_literal;
		union {
			SExpression *exp;
			SSimpleExp *simple_exp;
			SIf_Stmt *if_stmt;
			SVisBracketIterator_Stmt *itor_stmt;
		};
		SStatements *next;
	};

	struct SVisualizer
	{
		SType_Stmts *matchType;
		SStatements *preview;
		SStatements *stringview;
		SStatements *children;
	};

	enum VisualizerScriptKind
	{
		VisualizerScript_Visualizer,
		VisualizerScript_AutoExp,
	};

	struct SVisualizerScript
	{
		VisualizerScriptKind kind;
		union {
			SVisualizer *vis;
			SAutoExp *autoexp;
		};
		SVisualizerScript *next;
	};

	SExpression* NewExpression( Kind kind );
	SStatements* NewStatement( StatementKind kind );


	// Functions
	void PrintToken( Tokentype token, char *szTokenString );
// 	_variant_t	GetTypeStr2Type(const std::string &typeStr); // sArg->var->type
// 	int			GetPacketID(sRmi *rmi, sProtocol *packet);
// 	std::string Packet2String(const CPacket &packet, sProtocol *protocol);

}
