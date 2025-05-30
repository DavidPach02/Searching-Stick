#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Gameplay/StickCollection/StickCollectionController.h"
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
		delete(collection_controller);
	}

	void GameplayService::searchElement(SearchType search_type)
	{
		collection_controller->searchElement(search_type);
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

	Collection::SearchType GameplayService::getCurrentSearchType() { return collection_controller->getSearchType(); }

	int GameplayService::getNumOfSticks() { return collection_controller->getNumOfElements();  }
}