#include "Rayon/Core/Camera.hpp"
#include <cstring>

namespace rayon {
namespace core {

    Ray Camera3::getMouseRay(const Vector2& mousePosition)
    {
        return GetMouseRay(mousePosition, _camera);
    }

    Matrix Camera3::getMatrix() { return GetCameraMatrix(_camera); }

    Vector2 Camera3::getWorldToScreen(const Vector3& position)
    {
        return GetWorldToScreen(position, _camera);
    }

    Vector2 Camera3::getWorldToScreen(
        const Vector3& position, int width, int height)
    {
        return GetWorldToScreenEx(position, _camera, width, height);
    }

    Camera3& Camera3::setMode(int mode)
    {
        SetCameraMode(_camera, mode);
        return *this;
    }

    Camera3& Camera3::update()
    {
        UpdateCamera(&_camera);
        return *this;
    }

    Camera3& Camera3::setPosition(const Vector3& position)
    {
        _camera.position = position;
        return *this;
    }

    Camera3& Camera3::move(const Vector3& move)
    {
        setPosition({ _camera.position.x + move.x, _camera.position.y + move.y,
            _camera.position.z + move.z });
        return *this;
    }

    Camera3& Camera3::setTarget(const Vector3& target)
    {
        _camera.target = target;
        return *this;
    }

    Camera3& Camera3::setUp(const Vector3& up)
    {
        _camera.up = up;
        return *this;
    }

    Camera3& Camera3::setFOVY(float fovy)
    {
        _camera.fovy = fovy;
        return *this;
    }

    Camera3& Camera3::setProjection(int type)
    {
        _camera.projection = type;
        return *this;
    }

    Vector3 Camera3::getPosition() { return _camera.position; }

    Vector3 Camera3::getTarget() { return _camera.target; }

    Vector3 Camera3::getUp() { return _camera.up; }

    Camera& Camera3::inner() { return _camera; }

    float Camera3::getFOVY() { return _camera.fovy; }

    int Camera3::getProjection() { return _camera.projection; }

    Camera3& Camera3::zero()
    {
        memset(&_camera, 0, sizeof(Camera));
        return *this;
    }

    Camera2D& Camera2::inner() { return _camera; }

    Matrix Camera2::getCameraMatrix() { return GetCameraMatrix2D(_camera); }

    Vector2 Camera2::getWorldToScreen(const Vector2& position)
    {
        return GetWorldToScreen2D(position, _camera);
    }

    Vector2 Camera2::getScreenToWorld(const Vector2& position)
    {
        return GetScreenToWorld2D(position, _camera);
    }

    Camera2& Camera2::setOffset(const Vector2& offset)
    {
        _camera.offset = offset;
        return *this;
    }

    Camera2& Camera2::setTarget(const Vector2& target)
    {
        _camera.target = target;
        return *this;
    }

    Camera2& Camera2::setRotation(float rotation)
    {
        _camera.rotation = rotation;
        return *this;
    }

    Camera2& Camera2::setZoom(float zoom)
    {
        _camera.zoom = zoom;
        return *this;
    }

    Vector2 Camera2::getOffset()
    {
        return _camera.offset;
    }

    Vector2 Camera2::getTarget()
    {
        return _camera.target;
    }

    float Camera2::getRotation()
    {
        return _camera.rotation;
    }

    float Camera2::getZoom()
    {
        return _camera.zoom;
    }

    void setCameraPanControl(int keyPan) { SetCameraPanControl(keyPan); }

    void setCameraAltControl(int keyAlt) { SetCameraAltControl(keyAlt); }

    void setCameraSmoothZoomControl(int keySmoothZoom)
    {
        SetCameraSmoothZoomControl(keySmoothZoom);
    }

    void setCameraMoveControls(int keyFront, int keyBack, int keyRight,
        int keyLeft, int keyUp, int keyDown)
    {
        SetCameraMoveControls(
            keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
    }

}
}
