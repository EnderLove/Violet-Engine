#include "vtpch.h"

#include "LayerStack.h"

namespace Violet {
	LayerStack::LayerStack() { layerInsert_ = layers_.begin(); } // Beware of new vector allocations 

	LayerStack::~LayerStack() {
		for (Layer* layer : layers_) delete layer;
	}

	void LayerStack::PushLayer(Layer* layer) {
		layerInsert_ = layers_.emplace(layerInsert_, layer); // Sets at the end of layers and updates the layerInsert_
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		layers_.emplace_back(overlay); // Goes at the end of the vector
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(layers_.begin(), layers_.end(), layer);
		if (it != layers_.end()) {
			layers_.erase(it);
			layerInsert_--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(layers_.begin(), layers_.end(), overlay);
		if (it != layers_.end()) {
			layers_.erase(it);
		}
	}

}