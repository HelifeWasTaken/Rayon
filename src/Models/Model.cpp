#include "Rayon/Models/Model.hpp"
#include <iostream>

namespace rayon {
namespace models {

    RModelAnimation::RModelAnimation(Model& model, const std::string& filename)
        : _animation(LoadModelAnimations(filename.c_str(), &_animationCount))
        , _model(model)
    {
        if (_animation == nullptr) {
            throw RModelLoadingError(
                std::string("Failed to load model animation: ") + filename
                + "(load file)");
        }

        for (unsigned int i = 0; i < _animationCount; i++) {
            if (IsModelAnimationValid(_model, _animation[i]) == false) {
                throw RModelLoadingError(
                    std::string("Failed to load model animation: ") + filename
                    + "(Animation " + std::to_string(i) + ") is invalid");
            }
        }
    }

    RModelAnimation::~RModelAnimation()
    {
        UnloadModelAnimations(_animation, _animationCount);
    }

    const unsigned int& RModelAnimation::getAnimationCount() const
    {
        return _animationCount;
    }

    const ModelAnimation& RModelAnimation::getAnimation(
        unsigned int index) const
    {
        return _animation[index];
    }

    void RModelAnimation::updateAnimation(unsigned int anim, int frame)
    {
        UpdateModelAnimation(_model, _animation[anim], frame);
    }

    RModel::RModel(const std::string& path, bool keepMesh)
        : _model(LoadModel(path.c_str()))
        , _keepMesh(keepMesh)
    {
    }

    RModel::RModel(const Mesh& mesh, bool keepMesh)
        : _model(LoadModelFromMesh(mesh))
        , _keepMesh(keepMesh)
    {
    }

    RModel::~RModel()
    {
        _keepMesh ? UnloadModelKeepMeshes(_model) : UnloadModel(_model);
    }

    BoundingBox RModel::getBoundingBox() const
    {
        return GetModelBoundingBox(_model);
    }

    Model& RModel::getModel() { return _model; }

    const Model& RModel::getModel() const { return _model; }

    Model& RModel::inner() { return _model; }

    const Model& RModel::inner() const { return _model; }

    void RModel::setMaterialTexture(unsigned int materialIndex,
        unsigned int mapType, const RTexture2D& texture)
    {
        SetMaterialTexture(
            &_model.materials[materialIndex], mapType, texture.inner());
    }

    void RModel::setMaterialTexture(
        unsigned int materialIndex, const RTexture2D& texture)
    {
        setMaterialTexture(materialIndex, MATERIAL_MAP_DIFFUSE, texture);
    }

    void RModel::setKeepMesh(bool keepMesh) { _keepMesh = keepMesh; }

    void RModel::setPosition(const Vector3& position) { _position = position; }

    void RModel::setScale(const Vector3& scale) { _scale = scale; }

    void RModel::setRotation(const Vector3& rotation) { _rotation = rotation; }

    void RModel::setTint(const Color& tint) { _tint = tint; }

    void RModel::setRotationAngle(float rotationAngle)
    {
        _rotationAngle = rotationAngle;
    }

    const Vector3& RModel::getPosition() const { return _position; }

    const Vector3& RModel::getScale() const { return _scale; }

    const Vector3& RModel::getRotation() const { return _rotation; }

    const float& RModel::getRotationAngle() const { return _rotationAngle; }

    const Color& RModel::getTint() const { return _tint; }

    void RModel::draw() const
    {
        DrawModelEx(
            _model, _position, _rotation, _rotationAngle, _scale, _tint);
    }

    void RModel::drawBoundings(const Color& tint) const
    {
        DrawBoundingBox(getBoundingBox(), tint);
    }

    RLine::RLine(const Vector3& start, const Vector3& end, const Color& color)
        : start(start)
        , end(end)
        , color(color)
    {
    }

    void RLine::draw() { DrawLine3D(start, end, color); }

    RPoint::RPoint(const Vector3& point, const Color& color)
        : point(point)
        , color(color)
    {
    }

    void RPoint::draw() { DrawPoint3D(point, color); }

    RCircle::RCircle(const Vector3& center, float radius,
        const Vector3& rotation, float rotationAngle, const Color& color)
        : center(center)
        , radius(radius)
        , rotation(rotation)
        , rotationAngle(rotationAngle)
        , color(color)
    {
    }

    void RCircle::draw()
    {
        DrawCircle3D(center, radius, rotation, rotationAngle, color);
    }

    RTriangle::RTriangle(const Vector3& a, const Vector3& b, const Vector3& c,
        const Color& color)
        : a(a)
        , b(b)
        , c(c)
        , color(color)
    {
    }

    void RTriangle::draw() { DrawTriangle3D(a, b, c, color); }

    RTriangleStrip::RTriangleStrip(
        const std::vector<Vector3>& points, const Color& color)
        : points(points)
        , color(color)
    {
    }

    void RTriangleStrip::draw()
    {
        DrawTriangleStrip3D(
            points.data(), static_cast<int>(points.size()), color);
    }

    RCube::RCube(
        const Vector3& position, const Vector3& size, const Color& color)
        : position(position)
        , size(size)
        , color(color)
    {
    }

    RCube::RCube(
        const Vector3& position, const Vector3& size, const RTexture2D& texture)
        : position(position)
        , size(size)
        , texture(texture)
    {
        model.reset(new RModel(GenMeshCube(size.x, size.y, size.z)));
        model->setMaterialTexture(0, texture);
    }

    RCube::RCube(const Vector3& position, float width, float height,
        float length, const Color& color)
        : position(position)
        , size({ width, height, length })
        , color(color)
    {
    }

    void RCube::draw()
    {
        if (model == nullptr) {
            DrawCube(position, size.x, size.y, size.z, color);
            DrawCubeWires(position, size.x, size.y, size.z, BLACK);
        } else {
            model->setPosition(position);
            model->draw();
            DrawCubeWires(position, size.x, size.y, size.z, BLACK);
        }
    }

    RSphere::RSphere(const Vector3& position, float radius, const Color& color)
        : position(position)
        , radius(radius)
        , color(color)
    {
    }

    void RSphere::draw() { DrawSphere(position, radius, color); }

    RPlane::RPlane(
        const Vector3& position, const Vector2& size, const Color& color)
        : position(position)
        , size(size)
        , color(color)
    {
    }

    void RPlane::draw() { DrawPlane(position, size, color); }

    RRay::RRay(const Ray& ray, const Color& color)
        : ray(ray)
        , color(color)
    {
    }

    void RRay::draw() { DrawRay(ray, color); }

}
}
