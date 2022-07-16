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
        RText();
        /**
         * @brief Destroy the RText object
         *
         */
        ~RText();
        /**
         * @brief Set the text color
         *
         * @param tint
         */

        void setColor(const Color& tint);

        /**
         * @brief Get the text position
         *
         * @return Vector2
         */
        Vector2 getPos(void);

        /**
         * @brief Set the _spacing variable
         *
         * @param spacing
         */
        void setSpacing(const float& spacing);
        /**
         * @brief Set the text font size
         *
         * @param fontSize
         */
        void setFontSize(const float& fontSize);
        /**
         * @brief Set the text rotation
         *
         * @param rotation
         */
        void setRotation(const float& rotation);
        /**
         * @brief Set the text font
         *
         * @param font
         */
        void setFont(const Font& font);
        /**
         * @brief Set the text origin
         *
         * @param origin
         */
        void setOrigin(const Vector2& origin);
        /**
         * @brief Set the text pos
         *
         * @param pos
         */
        void setPos(const Vector2& pos);
        /**
         * @brief Set the text string
         *
         * @param text
         */
        void setString(const std::string& text);
        /**
         * @brief Draw current FPS
         *
         */
        void drawFPS();
        /**
         * @brief Draw a text
         *
         */
        void drawText();
    };
}
}