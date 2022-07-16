#pragma once

#include "raylib.h"
#include <string>

namespace rayon {
namespace core {

    /**
     * @brief Mouse class
     * @details Input-related functions: mouse
     */
    class Mouse {
    public:
        /**
         * @brief Construct a new Mouse object
         *
         */
        Mouse();
        /**
         * @brief Destroy the Mouse object
         *
         */
        ~Mouse();

        /**
         * @brief Check if a mouse button has been pressed once
         *
         * @param button
         * @return true
         * @return false
         */
        static bool isButtonPressed(int button);
        /**
         * @brief Check if a mouse button is being pressed
         *
         * @param button
         * @return true
         * @return false
         */
        static bool isButtonDown(int button);
        /**
         * @brief Check if a mouse button has been released once
         *
         * @param button
         * @return true
         * @return false
         */
        static bool isButtonReleased(int button);
        /**
         * @brief Check if a mouse button is NOT being pressed
         *
         * @param button
         * @return true
         * @return false
         */
        static bool isButtonUp(int button);
        /**
         * @brief Get mouse position X
         *
         * @return int
         */
        static int getX();
        /**
         * @brief Get mouse position Y
         *
         * @return int
         */
        static int getY();
        /**
         * @brief Get mouse position XY
         *
         * @return Vector2
         */
        static Vector2 getPosition();
        /**
         * @brief Get mouse delta between frames
         *
         * @return Vector2
         */
        static Vector2 getDelta();
        /**
         * @brief Set mouse position XY
         *
         * @param x
         * @param y
         */
        static void setPosition(int x, int y);
        /**
         * @brief Set mouse offset
         *
         * @param offsetX
         * @param offsetY
         */
        static void setOffset(int offsetX, int offsetY);
        /**
         * @brief Set mouse scaling
         *
         * @param scaleX
         * @param scaleY
         */
        static void setScale(float scaleX, float scaleY);
        /**
         * @brief Get mouse wheel movement Y
         *
         * @return float
         */
        static float getWheelMove(void);
    };
}
}
