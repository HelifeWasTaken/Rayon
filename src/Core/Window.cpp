/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-mattis.dalleau
** File description:
** Window.cpp
*/

#include "Rayon/Core/Window.hpp"

namespace rayon {
namespace core {

    Window::Window(int width, int height, const std::string& title)
    {
        InitWindow(width, height, title.c_str());
    }

    Window::~Window() { close(); }

    void Window::takeScreenshot(const std::string& fileName)
    {
        TakeScreenshot(fileName.c_str());
    }

    void Window::setConfigFlags(unsigned int flags) { SetConfigFlags(flags); }

    void Window::setTargetFPS(int fps) { SetTargetFPS(fps); }

    int Window::getFPS() { return GetFPS(); }

    float Window::getFrameTime() { return GetFrameTime(); }

    double Window::getTime() { return GetTime(); }

    bool Window::shouldClose() { return WindowShouldClose(); }

    void Window::close()
    {
        if (!_closed) {
            CloseWindow();
            _closed = true;
        }
    }

    bool Window::isReady() { return IsWindowReady(); }

    bool Window::isFullscreen() { return IsWindowFullscreen(); }

    bool Window::isHidden() { return IsWindowHidden(); }

    bool Window::isMinimized() { return IsWindowMinimized(); }

    bool Window::isMaximized() { return IsWindowMaximized(); }

    bool Window::isFocused() { return IsWindowFocused(); }

    bool Window::isResized() { return IsWindowResized(); }

    bool Window::isState(unsigned int flag) { return IsWindowState(flag); }

    void Window::setState(unsigned int flags) { SetWindowState(flags); }

    void Window::clearState(unsigned int flags) { ClearWindowState(flags); }

    void Window::toggleFullscreen() { ToggleFullscreen(); }

    void Window::maximizeWindow() { MaximizeWindow(); }

    void Window::minimizeWindow() { MinimizeWindow(); }

    void Window::restoreWindow() { RestoreWindow(); }

    void Window::setIcon(Image image) { SetWindowIcon(image); }

    void Window::setTitle(const std::string& title)
    {
        SetWindowTitle(title.c_str());
    }

    void Window::setPosition(int x, int y) { SetWindowPosition(x, y); }

    void Window::setMonitor(int monitor) { SetWindowMonitor(monitor); }

    void Window::setMinSize(int width, int height)
    {
        SetWindowMinSize(width, height);
    }

    void Window::setSize(int width, int height)
    {
        SetWindowSize(width, height);
    }

    void* Window::getHandle() { return GetWindowHandle(); }

    int Window::getScreenWidth() { return GetScreenWidth(); }

    int Window::getScreenHeight() { return GetScreenHeight(); }

    int Window::getMonitorCount() { return GetMonitorCount(); }

    int Window::getCurrentMonitor() { return GetCurrentMonitor(); }

    Vector2 Window::getMonitorPosition(int monitor)
    {
        return GetMonitorPosition(monitor);
    }

    int Window::getMonitorWidth(int monitor)
    {
        return GetMonitorWidth(monitor);
    }

    int Window::getMonitorHeight(int monitor)
    {
        return GetMonitorHeight(monitor);
    }

    int Window::getMonitorPhysicalWidth(int monitor)
    {
        return GetMonitorPhysicalWidth(monitor);
    }

    int Window::getMonitorPhysicalHeight(int monitor)
    {
        return GetMonitorPhysicalHeight(monitor);
    }

    int Window::getMonitorRefreshRate(int monitor)
    {
        return GetMonitorRefreshRate(monitor);
    }

    Vector2 Window::getPosition() { return GetWindowPosition(); }

    Vector2 Window::getScaleDPI() { return GetWindowScaleDPI(); }

    std::string Window::getMonitorName(int monitor)
    {
        return GetMonitorName(monitor);
    }

    void Window::setClipboardText(const std::string& text)
    {
        SetClipboardText(text.c_str());
    }

    std::string Window::getClipboardText()
    {
        return std::string(GetClipboardText());
    }

    Vector2 Window::percent(float percentx, float percenty)
    {
        return { (getScreenWidth() / 100) * percentx,
            (getScreenHeight() / 100) * percenty };
    }
}
}
