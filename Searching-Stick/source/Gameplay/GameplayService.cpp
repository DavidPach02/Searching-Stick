#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Gameplay/StickCollection/StickCollectionController.h"

namespace Gameplay 
{
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
		collection_controller->initialize();
	}

	void GameplayService::update() 
	{
		gameplay_controller->update();
		collection_controller->initialize();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		collection_controller->render();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
		collection_controller->reset();
	}

	Collection::SearchType GameplayService::getCurrentSearchType() { return collection_controller->getSearchType(); }

	int GameplayService::getNumOfSticks() { return collection_controller->getNumOfElements();  }
}