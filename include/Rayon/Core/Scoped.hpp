#pragma once

#include "Rayon/Core/Camera.hpp"
#include "raylib.h"
#include <functional>
#include <string>

/**
 * @brief namespace rayon
 *
 */
namespace rayon {

/**
 * @brief namespace core
 *
 */
namespace core {
    /**
     * @brief ScopedMode class
     * @details Class which grouping scoped functions
     * @tparam Begin
     */
    template <typename Begin> class ScopedMode {
    private:
        /**
         * @brief Begin function wrapped object
         *
         */
        const std::function<Begin> _begin;
        /**
         * @brief Stop function for the targeted object
         *
         */
        const std::function<void(void)> _stop;

    public:
        /**
         * @brief Construct a new Scoped Mode object
         *
         * @tparam Args
         * @param b
         * @param s
         * @param args
         */
        template <typename... Args>
        ScopedMode(const std::function<Begin>& b,
            const std::function<void(void)>& s, Args&&... args)
            : _begin(b)
            , _stop(s)
        {
            _begin(std::forward<Args>(args)...);
        }

        /**
         * @brief Destroy the Scoped Mode object using _stop function
         *
         */
        ~ScopedMode() { _stop(); }
    };

    /**
     * @brief ScopedCanvas class
     * @details Handle scoped canvas
     */
    class ScopedCanvas : public ScopedMode<void(void)> {
    public:
        /**
         * @brief Construct a new Scoped Canvas object with scoped begins
         * functions
         *
         */
        ScopedCanvas()
            : ScopedMode(BeginDrawing, EndDrawing)
        {
        }

        /**
         * @brief Clear the scoped canva background
         *
         * @param color
         */
        void clearBackground(Color color);
        /**
         * @brief Draw a text on the scoped canva using x and y coordinates
         *
         * @param text
         * @param x
         * @param y
         * @param fontSize
         * @param color
         */
        void drawText(
            const std::string& text, int x, int y, int fontSize, Color color);
        /**
         * @brief Draw a text on the scoped canva using a Vector2 for positions
         *
         * @param text
         * @param pos
         * @param fontSize
         * @param color
         */
        void drawText(const std::string& text, const Vector2& pos, int fontSize,
            Color color);
        /**
         * @brief Draw a grid on the scoped canva
         *
         * @param slices
         * @param spacing
         */
        void drawGrid(int slices, float spacing);
        /**
         * @brief Draw any object else on the scoped canva
         *
         * @tparam T
         * @param t
         */
        template <typename T> inline void draw(T& t) { t.draw(); }
        /**
         * @brief Draw a const object on the scoped canva
         *
         * @tparam T
         * @param t
         */
        template <typename T> inline void draw(const T& t) { t.draw(); }
    };

    /**
     * @brief ScopeMode2D class
     * @details Handle 2D mode camera
     */
    class ScopedMode2D : public ScopedMode<void(const Camera2D&)> {
    public:
        /**
         * @brief Construct a new Scoped Mode 2D object
         *
         * @param camera
         */
        ScopedMode2D(const Camera2D& camera)
            : ScopedMode(BeginMode2D, EndMode2D, camera)
        {
        }
        /**
         * @brief Construct a new Scoped Mode 2D camera with an inner camera
         * @param camera
         */
        ScopedMode2D(Camera2& camera)
            : ScopedMode(BeginMode2D, EndMode2D, camera.inner())
        {
        }
    };

    /**
     * @brief ScopedMode3D class
     * @details Handle 3D mode camera
     */

    class ScopedMode3D : public ScopedMode<void(const Camera3D&)> {
    public:
        /**
         * @brief Construct a new Scoped Mode 3D object
         *
         * @param camera
         */
        ScopedMode3D(const Camera3D& camera)
            : ScopedMode(BeginMode3D, EndMode3D, camera)
        {
        }
        /**
         * @brief Construct a new Scoped Mode 3D object with an inner camera
         *
         * @param camera
         */
        ScopedMode3D(Camera3& camera)
            : ScopedMode(BeginMode3D, EndMode3D, camera.inner())
        {
        }
    };

    /**
     * @brief ScopedTextureMode class
     * @details Handle texture
     */
    class ScopedTextureMode : public ScopedMode<void(const RenderTexture2D&)> {
    public:
        /**
         * @brief Construct a new Scoped Texture Mode object
         *
         * @param tx
         */
        ScopedTextureMode(const RenderTexture2D& tx)
            : ScopedMode(BeginTextureMode, EndTextureMode, tx)
        {
        }
    };

    /**
     * @brief ScopedShaderMode class
     * @details Handle scoped shader mode
     */
    class ScopedShaderMode : public ScopedMode<void(const Shader&)> {
    public:
        /**
         * @brief Construct a new Scoped Shader Mode object with a shader
         *
         * @param sh
         */
        ScopedShaderMode(const Shader& sh)
            : ScopedMode(BeginShaderMode, EndShaderMode, sh)
        {
        }
    };

    /**
     * @brief ScopedBlendMode class
     * @details Handle scoped blend object
     */
    class ScopedBlendMode : public ScopedMode<void(const int&)> {
    public:
        /**
         * @brief Construct a new Scoped Blend Mode object with a given mode
         *
         * @param mode
         */
        ScopedBlendMode(const int& mode)
            : ScopedMode(BeginBlendMode, EndBlendMode, mode)
        {
        }
    };

    /**
     * @brief ScopedScissorMode class
     *
     */
    class ScopedScissorMode : public ScopedMode<void(const int&, const int&,
                                  const int&, const int&)> {
    public:
        /**
         * @brief Construct a new Scoped Scissor Mode object
         *
         * @param x
         * @param y
         * @param w
         * @param h
         */
        ScopedScissorMode(
            const int& x, const int& y, const int& w, const int& h)
            : ScopedMode(BeginScissorMode, EndScissorMode, x, y, w, h)
        {
        }
    };

    /**
     * @brief ScopedVrStereoMode
     * @details Handle Vr Stereo mode
     */
    class ScopedVrStereoMode : public ScopedMode<void(const VrStereoConfig&)> {
    public:
        /**
         * @brief Construct a new Scoped Vr Stereo Mode object
         *
         * @param c
         */
        ScopedVrStereoMode(const VrStereoConfig& c)
            : ScopedMode(BeginVrStereoMode, EndVrStereoMode, c)
        {
        }
    };
}
}
