#pragma once

namespace Gameplay 
{
	class GameplayController;

	class GameplayView {
	public:
		GameplayView();
		~GameplayView();

		void initialize(GameplayController* gameplay_controller);
		void update();
		void render();
	};
}