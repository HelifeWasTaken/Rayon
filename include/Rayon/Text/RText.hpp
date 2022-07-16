#pragma once

#include "raylib.h"
#include <string>

namespace rayon {
namespace text {
    /**
     * @brief RText
     * @details Text related functions
     *
     */
    class RText {
    private:
        std::string _text;
        Vector2 _pos = { 0, 0 };
        Vector2 _origin = { 0, 0 };
        Font _font = GetFontDefault();
        float _rotation = 0;
        float _fontSize = 11;
        /**
         * @brief spacing between letters
         *
         */
        float _spacing = 1;
        Color _tint = { 255, 255, 255, 255 };

    public:
        /**
         * @brief Construct a new RText object
         *
         */
        RText() = default;
        /**
         * @brief Destroy the RText object
         *
         */
        ~RText() = default;
        /**
         * @brief Set the text color
         *
         * @param tint
         */

        RText& setColor(const Color& tint);

        /**
         * @brief Get the text position
         *
         * @return Vector2
         */
        const Vector2& getPosition() const;

        /**
         * @brief Set the _spacing variable
         *
         * @param spacing
         */
        RText& setSpacing(const float& spacing);
        /**
         * @brief Set the text font size
         *
         * @param fontSize
         */
        RText& setFontSize(const float& fontSize);
        /**
         * @brief Set the text rotation
         *
         * @param rotation
         */
        RText& setRotation(const float& rotation);
        /**
         * @brief Set the text font
         *
         * @param font
         */
        RText& setFont(const Font& font);
        /**
         * @brief Set the text origin
         *
         * @param origin
         */
        RText& setOrigin(const Vector2& origin);
        /**
         * @brief Set the text pos
         *
         * @param pos
         */
        RText& setPosition(const Vector2& pos);
        /**
         * @brief Set the text string
         *
         * @param text
         */
        RText& setText(const std::string& text);
        /**
         * @brief Draw current FPS (Ignores current text)
         *
         */
        RText& drawFPS();

        /**
         * @brief Draw the current text
         *
         */
        RText& draw();
    };
}
}