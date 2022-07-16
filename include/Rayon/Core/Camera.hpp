#pragma once

#include "Rayon/Core/Vector.hpp"

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
     * @brief Camera3 class
     * @details 3D Camera handling
     */
    class Camera3 {
    private:
        /**
         * @brief Camera object
         *
         */
        Camera _camera = { 0 };

    public:
        /**
         * @brief Construct a new Camera 3 object
         *
         */
        Camera3();

        /**
         * @brief get inner Camera object
         *
         * @return Camera&
         */
        Camera& inner();

        /**
         * @brief Get a ray trace from mouse position
         *
         * @param mousePosition
         * @return Ray
         */
        Ray getMouseRay(const Vector2& mousePosition);

        /**
         * @brief Get camera transform matrix (view matrix)
         *
         * @return Matrix
         */
        Matrix getMatrix();

        /**
         * @brief Get the screen space position for a 3d world space position
         *
         * @param position
         * @return Vector2
         */
        Vector2 getWorldToScreen(const Vector3& position);

        /**
         * @brief Get the screen space position for a 3d world space position
         * with data given
         * @param position
         * @param width
         * @param height
         * @return Vector2
         */
        Vector2 getWorldToScreen(
            const Vector3& position, int width, int height);

        /**
         * @brief Set camera mode (multiple camera modes available)
         *
         * @param mode
         * @return Camera3&
         */
        Camera3& setMode(int mode);

        /**
         * @brief Update camera position for selected mode
         *
         * @return Camera3&
         */
        Camera3& update();

        /**
         * @brief Set the camera position
         *
         * @param position
         * @return Camera3&
         */
        Camera3& setPosition(const Vector3& position);

        /**
         * @brief Set the camera target
         *
         * @param target
         * @return Camera3&
         */
        Camera3& setTarget(const Vector3& target);

        /**
         * @brief Set the camera angle to up
         *
         * @param up
         * @return Camera3&
         */
        Camera3& setUp(const Vector3& up);

        /**
         * @brief Set the camera Fov in y axis
         *
         * @param fovy
         * @return Camera3&
         */
        Camera3& setFOVY(float fovy);

        /**
         * @brief Set the camera Projection
         *
         * @param type
         * @return Camera3&
         */
        Camera3& setProjection(int type);

        /**
         * @brief Set the camera move
         * @param move
         * @return Camera3&
         */
        Camera3& move(const Vector3& move);

        /**
         * @brief Set the camera 2D moves
         *
         * @param move
         * @return Camera3&
         */
        Camera3& move2D(const Vector2& move);

        /**
         * @brief Get the camera position
         *
         * @return Vector3
         */
        Vector3 getPosition();

        /**
         * @brief Get the camera target
         *
         * @return Vector3
         */
        Vector3 getTarget();

        /**
         * @brief Get the camera angle up
         *
         * @return Vector3
         */
        Vector3 getUp();

        /**
         * @brief Get the camera fov on y axis
         *
         * @return float
         */
        float getFOVY();

        /**
         * @brief Get the camera projection
         *
         * @return int
         */
        int getProjection();

        /**
         * @brief Set all the camera values to zero
         *
         * @return Camera3&
         */
        Camera3& zero();
    };

    /**
     * @brief Camera2 class
     * @details 2D Camera handling
     */
    class Camera2 {
    private:
        /**
         * @brief 2D Camera object
         *
         */
        Camera2D _camera = { 0 };

    public:
        /**
         * @brief Construct a new Camera 2 object
         *
         */
        Camera2();

        /**
         * @brief Get the camera 2D inner object
         *
         * @return Camera2D&
         */
        Camera2D& inner();

        /**
         * @brief Get camera transform matrix (view matrix)
         *
         * @return Matrix
         */
        Matrix getCameraMatrix();

        /**
         * @brief Get the screen space position for a 2d camera world space
         * position
         *
         * @param position
         * @return Vector2
         */
        Vector2 getWorldToScreen(const Vector2& position);

        /**
         * @brief Get the world space position for a 2d camera screen space
         * position
         *
         * @param position
         * @return Vector2
         */
        Vector2 getScreenToWorld(const Vector2& position);

        /**
         * @brief Set the camera offset
         *
         * @param offset
         */
        void setOffset(const Vector2& offset);

        /**
         * @brief Set the camera target
         *
         * @param target
         */
        void setTarget(const Vector2& target);

        /**
         * @brief Set the camera rotation
         *
         * @param rotation
         */
        void setRotation(float rotation);

        /**
         * @brief Set the camera zoom
         *
         * @param zoom
         */
        void setZoom(float zoom);

        /**
         * @brief Get the camera offset
         *
         * @return Vector2
         */
        Vector2 getOffset();

        /**
         * @brief Get the camera target
         *
         * @return Vector2
         */
        Vector2 getTarget();

        /**
         * @brief Get the camera rotation
         *
         * @return float
         */
        float getRotation();

        /**
         * @brief Get the camera zoom
         *
         * @return float
         */
        float getZoom();
    };

    /**
     * @brief Set camera pan key to combine with mouse movement (free camera)
     *
     * @param keyPan
     */
    void setCameraPanControl(int keyPan);

    /**
     * @brief Set camera alt key to combine with mouse movement (free camera)
     *
     * @param keyAlt
     */
    void setCameraAltControl(int keyAlt);

    /**
     * @brief Set camera smooth zoom key to combine with mouse (free camera)
     *
     * @param keySmoothZoom
     */
    void setCameraSmoothZoomControl(int keySmoothZoom);

    /**
     * @brief Set camera move controls (1st person and 3rd person cameras)
     *
     * @param keyFront
     * @param keyBack
     * @param keyRight
     * @param keyLeft
     * @param keyUp
     * @param keyDown
     */
    void setCameraMoveControls(int keyFront, int keyBack, int keyRight,
        int keyLeft, int keyUp, int keyDown);
}
}
