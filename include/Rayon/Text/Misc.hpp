#include "raylib.h"
#include <string>

namespace rayon {
namespace text {
    /**
     * @brief Misc class
     * @details You can find miscellaneous functions here
     */
    class Misc {
    public:
        /**
         * @brief Construct a new Misc object
         *
         */
        Misc();
        /**
         * @brief Destroy the Misc object
         *
         */
        ~Misc();
        /**
         * @brief Measure string width for default font
         *
         * @param text
         * @param fontSize
         * @return int
         */
        static int measure(std::string text, int fontSize);
        /**
         * @brief Measure string size for Font
         *
         * @param font
         * @param text
         * @param fontSize
         * @param spacing
         * @return Vector2
         */
        static Vector2 measureEx(
            Font font, std::string text, float fontSize, float spacing);
        /**
         * @brief Get glyph index position in font for a codepoint (unicode
         * character), fallback to '?' if not found
         *
         * @param font
         * @param codepoint
         * @return int
         */
        static int getGlyphIndex(Font font, int codepoint);
        /**
         * @brief Get glyph font info data for a codepoint (unicode character),
         * fallback to '?' if not found
         *
         * @param font
         * @param codepoint
         * @return GlyphInfo
         */
        static GlyphInfo getGlyphInfo(Font font, int codepoint);
        /**
         * @brief Get glyph rectangle in font atlas for a codepoint (unicode
         * character), fallback to '?' if not found
         *
         * @param font
         * @param codepoint
         * @return Rectangle
         */

        static Rectangle getGlyphAtlasRec(Font font, int codepoint);
    };
}
}