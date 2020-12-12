#ifndef UTIL_H
#define UTIL_H

#define GL_SILENCE_DEPRECATION
#ifdef _WINDOWS
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES 1
#include <vector>
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Text.h"
class Util {
public:
	static GLuint LoadTexture(const char* filePath);
	static void DrawText(ShaderProgram* program, GLuint fontTextureID, std::string
		text, float size, float spacing, glm::vec3 position);
	static void DisplayText(ShaderProgram* program, GLuint fontTextureID, const Text& text);
	static void DisplayText(ShaderProgram* program, GLuint fontTextureID, const std::vector<Text>& texts);
	static void DisplayText(ShaderProgram* program, GLuint fontTextureID, const Text& text, float xOffset);
};

#endif // !UTIL_H
