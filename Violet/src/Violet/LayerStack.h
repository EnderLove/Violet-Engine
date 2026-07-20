#pragma once 

#include <vector>

#include "Core.h"
#include "Layer.h"

namespace Violet {
	class VIOLET_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return layers_.begin(); }
		std::vector<Layer*>::iterator end()   { return layers_.end();   }

	private:
		std::vector<Layer*> layers_;
		std::vector<Layer*>::iterator layerInsert_;

		// TODO : Consider changing (layerIsert_) to unsigned int to avoid memory reallocations
	};
}