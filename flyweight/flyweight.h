#ifndef FLY_WEIGHT_H
#define FLY_WEIGHT_H

#include <cstdio>
#include <list>
#include <map>
#include <utility>
using std::pair;
using std::list;
using std::map;

namespace fw
{
	struct Context;

	class Glyph
	{
		public:
			virtual void draw() = 0;
	};

	struct Context
	{
			char c;
			int size;
			Context(char c, int size):c(c),size(size){}
	};

	class Character:public Glyph
	{
		private:
			char c;
			int size;

		public:
			virtual void draw()
			{
				printf("draw context %c with size %d\n", c, size);
			}

		class Builder
		{
			public:
				static Character* build(Context *context)
				{
					Character *character = new Character();
					character->c = context->c;
					character->size = context->size;
					return character;
				}
		};
	};

	class Row:public Glyph
	{
		private:
			list<Glyph*> *row;
		public:
			Row()
			{
				row = new list<Glyph*>();
			}
			void add(Glyph *c)
			{
				row->push_back(c);
			}
			virtual void draw()
			{
				for(list<Glyph*>::iterator it = row->begin(); it != row->end(); ++it)
				{
					(*it)->draw();
				}
			}
	};

	class GlyphFactory
	{
		private:
			static map<Context*, Glyph*> glyphMap;
		public:
			static Glyph *getGlyph(Context *c)
			{
				if(glyphMap.find(c) == glyphMap.end())
				{
					Glyph *g = Character::Builder::build(c);
					glyphMap.insert(pair<Context*,Glyph*>(c, g));
				}

				return glyphMap[c];
			}
	};
	map<Context*,Glyph*> GlyphFactory::glyphMap;

};
#endif
