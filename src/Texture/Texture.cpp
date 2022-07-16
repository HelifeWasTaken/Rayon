#include "Rayon/Texture/Texture.hpp"

namespace rayon {

RImage::RImage(const std::string& fileName, bool loadAnim)
{
    if (loadAnim) {
        _image = LoadImageAnim(fileName.c_str(), &_frames);
    } else {
        _image = LoadImage(fileName.c_str());
    }
}

RImage::RImage(const std::string& fileName, int width, int height, int format,
    int headerSize)
{
    _image = LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

RImage::RImage(
    const std::string& fileName, const std::vector<unsigned char>& fileData)
{
    _image = LoadImageFromMemory(
        fileName.c_str(), fileData.data(), static_cast<int>(fileData.size()));
}

RImage::RImage(const Texture2D& tx) { _image = LoadImageFromTexture(tx); }

RImage::RImage(int width, int height, const Color& color)
{
    _image = GenImageColor(width, height, color);
}

template <typename F, typename... Args>
RImage::RImage(const F& f, Args&&... args)
{
    _image = f(std::forward<Args>(args)...);
}

Image& RImage::inner() { return _image; }

void RImage::clearBackground(const Color& color)
{
    ImageClearBackground(&_image, color);
}

void RImage::drawPixel(const Vector2& pos, const Color& color)
{
    ImageDrawPixelV(&_image, pos, color);
}

void RImage::drawCircle(const Vector2& center, int radius, const Color& color)
{
    ImageDrawCircleV(&_image, center, radius, color);
}

void RImage::drawRectangle(
    const Vector2& pos, const Vector2& size, const Color& color)
{
    ImageDrawRectangleV(&_image, pos, size, color);
}

Image& RImage::image() { return _image; }

RImage::~RImage() { UnloadImage(_image); }

RTexture2D::RTexture2D(const std::string& fileName)
{
    _texture = LoadTexture(fileName.c_str());
    _rectangle = { 0, 0, (float)_texture.width, (float)_texture.height };
}

RTexture2D::RTexture2D(const Image& image)
{
    _texture = LoadTextureFromImage(image);
    _rectangle = { 0, 0, (float)_texture.width, (float)_texture.height };
}

RTexture2D::RTexture2D(RImage& image)
{
    _texture = LoadTextureFromImage(image.image());
    _rectangle = { 0, 0, (float)_texture.width, (float)_texture.height };
}

Texture2D& RTexture2D::inner() { return _texture; }

const Texture2D& RTexture2D::inner() const { return _texture; }

void RTexture2D::setColor(const Color& color) { _tint = color; }

void RTexture2D::setPosition(const Vector2& pos) { _pos = pos; }

void RTexture2D::setRectangle(const Rectangle& rect) { _rectangle = rect; }

void RTexture2D::draw() { DrawTextureRec(_texture, _rectangle, _pos, _tint); }
}
