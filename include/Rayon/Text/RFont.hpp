#pragma once

#include "raylib.h"
#include <string>
#include <vector>

namespace rayon {
namespace text {
    /**
     * @brief RFont class
     * @details Font related functions
     */
    class RFont {
    public:
        /**
         * @brief Construct a new RFont object
         *
         */
        RFont();
        /**
         * @brief Construct a new RFont object with a given fileName
         *
         * @param fileName
         */
        RFont(const std::string& fileName);
        /**
         * @brief Load font from file into GPU memory (VRAM)
         *
         * @param fileName
         * @param fontSize
         * @param fontChars
         * @param glyphCount
         */
        RFont(const std::string& fileName, const int& fontSize, int* fontChars,
            const int& glyphCount);
        /**
         * @brief Load font from Image (XNA style)
         *
         * @param image
         * @param key
         * @param firstChar
         */
        RFont(const Image& image, const Color& key, const int& firstChar);
        /**
         * @brief Load font from memory buffer, fileType refers to extension:
         * i.e. '.ttf'
         *
         * @param fileType
         * @param fileData
         * @param fontSize
         * @param fontChars
         * @param glyphCount
         */
        RFont(const std::string& fileType,
            const std::vector<unsigned char>& fileData, const int& fontSize,
            int* fontChars, const int& glyphCount);
        /**
         * @brief Destroy the RFont object
         *
         */
        ~RFont();
        /**
         * @brief Get the inner font object
         *
         * @return Font&
         */
        Font& inner(void);
        /**
         * @brief Get the const Font object
         *
         * @return Font&
         */
        const Font& getFont(void) const;

        /**
         * @brief Get the Font object
         *
         * @return Font&
         */

        Font& getFont(void);

        /**
         * @brief Get the default font
         *
         * @return Font
         */
        static Font getFontDefault(void);
        /**
         * @brief Load font data for further use
         *
         * @param fileData
         * @param fontSize
         * @param fontChars
         * @param glyphCount
         * @param type
         * @return GlyphInfo*
         */
        GlyphInfo* loadFontData(const std::vector<unsigned char>& fileData,
            const int& fontSize, int* fontChars, const int& glyphCount,
            const int& type);
        /**
         * @brief Generate image font atlas using chars info
         *
         * @param chars
         * @param recs
         * @param glyphCount
         * @param fontSize
         * @param padding
         * @param packMethod
         * @return Image
         */
        Image genImageFontAtlas(GlyphInfo* chars, Rectangle** recs,
            const int& glyphCount, const int& fontSize, const int& padding,
            const int& packMethod);

    private:
        Font _font = { 0 };
        /**
         * @brief font characters glyphs info
         *
         */
        GlyphInfo* _fontData = nullptr;
        int _glyphCount = 0;
        bool _shouldDestroy = true;
    };
}
}
