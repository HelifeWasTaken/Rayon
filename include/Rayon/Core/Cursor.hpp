#pragma once

#include "raylib.h"

namespace rayon {
namespace core {

    /**
     * @brief Cursor class
     * @details Handle cursor's action
     */
    class Cursor {
    private:
    public:
        /**
         * @brief Show the cursor on the screen
         *
         */
        static void show();
        /**
         * @brief Hide the cursor on the screen
         *
         */
        static void hide();
        /**
         * @brief Check if the cursor is hidden
         *
         * @return true
         * @return false
         */
        static bool isHidden();
        /**
         * @brief Check if the cursor is enabled
         *
         */
        static void enable();
        /**
         * @brief Check if the cursor is disabled
         *
         */
        static void disable();
        /**
         * @brief Check if the cursor is still on the screen (Window size)
         *
         * @return true
         * @return false
         */
        static bool isOnScreen();
    };
}
}