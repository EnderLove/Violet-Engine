#include "vtpch.h"

#include "LayerStack.h"

namespace Violet {
	LayerStack::LayerStack() {}

	LayerStack::~LayerStack() {
		for (Layer* layer : layers_) delete layer;
	}

	void LayerStack::PushLayer(Layer* layer) {
		layers_.emplace(layers_.begin() + layerInsertIndex_, layer); // Sets at the end of layers and updates the layerInsert_
		layerInsertIndex_++;
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		layers_.emplace_back(overlay); // Goes at the end of the vector
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(layers_.begin(), layers_.end(), layer);
		if (it != layers_.end()) {
			layers_.erase(it);
			layerInsertIndex_--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(layers_.begin(), layers_.end(), overlay);
		if (it != layers_.end()) {
			layers_.erase(it);
		}
	}

}