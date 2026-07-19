#include <Violet.h>

class TempLayer : public Violet::Layer {
public:
	TempLayer() : Layer("TempLayer") {}

	void OnUpdate() override { VT_INFO("TempLayer::Update"); }
	void OnEvent(Violet::Event& event) override { VT_TRACE("{0}", event); }
};

class Sandbox : public Violet::Application {
public:
	Sandbox() { PushLayer(new TempLayer()); }
	~Sandbox() {}
};

Violet::Application* Violet::CreateApplication() {
	return new Sandbox();
}
