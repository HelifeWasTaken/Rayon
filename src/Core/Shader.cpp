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

RShader::RShader(std::vector<char>& vsCode, std::vector<char>& fsCode)
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

RShader& RShader::setValue(
    const std::string& uniformName, const void* value, int uniformType)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    return setValue(_uniformLocations[uniformName], value, uniformType);
}

RShader& RShader::setValue(int locIndex, const void* value, int uniformType)
{
    SetShaderValue(_shader, locIndex, value, uniformType);
    return *this;
}

RShader& RShader::setValueV(const std::string& uniformName, const void* value,
    int uniformType, int count)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    return setValue(_uniformLocations[uniformName], value, uniformType);
}

RShader& RShader::setValueV(
    int locIndex, const void* value, int uniformType, int count)
{
    SetShaderValueV(_shader, locIndex, value, uniformType, count);
    return *this;
}

RShader& RShader::setValueMatrix(const std::string& uniformName, Matrix mat)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    return setValueMatrix(_uniformLocations[uniformName], mat);
}

RShader& RShader::setValueMatrix(int locIndex, Matrix mat)
{
    SetShaderValueMatrix(_shader, locIndex, mat);
    return *this;
}

RShader& RShader::setValueTexture(const std::string& uniformName, Texture2D texture)
{
    if (_uniformLocations.find(uniformName) == _uniformLocations.end())
        _uniformLocations[uniformName] = getUniformLocation(uniformName);
    return setValueTexture(_uniformLocations[uniformName], texture);
}

RShader& RShader::setValueTexture(int locIndex, Texture2D texture)
{
    SetShaderValueTexture(_shader, locIndex, texture);
    return *this;
}

RShader& RShader::unload()
{
    if (_loaded) {
        UnloadShader(_shader);
        _loaded = false;
    }
    return *this;
}
