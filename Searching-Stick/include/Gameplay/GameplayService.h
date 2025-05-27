#pragma once
#include <SFML/System/String.hpp>

namespace Gameplay 
{
	enum class SearchType 
	{
		LINEAR_SEARCH,
		BINARY_SEARCH
	};

	class GameplayController;

	class GameplayService {
	private:
		GameplayController* gameplay_controller;
		static SearchType search_type;

	public:
		GameplayService();
		~GameplayService();

		void searchElement(SearchType search_type);
		void initialize();
		void update();
		void render();
		void reset();
	};
}