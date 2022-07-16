#pragma once

#include "raylib.h"
#include <memory>
#include <string>
#include <vector>

namespace rayon {
/**
 * @brief RImage
 * @details Image related functions
 */
class RImage {
private:
    int _frames = 1;
    Image _image = { 0 };

public:
    /**
     * @brief Load image from file into CPU memory (RAM)
     *
     * @param fileName
     * @param loadAnim
     */
    RImage(const std::string& fileName, bool loadAnim = false);
    /**
     * @brief Load image from RAW file data
     *
     * @param fileName
     * @param width
     * @param height
     * @param format
     * @param headerSize
     */

    RImage(const std::string& fileName, int width, int height, int format,
        int headerSize);
    /**
     * @brief Load image from RAW given file data
     *
     * @param fileName
     * @param fileData
     */

    RImage(const std::string& fileName,
        const std::vector<unsigned char>& fileData);
    /**
     * @brief Construct a new RImage object with a texture
     *
     * @param texture
     */
    RImage(const Texture2D& texture);
    /**
     * @brief Construct a new RImage object with a color
     *
     * @param width
     * @param height
     * @param color
     */
    RImage(int width, int height, const Color& color);
    /**
     * @brief Construct a new RImage object with 2
     *  colors
     * @param width
     * @param height
     * @param top
     * @param bottom
     */
    RImage(int width, int height, const Color& top, const Color& bottom);
    /**
     * @brief Construct a new RImage object with some given functions
     *
     * @tparam F
     * @tparam Args
     * @param f
     * @param args
     */

    template <typename F, typename... Args> RImage(const F& f, Args&&... args);
    /**
     * @brief Clear the image background
     *
     * @param color
     */
    RImage& clearBackground(const Color& color);
    /**
     * @brief Draw pixel on image
     *
     * @param pos
     * @param color
     */
    RImage& drawPixel(const Vector2& pos, const Color& color);
    /**
     * @brief Draw circle on image
     *
     * @param center
     * @param radius
     * @param color
     */
    RImage& drawCircle(const Vector2& center, int radius, const Color& color);
    /**
     * @brief Draw rectangle on image
     *
     * @param pos
     * @param size
     * @param color
     */
    RImage& drawRectangle(
        const Vector2& pos, const Vector2& size, const Color& color);

    /**
     * @brief Get the image object
     *
     * @return Image&
     */
    Image& inner();

    /**
     * @brief Get the image object
     *
     * @return const Image&
     */
    const Image& inner() const;

    /**
     * @brief Destroy the RImage object
     *
     */
    ~RImage();
};

/**
 * @brief RTexture2D class
 * @details Texture related functions
 */
class RTexture2D {
private:
    Texture2D _texture = { 0 };
    Rectangle _rectangle = { 0 };
    Vector2 _pos = { 0, 0 };
    Color _tint = { 255, 255, 255, 255 };

public:
    /**
     * @brief Construct a new RTexture2D object with a given file
     *
     * @param fileName
     */
    RTexture2D(const std::string& fileName);
    /**
     * @brief Construct a new RTexture2D object from a const image
     *
     * @param image
     */
    RTexture2D(const Image& image);
    /**
     * @brief Construct a new RTexture2D object from an image
     *
     * @param image
     */
    RTexture2D(const RImage& image);

    /**
     * @brief Unload a texture
     *
     */
    ~RTexture2D();

    /**
     * @brief Get the inner texture
     *
     * @return Texture2D&
     */
    Texture2D& inner();
    /**
     * @brief Get a const inner texture
     *
     * @return const Texture2D&
     */

    const Texture2D& inner() const;
    /**
     * @brief Set the texture color
     *
     * @param color
     */

    RTexture2D& setColor(const Color& color);
    /**
     * @brief Set the texture position
     *
     * @param pos
     */
    RTexture2D& setPosition(const Vector2& pos);
    /**
     * @brief Set the texture rectangle
     *
     * @param rect
     */
    RTexture2D& setRectangle(const Rectangle& rect);
    /**
     * @brief Draw texture
     *
     */
    RTexture2D& draw();

    /**
     * @brief Load a texture from a filename
     * @param fileName
     */
    RTexture2D& load(const std::string& fileName);

    /**
     * @brief Load a texture from an image
     * @param image
     */
    RTexture2D& load(const Image& image);

    /**
     * @brief Load a texture from an RImage
     * @param image
     */
    RTexture2D& load(const RImage& image);
};

} // namespace rayon
