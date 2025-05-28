#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Main/GameService.h"


namespace Gameplay 
{
	using namespace Main;

	GameplayService::GameplayService() 
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService() 
	{
		delete(gameplay_controller);
	}

	void GameplayService::searchElement(SearchType search_type)
	{
		// TODO
	}

	void GameplayService::initialize() 
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update() 
	{
		if (GameService::getGameState() == GameState::GAMEPLAY) 
		{
			gameplay_controller->update();
		}
	}

	void GameplayService::render()
	{
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_controller->render();
		}
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
	}
}