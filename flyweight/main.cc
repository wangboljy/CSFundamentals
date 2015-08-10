#include "flyweight.h"
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using namespace fw;

int main()
{
	Context w('w',1);
	Context a('a',2);
	Context n('n',3);
	Context g('g',4);
	Context b('b',5);
	Context o('o',6);

	vector<Context> v;
	v.push_back(w);
	v.push_back(a);
	v.push_back(n);
	v.push_back(g);
	v.push_back(b);
	v.push_back(o);

	Row *r = new Row();

	for(vector<Context>::iterator it = v.begin(); it != v.end(); ++it)
	{
		Glyph *g = GlyphFactory::getGlyph(&(*it));
		r->add(g);
	}

	r->draw();
	return 0;
}
