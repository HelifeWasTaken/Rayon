#include "Rayon/Text/RFont.hpp"

namespace rayon {
namespace text {

    RFont::RFont()
    {
        _font = GetFontDefault();
        _shouldDestroy = false;
    }

    RFont::RFont(const std::string& fileName)
    {
        _font = LoadFont(fileName.c_str());
    }

    RFont::RFont(const std::string& fileName, const int& fontSize,
        int* fontChars, const int& glyphCount)
    {
        _glyphCount = glyphCount;
        _font = LoadFontEx(fileName.c_str(), fontSize, fontChars, _glyphCount);
    }

    RFont::RFont(const Image& image, const Color& key, const int& firstChar)
    {
        _font = LoadFontFromImage(image, key, firstChar);
    }

    RFont::RFont(const std::string& fileType,
        const std::vector<unsigned char>& fileData, const int& fontSize,
        int* fontChars, const int& glyphCount)
    {
        _glyphCount = glyphCount;
        _font = LoadFontFromMemory(fileType.c_str(), fileData.data(),
            static_cast<int>(fileData.size()), fontSize, fontChars,
            _glyphCount);
    }

    RFont::~RFont()
    {
        if (_shouldDestroy) {
            UnloadFontData(_fontData, _glyphCount);
            UnloadFont(_font);
        }
    }

    Font& RFont::inner(void) { return _font; }

    Font& RFont::getFont(void) { return _font; }

    const Font& RFont::getFont(void) const { return _font; }

    Font RFont::getFontDefault(void) { return GetFontDefault(); }

    GlyphInfo* RFont::loadFontData(const std::vector<unsigned char>& fileData,
        const int& fontSize, int* fontChars, const int& glyphCount,
        const int& type)
    {
        return LoadFontData(fileData.data(), static_cast<int>(fileData.size()),
            fontSize, fontChars, glyphCount, type);
    }

    Image RFont::genImageFontAtlas(GlyphInfo* chars, Rectangle** recs,
        const int& glyphCount, const int& fontSize, const int& padding,
        const int& packMethod)
    {
        return GenImageFontAtlas(
            chars, recs, glyphCount, fontSize, padding, packMethod);
    }
}
}
