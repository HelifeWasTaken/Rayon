#pragma once

#include "Rayon/Models/Model.hpp"
#include "Rayon/Texture/Texture.hpp"
#include "raylib.h"
#include <vector>

namespace rayon::models {

/**
 * @brief RFrameAnimModel
 * @details Handle model animation
 */
class RFrameAnimModel : public RModel {
private:
    /**
     * @brief the whole models we will use
     *
     */
    std::vector<RModel*> _models;
    int _frame = 0;
    float _time = 0.f;
    bool _loop = false;
    bool _paused = false;
    float _timePerFrame = 0.25f;
    bool _finished = false;

public:
    /**
     * @brief Construct a new RFrameAnimModel object
     *
     * @param animationDir
     */
    RFrameAnimModel(const std::string& animationDir);
    /**
     * @brief Construct a new RFrameAnimModel object with a given 2D texture
     *
     * @param animationDir
     * @param texture
     */
    RFrameAnimModel(const std::string& animationDir, const RTexture2D& texture);
    /**
     * @brief Destroy the RFrameAnimModel object
     *
     */
    ~RFrameAnimModel();

    /**
     * @brief Set the animation number of frames
     *
     * @param frame
     */
    void setFrame(int frame);
    /**
     * @brief Get the number of animation frame
     *
     * @return int
     */

    int getFrame() const;
    /**
     * @brief Check if the model animation is paused
     *
     * @return true
     * @return false
     */

    bool isPaused() const;
    /**
     * @brief Set the animation to the state pause
     *
     * @param paused
     */

    void setPaused(bool paused);

    /**
     * @brief Check if the animation is looping
     *
     * @return true
     * @return false
     */

    bool isLoop() const;

    /**
     * @brief Get the time between each frame
     *
     * @return float
     */

    float getTimePerFrame() const;

    /**
     * @brief Set the model animation loop
     *
     * @param loop
     */

    void setLoop(bool loop);

    /**
     * @brief Check if the animation is finished
     *
     * @return true
     * @return false
     */

    bool isFinished() const;

    /**
     * @brief Set the elapsed time between each frame
     *
     * @param timePerFrame
     */

    void setTimePerFrame(float timePerFrame);

    /**
     * @brief Get the frame count of the animation
     *
     * @return int
     */

    int getFrameCount() const;

    /**
     * @brief Update the frame animation
     *
     */

    void update();
};

}
