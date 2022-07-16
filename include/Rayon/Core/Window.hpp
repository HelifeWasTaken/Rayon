#pragma once

#include "raylib.h"
#include <string>

namespace rayon {
namespace core {

    /**
     * @brief Window class
     *
     */
    class Window {
    public:
        /**
         * @brief Construct a new Window object
         *
         * @param width
         * @param height
         * @param title
         */
        Window(int width, int height, const std::string& title);
        /**
         * @brief Destroy the Window object
         *
         */
        ~Window();

        /**
         * @brief Take a screenshot of the current window
         *
         * @param fileName
         */
        static void takeScreenshot(const std::string& fileName);
        /**
         * @brief Set the Config Flags for the window
         *
         * @param flags
         */
        static void setConfigFlags(unsigned int flags);
        /**
         * @brief Set target FPS for the window (maximum)
         *
         * @param fps
         */
        void setTargetFPS(int fps);
        /**
         * @brief Get current FPS
         *
         * @return int
         */
        static int getFPS();
        /**
         * @brief Get time in seconds for last frame drawn (delta time)
         *
         * @return float
         */

        static float getFrameTime();
        /**
         * @brief Get elapsed time in seconds since InitWindow()
         *
         * @return double
         */
        static double getTime();
        /**
         * @brief Check if KEY_ESCAPE pressed or Close icon pressed
         *
         * @return true
         * @return false
         */
        bool shouldClose();
        /**
         * @brief Close window and unload OpenGL context
         *
         */
        void close();
        /**
         * @brief Check if window has been initialized successfully
         *
         * @return true
         * @return false
         */
        bool isReady();
        /**
         * @brief Check if window is currently fullscreen
         *
         * @return true
         * @return false
         */
        bool isFullscreen();
        /**
         * @brief Check if window is currently hidden (only PLATFORM_DESKTOP)
         *
         * @return true
         * @return false
         */
        bool isHidden();
        /**
         * @brief Check if window is currently minimized (only PLATFORM_DESKTOP)
         *
         * @return true
         * @return false
         */
        bool isMinimized();
        /**
         * @brief Check if window is currently maximized (only PLATFORM_DESKTOP)
         *
         * @return true
         * @return false
         */
        bool isMaximized();
        /**
         * @brief Check if window is currently focused (only PLATFORM_DESKTOP)
         *
         * @return true
         * @return false
         */
        bool isFocused();
        /**
         * @brief Check if window has been resized last frame
         *
         * @return true
         * @return false
         */
        bool isResized();
        /**
         * @brief Check if one specific window flag is enabled
         *
         * @param flag
         * @return true
         * @return false
         */
        bool isState(unsigned int flag);
        /**
         * @brief Set window configuration state using flags
         *
         * @param flags
         */
        void setState(unsigned int flags);
        /**
         * @brief Clear window configuration state flags
         *
         * @param flags
         */
        void clearState(unsigned int flags);
        /**
         * @brief Toggle window state: fullscreen/windowed (only
         * PLATFORM_DESKTOP)
         *
         */
        void toggleFullscreen();
        /**
         * @brief Set window state: maximized, if resizable (only
         * PLATFORM_DESKTOP)
         *
         */
        void maximizeWindow();
        /**
         * @brief Set window state: minimized, if resizable (only
         * PLATFORM_DESKTOP)
         *
         */
        void minimizeWindow();
        /**
         * @brief Set window state: not minimized/maximized (only
         * PLATFORM_DESKTOP)
         *
         */
        void restoreWindow();
        /**
         * @brief Set icon for window (only PLATFORM_DESKTOP)
         *
         * @param image
         */
        void setIcon(Image image);
        /**
         * @brief Set title for window (only PLATFORM_DESKTOP)
         *
         * @param title
         */
        void setTitle(const std::string& title);
        /**
         * @brief Set window position on screen (only PLATFORM_DESKTOP)
         *
         * @param x
         * @param y
         */
        void setPosition(int x, int y);
        /**
         * @brief Set monitor for the current window (fullscreen mode)
         *
         * @param monitor
         */
        void setMonitor(int monitor);
        /**
         * @brief Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
         *
         * @param width
         * @param height
         */
        void setMinSize(int width, int height);
        /**
         * @brief Set window dimensions
         *
         * @param width
         * @param height
         */
        void setSize(int width, int height);
        /**
         * @brief Get native window handle
         *
         * @return void*
         */
        void* getHandle();
        /**
         * @brief Get current screen width
         *
         * @return int
         */
        int getScreenWidth();
        /**
         * @brief Get current screen height
         *
         * @return int
         */
        int getScreenHeight();
        /**
         * @brief Get number of connected monitors
         *
         * @return int
         */
        int getMonitorCount();
        /**
         * @brief Get current connected monitor
         *
         * @return int
         */
        int getCurrentMonitor();
        /**
         * @brief Get specified monitor position
         *
         * @param monitor
         * @return Vector2
         */
        Vector2 getMonitorPosition(int monitor);
        /**
         * @brief Get specified monitor width (max available by monitor)
         *
         * @param monitor
         * @return int
         */
        int getMonitorWidth(int monitor);
        /**
         * @brief Get specified monitor height (max available by monitor)
         *
         * @param monitor
         * @return int
         */
        int getMonitorHeight(int monitor);
        /**
         * @brief Get specified monitor physical width in millimetres
         *
         * @param monitor
         * @return int
         */
        int getMonitorPhysicalWidth(int monitor);
        /**
         * @brief Get specified monitor physical height in millimetres
         *
         * @param monitor
         * @return int
         */
        int getMonitorPhysicalHeight(int monitor);
        /**
         * @brief Get specified monitor refresh rate
         *
         * @param monitor
         * @return int
         */
        int getMonitorRefreshRate(int monitor);
        /**
         * @brief Get window position XY on monitor
         *
         * @return Vector2
         */
        Vector2 getPosition();
        /**
         * @brief Get window scale DPI factor
         *
         * @return Vector2
         */
        Vector2 getScaleDPI();
        /**
         * @brief Get the human-readable, UTF-8 encoded name of the primary
         * monitor
         *
         * @param monitor
         * @return std::string
         */
        std::string getMonitorName(int monitor);
        /**
         * @brief Set clipboard text content
         *
         * @param text
         */
        void setClipboardText(const std::string& text);
        /**
         * @brief Get clipboard text content
         *
         * @return std::string
         */
        std::string getClipboardText();
        Vector2 percent(float percentx, float percenty);

    private:
        /**
         * @brief checker for window state
         *
         */
        bool _closed = false;
    };

}
}
