#include "Rayon/Text/Misc.hpp"

namespace rayon {
namespace text {

    Misc::Misc() { }

    Misc::~Misc() { }

    int Misc::measure(std::string text, int fontSize)
    {
        return MeasureText(text.c_str(), fontSize);
    }

    Vector2 Misc::measureEx(
        Font font, std::string text, float fontSize, float spacing)
    {
        return MeasureTextEx(font, text.c_str(), fontSize, spacing);
    }

    int Misc::getGlyphIndex(Font font, int codepoint)
    {
        return GetGlyphIndex(font, codepoint);
    }

    GlyphInfo Misc::getGlyphInfo(Font font, int codepoint)
    {
        return GetGlyphInfo(font, codepoint);
    }

    Rectangle Misc::getGlyphAtlasRec(Font font, int codepoint)
    {
        return GetGlyphAtlasRec(font, codepoint);
    }
}
}