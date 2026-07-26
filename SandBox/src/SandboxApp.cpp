#include <Violet.h>

class TempLayer : public Violet::Layer {
public:
	TempLayer() : Layer("TempLayer") {}

	void OnUpdate() override { 
		//if (Violet::Input::IsKeyPressed(VT_KEY_A)) 
			//VT_WARN("THE KEY {0} HAS BEEN PRESSED!!!", char(VT_KEY_A));
	}
	void OnEvent(Violet::Event& event) override { 
		//VT_TRACE("{0}", event);
		if (event.GetEventType() == Violet::EventType::KEY_PRESSED) {
			Violet::KeyPressEvent& e = (Violet::KeyPressEvent&)event;
			VT_WARN("KEY '{0}' PRESSED", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Violet::Application {
public:
	Sandbox() { 
		PushLayer(new TempLayer()); 
		PushOverlay(new Violet::ImGuiLayer());
	}
	~Sandbox() {}
};

Violet::Application* Violet::CreateApplication() {
	return new Sandbox();
}
