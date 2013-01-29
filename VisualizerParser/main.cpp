
#include "stdafx.h"
#include "lib/VisualizerParser.h"

int _tmain(int argc, _TCHAR* argv[])
{
	visualizer_parser::CParser parser;
	visualizer_parser::SVisualizerScript *pscr = parser.Parse( "test.txt" );

	visualizer_parser::RemoveVisualizerScript( pscr );

	return 0;
}
