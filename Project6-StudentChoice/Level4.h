#ifndef LEVEL4_H
#define LEVEL4_H

#include "Level.h"

class Level4 : public Level {
	Mix_Chunk* popSfx;
	bool readSign = false;
	bool pathStart = false;
	bool pathClear = false;
	void die();
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program_regular, ShaderProgram* program_lit);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};


#endif // !LEVEL4_H