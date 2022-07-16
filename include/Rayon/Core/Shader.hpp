#pragma once

#include "raylib.h"
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief RShader class
 * @details Shader management functions
 */
class RShader {
public:
    /**
     * @brief Construct a new RShader object
     *
     * @param nil1
     * @param fsFileName
     */
    RShader(std::nullptr_t nil1, const std::string& fsFileName);
    RShader(const std::string& vsFileName, std::nullptr_t nil2);
    RShader(const std::string& vsFileName, const std::string& fsFileName);
    RShader(std::vector<char>& vsCode, std::vector<char>& fsCode);
    /**
     * @brief Destroy the RShader object
     *
     */
    ~RShader();

    /**
     * @brief Get the inner Shader object
     *
     * @return Shader&
     */
    Shader& inner();
    /**
     * @brief Get shader uniform location
     *
     * @param uniformName
     * @return int
     */
    int getUniformLocation(const std::string& uniformName);
    /**
     * @brief Get shader attribute location
     *
     * @param attribName
     * @return int
     */
    int getAttribLocation(const std::string& attribName);
    /**
     * @brief Set shader uniform value
     *
     * @param locIndex
     * @param value
     * @param uniformType
     * @return RShader&
     */
    RShader& setValue(int locIndex, const void* value, int uniformType);
    /**
     * @brief Set shader uniform value vector
     *
     * @param locIndex
     * @param value
     * @param uniformType
     * @param count
     * @return RShader&
     */
    RShader& setValueV(int locIndex, const void* value, int uniformType, int count);
    /**
     * @brief Set shader uniform value (matrix 4x4)
     *
     * @param locIndex
     * @param mat
     * @return RShader&
     */
    RShader& setValueMatrix(int locIndex, Matrix mat);
    /**
     * @brief Set shader uniform value for texture (sampler2d)
     *
     * @param locIndex
     * @param texture
     * @return RShader&
     */
    RShader& setValueTexture(int locIndex, Texture2D texture);
    /**
     * @brief Set shader uniform value with a given uniform name
     *
     * @param uniformName
     * @param value
     * @param uniformType
     * @return RShader&
     */
    RShader& setValue(
        const std::string& uniformName, const void* value, int uniformType);
    /**
     * @brief Set shader uniform value vector with a given uniform name
     *
     * @param uniformName
     * @param value
     * @param uniformType
     * @param count
     * @return RShader&
     */
    RShader& setValueV(const std::string& uniformName, const void* value,
        int uniformType, int count);
    /**
     * @brief Set shader uniform value (matrix 4x4) with a given uniform name
     *
     * @param uniformName
     * @param mat
     * @return RShader&
     */
    RShader& setValueMatrix(const std::string& uniformName, Matrix mat);
    /**
     * @brief Set shader uniform value for texture (sampler2d) with a given
     * uniform name
     *
     * @param uniformName
     * @param texture
     * @return RShader&
     */
    RShader& setValueTexture(const std::string& uniformName, Texture2D texture);
    /**
     * @brief Unload shader from GPU memory (VRAM)
     * @return RShader&
     */
    RShader& unload();

private:
    /**
     * @brief Map where all the uniform names will be stocked
     *
     */
    std::unordered_map<std::string, int> _uniformLocations;
    /**
     * @brief Shader object
     *
     */
    Shader _shader = { 0 };
    /**
     * @brief checker for shader state
     *
     */
    bool _loaded = false;
};
