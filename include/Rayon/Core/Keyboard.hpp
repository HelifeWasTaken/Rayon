#pragma once

#include "raylib.h"

namespace rayon {
namespace core {

    /**
     * @brief Keyboard class
     * @details Input-related functions: keyboard
     */
    class Keyboard {
    private:
    public:
        /**
         * @brief Check if a key has been pressed once
         *
         * @param key
         * @return true
         * @return false
         */
        static bool isPressed(const int& key);
        /**
         * @brief Check if a key is being pressed
         *
         * @param key
         * @return true
         * @return false
         */
        static bool isDown(const int& key);
        /**
         * @brief Check if a key has been released once
         *
         * @param key
         * @return true
         * @return false
         */
        static bool isReleased(const int& key);
        /**
         * @brief Get key pressed (keycode), call it multiple times for keys
         * queued, returns 0 when the queue is empty
         *
         * @return int
         */

        static int getPressed();
        /**
         * @brief Get char pressed (unicode), call it multiple times for chars
         * queued, returns 0 when the queue is empty
         *
         * @return int
         */
        static int getCharPressed();
        /**
         * @brief Set a custom key to exit program (default is ESC)
         *
         * @param key
         */
        static void setExitKey(const int& key);
    };

}
}
