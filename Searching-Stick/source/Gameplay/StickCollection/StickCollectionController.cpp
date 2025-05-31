#include "Gameplay/StickCollection/StickCollectionController.h"
#include "Gameplay/StickCollection/StickCollectionView.h"
#include "Global/ServiceLocator.h"
#include "Gameplay/StickCollection/Stick.h"

namespace Gameplay
{
	namespace Collection
	{
		using namespace Global;

		StickCollectionController::StickCollectionController()
		{
			collection_view = new StickCollectionView();
			collection_model = new StickCollectionModel();
		}

		StickCollectionController::~StickCollectionController()
		{
			delete(collection_view);
			delete(collection_model);
		}

		void StickCollectionController::initialize()
		{
			collection_view->initialize();
			collection_model->initialize();
			initializeSticks();
			updateSticksPosition();
		}

		void StickCollectionController::update()
		{

		}

		void StickCollectionController::render()
		{

		}

		void StickCollectionController::reset()
		{

		}

		void StickCollectionController::searchElement(SearchType search_type)
		{

		}

		SearchType StickCollectionController::getSearchType() { return search_type; }

		int StickCollectionController::getNumOfElements() { return sticks.size();  }

		void StickCollectionController::initializeSticks()
		{
			// Calculate rect width
			float rect_width = calculateStickWidth();

			// Create the sticks
			for (int i = 0; i < collection_model->number_of_elements; i++)
			{
				// Calculate height
				float rect_height = calculateStickHeight(i);

				// Set size of rect
				sf::Vector2f rect_size = sf::Vector2f(rect_width, rect_height);

				// Initialize rect
				sticks[i]->stick_view->initialize(rect_size, sf::Vector2f(0, 0), 0, collection_model->found_element_color);
			}
		}

		float StickCollectionController::calculateStickWidth()
		{
			// Get width of window
			float total_space = static_cast<float>(ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x);

			// Calculate total spacing 
			float total_spacing = collection_model->space_percentage * total_space;

			// Caculate space between sticks
			float space_between = total_spacing / (collection_model->number_of_elements - 1);
			collection_model->setElementSpacing(space_between);

			// Calculate space for all rect
			float rect_space = total_space - total_spacing;

			// Calculate width for each rect
			float rect_width = rect_space / collection_model->number_of_elements;

			return rect_width;
		}

		void StickCollectionController::updateSticksPosition()
		{

		}

		void StickCollectionController::resetSticksColor()
		{

		}

		void StickCollectionController::initializeSticksArray()
		{

		}

		float StickCollectionController::calculateStickHeight(int array_pos)
		{
			return (static_cast<float>(array_pos + 1) / collection_model->number_of_elements) * collection_model->max_element_height;
		}

		void StickCollectionController::destroy()
		{

		}
	}
}