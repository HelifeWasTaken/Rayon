#pragma once

#include "Rayon/Core/Exception.hpp"
#include "Rayon/Texture/Texture.hpp"
#include "raylib.h"
#include <optional>
#include <string>
#include <vector>

namespace rayon {
namespace models {

    /**
     * @brief RModelAnimation class
     * @details Handle model animation
     */
    class RModelAnimation {
    protected:
        ModelAnimation* _animation = nullptr;
        unsigned int _animationCount = 0;
        Model& _model;

    public:
        /**
         * @brief Construct a new RModelAnimation object
         *
         * @param model
         * @param filename
         */
        RModelAnimation(Model& model, const std::string& filename);
        /**
         * @brief Destroy the RModelAnimation object
         *
         */
        ~RModelAnimation();
        /**
         * @brief Get the Animation Count object
         *
         * @return const unsigned&
         */
        const unsigned int& getAnimationCount() const;
        /**
         * @brief Get the Animation object with a given index
         *
         * @param index
         * @return const ModelAnimation&
         */
        const ModelAnimation& getAnimation(unsigned int index) const;
        /**
         * @brief Update the model animation
         *
         * @param anim
         * @param frame
         */
        void updateAnimation(unsigned int anim, int frame);
    };

    /**
     * @brief RModel class
     *
     */
    class RModel {
    protected:
        /**
         * @brief Construct a new RModel object
         *
         */
        RModel() = default;
        Model _model = { 0 };
        bool _keepMesh = false;

        Vector3 _position = { 0.0f, 0.0f, 0.0f };
        Vector3 _scale = { 1.0f, 1.0f, 1.0f };
        Vector3 _rotation = { 0.0f, 0.0f, 0.0f };
        float _rotationAngle = 0.0f;
        Color _tint = { 255, 255, 255, 255 };

    public:
        /**
         * @brief Construct a new RModel object with a given path
         *
         * @param path
         * @param keepMesh
         */
        RModel(const std::string& path, bool keepMesh = false);
        /**
         * @brief Construct a new RModel object with a given mesh object
         *
         * @param mesh
         * @param keepMesh
         */
        RModel(const Mesh& mesh, bool keepMesh = false);

        /**
         * @brief Set the model KeepMesh object state
         *
         * @param keepMesh
         */
        void setKeepMesh(bool keepMesh);

        /**
         * @brief Set the model Position object
         *
         * @param position
         */
        void setPosition(const Vector3& position);
        /**
         * @brief Set the model scale
         *
         * @param scale
         */
        void setScale(const Vector3& scale);
        /**
         * @brief Set the model Rotation
         *
         * @param rotation
         */
        void setRotation(const Vector3& rotation);
        /**
         * @brief Set the model tint
         *
         * @param tint
         */
        void setTint(const Color& tint);
        /**
         * @brief Set the model Rotation Angle
         *
         * @param rotationAngle
         */
        void setRotationAngle(float rotationAngle);
        /**
         * @brief Set the model Material Texture with a given map type
         *
         * @param materialIndex
         * @param mapType
         * @param texture
         */
        void setMaterialTexture(unsigned int materialIndex,
            unsigned int mapType, const RTexture2D& texture);
        /**
         * @brief Set the model Material Texture
         *
         * @param materialIndex
         * @param texture
         */
        void setMaterialTexture(
            unsigned int materialIndex, const RTexture2D& texture);
        /**
         * @brief Get the model Bounding Box
         *
         * @return BoundingBox
         */
        BoundingBox getBoundingBox() const;
        /**
         * @brief Get the model Position
         *
         * @return const Vector3&
         */
        const Vector3& getPosition() const;
        /**
         * @brief Get the model Scale 3D vector
         *
         * @return const Vector3&
         */
        const Vector3& getScale() const;
        /**
         * @brief Get the model Rotation 3D vector
         *
         * @return const Vector3&
         */
        const Vector3& getRotation() const;
        /**
         * @brief Get the model Rotation Angle
         *
         * @return const float&
         */
        const float& getRotationAngle() const;
        /**
         * @brief Get the model Tint
         *
         * @return const Color&
         */
        const Color& getTint() const;
        /**
         * @brief Get a const Model object
         *
         * @return const Model&
         */
        const Model& getModel() const;
        /**
         * @brief Get a const inner Model object
         *
         * @return const Model&
         */
        const Model& inner() const;

        /**
         * @brief Get the Model object
         *
         * @return Model&
         */
        Model& getModel();
        /**
         * @brief Get the inner Model object
         *
         * @return Model&
         */
        Model& inner();
        /**
         * @brief Draw a model
         *
         */
        void draw() const;
        /**
         * @brief Draw the bonding box of a model
         *
         * @param tint
         */
        void drawBoundings(const Color& tint = { 255, 255, 255, 255 }) const;
        /**
         * @brief Destroy the RModel object
         *
         */
        ~RModel();
    };

    /**
     * @brief RModelLoadingError
     *
     */
    class RModelLoadingError : public core::RException {
    public:
        RModelLoadingError(const std::string& message)
            : RException(message)
        {
        }
        ~RModelLoadingError() = default;
    };

    /**
     * @brief RAnimableModel
     * @details Check the properties of a model
     */

    class RAnimableModel : public RModel, public RModelAnimation {
        RAnimableModel(const std::string& modelFilepath,
            const std::string& modelAnimation, bool keepMesh = false)
            : RModel(modelFilepath)
            , RModelAnimation(RModel::_model, modelAnimation)
        {
        }
    };

    /**
     * @brief RLine class
     * @details Create Draw a line with a specific position, size and color
     */

    class RLine {
    public:
        Vector3 start = { 0.0f, 0.0f, 0.0f };
        Vector3 end = { 1.0f, 1.0f, 1.0f };
        Color color = { 255, 255, 255, 255 };
        RLine(const Vector3& start, const Vector3& end, const Color& color);
        RLine() = default;
        void draw();
    };

    /**
     * @brief RPoint class
     * @details Create Draw a color point at a specific position
     */
    class RPoint {
    public:
        Vector3 point = { 0.0f, 0.0f, 0.0f };
        Color color = { 255, 255, 255, 255 };
        RPoint(const Vector3& point, const Color& color);
        RPoint() = default;
        void draw();
    };

    /**
     * @brief RCircle class
     * @details Handle all the properties that a circle can have
     */
    class RCircle {
    public:
        Vector3 center = { 1.0f, 1.0f, 1.0f };
        float radius = 1.0f;
        Vector3 rotation = { 0.0f, 0.0f, 0.0f };
        float rotationAngle = 0.0f;
        Color color = { 255, 255, 255, 255 };
        RCircle(const Vector3& center, float radius, const Vector3& rotation,
            float rotationAngle, const Color& color);
        RCircle() = default;
        /**
         * @brief Draw a circle with the constructor's properties
         *
         */
        void draw();
    };

    /**
     * @brief RTriangle class
     * @details Create and Draw a triangle with a specific size and color
     */
    class RTriangle {
    public:
        Vector3 a = { 1.0f, 1.0f, 0.0f };
        Vector3 b = { -1.0f, 1.0f, 0.0f };
        Vector3 c = { 0.0f, -1.0f, 0.0f };
        Color color = { 255, 255, 255, 255 };
        RTriangle(const Vector3& a, const Vector3& b, const Vector3& c,
            const Color& color);
        RTriangle() = default;
        void draw();
    };

    /**
     * @brief RTriangleStrip class
     * @details Create and Draw a triangle strip with a specific position and
     * color
     */
    class RTriangleStrip {
    public:
        std::vector<Vector3> points = {};
        Color color = { 255, 255, 255, 255 };
        RTriangleStrip(const std::vector<Vector3>& points, const Color& color);
        RTriangleStrip() = default;
        void draw();
    };

    /**
     * @brief RCube class
     * @details Create and Draw a cube
     */
    class RCube {
    public:
        Vector3 position = { 0.0f, 0.0f, 0.0f };
        Vector3 size = { 1.0f, 1.0f, 1.0f };
        Color color = { 255, 255, 255, 255 };
        std::optional<RTexture2D> texture = std::nullopt;
        std::unique_ptr<RModel> model = nullptr;

        RCube(const Vector3& position, float width, float height, float length,
            const Color& color);
        RCube(const Vector3& position, const Vector3& size, const Color& color);
        RCube(const Vector3& position, const Vector3& size,
            const RTexture2D& texture);
        RCube() = default;
        void draw();
    };

    /**
     * @brief RSphere class
     * @details Create and Draw a Sphere
     */
    class RSphere {
    public:
        Vector3 position = { 0.0f, 0.0f, 0.0f };
        float radius = 1.0f;
        Color color = { 255, 255, 255, 255 };
        RSphere(const Vector3& position, float radius, const Color& color);
        RSphere() = default;
        void draw();
    };

    /**
     * @brief RPlane class
     * @details Create and Draw a plane with a specific size, color and position
     */
    class RPlane {
    public:
        Vector3 position = { 0.0f, 0.0f, 0.0f };
        Vector2 size = { 1.0f, 1.0f };
        Color color = { 255, 255, 255, 255 };
        RPlane(
            const Vector3& position, const Vector2& size, const Color& color);
        RPlane() = default;
        void draw();
    };

    /**
     * @brief RRay class
     *
     */
    class RRay {
    public:
        Ray ray = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
        Color color = { 255, 255, 255, 255 };
        /**
         * @brief Construct a new RRay object with a color
         *
         * @param ray
         * @param color
         */
        RRay(const Ray& ray, const Color& color);
        /**
         * @brief Default constructor for a new RRay object
         *
         */
        RRay() = default;
        /**
         * @brief Draw a ray
         *
         */
        void draw();
        /**
         * @brief Handle collisions between ray and spheres
         *
         * @param sphere
         * @return RayCollision
         */
        RayCollision collides(const RSphere& sphere);
        /**
         * @brief Handle collisions between ray and boxes
         *
         * @param box
         * @return RayCollision
         */
        RayCollision collides(const BoundingBox& box);
        /**
         * @brief Handle collisions between ray and models
         *
         * @param model
         * @return RayCollision
         */
        RayCollision collides(const RModel& model);
        /**
         * @brief Handle collisions between ray and triangle
         *
         * @param triangle
         * @return RayCollision
         */
        RayCollision collides(const RTriangle& triangle);

        /**
         * @brief Handle collisions between ray and cubes
         *
         * @param cube
         * @return RayCollision
         */
        RayCollision collides(const RCube& cube);
    };

    /**
     * @brief RGrid class
     * @details Create and Draw a Grid with a specific spacing between slices
     * and a specific color
     */
    class RGrid {
    public:
        int slices = 10;
        float spacing = 1.0f;
        Color color = { 255, 255, 255, 255 };
        RGrid(int slices, float spacing, const Color& color);
        RGrid() = default;
        void draw();
    };

}
}
