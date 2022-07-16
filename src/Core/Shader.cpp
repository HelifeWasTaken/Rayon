#include "Rayon/Core/Shader.hpp"

RShader::RShader(const std::string& vsFileName, const std::string& fsFileName)
{
    _shader = LoadShader(vsFileName.c_str(), fsFileName.c_str());
    _loaded = true;
}

RShader::RShader(std::nullptr_t, const std::string& fsFileName)
{
    _shader = LoadShader(0, fsFileName.c_str());
    _loaded = true;
}

RShader::RShader(const std::string& vsFileName, std::nullptr_t)
{
    _shader = LoadShader(vsFileName.c_str(), 0);
    _loaded = true;
}

RShader::RShader(std::vector<char> vsCode, std::vector<char> fsCode)
{
    _shader = LoadShaderFromMemory(vsCode.data(), fsCode.data());
    _loaded = true;
}

RShader::~RShader() { unload(); }

Shader& RShader::inner() { return _shader; }

int RShader::getUniformLocation(const std::string& uniformName)
{
    return GetShaderLocation(_shader, uniformName.c_str());
}

int RShader::getAttribLocation(const std::string& attribName)
{
    return GetShaderLocationAttrib(_shader, attribName.c_str());
}

void RShader::setValue(
    const std::string& uniformName, const void* value, int uniformType)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    setValue(_uniformLocations[uniformName], value, uniformType);
}

void RShader::setValue(int locIndex, const void* value, int uniformType)
{
    SetShaderValue(_shader, locIndex, value, uniformType);
}

void RShader::setValueV(const std::string& uniformName, const void* value,
    int uniformType, int count)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    setValue(_uniformLocations[uniformName], value, uniformType);
}

void RShader::setValueV(
    int locIndex, const void* value, int uniformType, int count)
{
    SetShaderValueV(_shader, locIndex, value, uniformType, count);
}

void RShader::setValueMatrix(const std::string& uniformName, Matrix mat)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    setValueMatrix(_uniformLocations[uniformName], mat);
}

void RShader::setValueMatrix(int locIndex, Matrix mat)
{
    SetShaderValueMatrix(_shader, locIndex, mat);
}

void RShader::setValueTexture(const std::string& uniformName, Texture2D texture)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    setValueTexture(_uniformLocations[uniformName], texture);
}

void RShader::setValueTexture(int locIndex, Texture2D texture)
{
    SetShaderValueTexture(_shader, locIndex, texture);
}

void RShader::unload()
{
    if (_loaded) {
        UnloadShader(_shader);
        _loaded = false;
    }
}
