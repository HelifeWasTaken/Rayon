#include "Rayon/Models/FrameAnimModel.hpp"
#include "Rayon/Models/Model.hpp"
#include "Rayon/Texture/Texture.hpp"
#include "raylib.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

namespace rayon::models {

RFrameAnimModel::RFrameAnimModel(const std::string& animationDir)
{
    int frameCount = 0;
    char** files = LoadDirectoryFiles(animationDir.c_str(), &frameCount);
    if (files == nullptr) {
        throw RModelLoadingError(
            "Failed to load model animation: " + animationDir);
    }

    std::vector<std::string> fileNames(frameCount);
    for (int i = 0; i < frameCount; i++) {
        fileNames[i] = files[i];
    }

    std::sort(fileNames.begin(), fileNames.end());

    for (int i = 0; i < frameCount; i++) {
        if (fileNames[i] == "." || fileNames[i] == "..")
            continue;
        RModel* model = new RModel(animationDir + "/" + fileNames[i], false);
        _models.push_back(model);
    }
    _model = _models.at(0)->inner();
    UnloadDirectoryFiles();
}

RFrameAnimModel::RFrameAnimModel(
    const std::string& animationDir, const RTexture2D& texture)
    : RFrameAnimModel(animationDir)
{
    for (auto model : _models) {
        model->setMaterialTexture(0, texture);
    }
}

RFrameAnimModel::~RFrameAnimModel()
{
    for (auto& model : _models) {
        // do not delete the currently loaded model, since it will
        // be deleted by the ~RModel destructor anyway
        if (model->inner().meshes == _model.meshes) {
            memset(&model->inner(), 0, sizeof(model->inner()));
        }
        delete model;
    }
}

void RFrameAnimModel::setFrame(int frame)
{
    _model = _models.at(frame)->inner();
    _frame = frame;
    _finished = false;
}

int RFrameAnimModel::getFrame() const { return _frame; }

bool RFrameAnimModel::isPaused() const { return _paused; }

void RFrameAnimModel::setPaused(bool paused) { _paused = paused; }

bool RFrameAnimModel::isLoop() const { return _loop; }

float RFrameAnimModel::getTimePerFrame() const { return _timePerFrame; }

void RFrameAnimModel::setLoop(bool loop)
{
    _loop = loop;
    _finished = false;
}

bool RFrameAnimModel::isFinished() const { return _loop ? false : _finished; }

void RFrameAnimModel::setTimePerFrame(float timePerFrame)
{
    _timePerFrame = timePerFrame;
}

int RFrameAnimModel::getFrameCount() const { return _models.size(); }

void RFrameAnimModel::update()
{
    if (_paused)
        return;
    _time += GetFrameTime();
    if (_time > _timePerFrame) {
        _frame = (_frame + 1) % _models.size();
        _time = 0.f;
        if (!_loop && _frame == 0) {
            setFrame(_models.size() - 1);
            _finished = true;
        } else {
            setFrame(_frame);
        }
    }
}

}
