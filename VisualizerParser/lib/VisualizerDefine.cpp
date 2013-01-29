
#include "stdafx.h"
#include "VisualizerDefine.h"

using namespace visualizer_parser;


//------------------------------------------------------------------------
// 
//------------------------------------------------------------------------
void visualizer_parser::PrintToken( Tokentype token, char *szTokenString )
{
	switch( token )
	{
	case ID:
	case STRING:	printf( "string = %s\n", szTokenString ); break;

	case ASSIGN:	printf( "=" ); break;
	case TIMES:		printf( "*" ); break;
	case LPAREN:	printf( "(" ); break;
	case RPAREN:	printf( ")" ); break;
	case LBRACE:	printf( "{" ); break;
	case RBRACE:	printf( "}" ); break;
	case COMMA:		printf( "," ); break;
	case NUM:		printf( "number" ); break;
	case OR:		printf( "||" ); break;
	case AND:		printf( "&&" ); break;

	default: 		printf( "UnKnown token %d, %s\n", token, szTokenString ); break;
	}
}

/*
//------------------------------------------------------------------------
// typeStr: sArg->var->type
// 스트링을 타입으로 리턴한다.
//------------------------------------------------------------------------
_variant_t network::GetTypeStr2Type(const std::string &typeStr)
{
	if (typeStr == "std::string")
	{
		char *v=NULL;
		return _variant_t(v);
	}
	else if (typeStr == "string")
	{
		char *v=NULL;
		return _variant_t(v);
	}
	else if (typeStr == "float")
	{
		float v=0.f;
		return _variant_t(v);
	}
	else if (typeStr == "double")
	{
		double v=0.f;
		return _variant_t(v);
	}
	else if (typeStr == "int")
	{
		int v=0;
		return _variant_t(v);
	}
	else if (typeStr == "char")
	{
		char v='a';
		return _variant_t(v);
	}
	else if (typeStr == "short")
	{
		short v=0;
		return _variant_t(v);
	}
	else if (typeStr == "long")
	{
		long v=0;
		return _variant_t(v);
	}
	else if (typeStr == "bool")
	{
		bool v=true;
		return _variant_t(v);
	}
	else if (typeStr == "BOOL")
	{
		bool v=true;
		return _variant_t(v);
	}

	return _variant_t(1);
}


//------------------------------------------------------------------------
// packetID를 리턴한다. 여기서 Packet이란 sProtocol protocol을 의미하고, 
// sRmi 의 자식으로 순서대로 번호가 매겨진 값이 Packet ID이다.
//------------------------------------------------------------------------
int	network::GetPacketID(sRmi *rmi, sProtocol *packet)
{
	if (!rmi) return 0;
	if (!packet) return 0;

	int id = rmi->number + 1;
	sProtocol *p = rmi->protocol;
	while (p)
	{
		if (p == packet)
			break;
		++id;
		p = p->next;
	}
	return id;
}


//------------------------------------------------------------------------
// 패킷내용을 스트링으로 변환 한다.
//------------------------------------------------------------------------
std::string network::Packet2String(const CPacket &packet, sProtocol *protocol)
{
	if (!protocol) return "";

	std::stringstream ss;
	CPacket tempPacket = packet;

	int protocolID, packetID;
	tempPacket >> protocolID >> packetID;

	ss << protocol->name << " ";

	sArg *arg = protocol->argList;
	while (arg)
	{
		const _variant_t varType = GetTypeStr2Type(arg->var->type);
		const _variant_t var = tempPacket.GetVariant(varType);

		ss << arg->var->var + " = ";
		ss << common::variant2string(var);
		ss << ", ";

		arg = arg->next;
	}

	return ss.str();
}
/**/


SExpression* visualizer_parser::NewExpression( Kind kind )
{
	SExpression *p = new SExpression;
	p->kind = kind;
	return p;
}

SStatements* visualizer_parser::NewStatement( StatementKind kind )
{
	SStatements *p = new SStatements;
	p->kind = kind;
	return p;
}