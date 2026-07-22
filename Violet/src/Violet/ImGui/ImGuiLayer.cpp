#include "vtpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"

#include "Platform/OpenGL/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Violet/Application.h"
#include "Violet/Events/MouseEvent.h"

namespace Violet {
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}
	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::OnAttach() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410 core");
	}

	void ImGuiLayer::OnDetach() {

	}

	void ImGuiLayer::OnUpdate() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = time_ > 0.0f ? (time - time_) : (1.0f / 60.0f);
		time_ = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrollEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleaseEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(VT_BIND_EVENT_FN(ImGuiLayer::OnWindowResizedEvent));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrollEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();
		return false;
	}

	// STILL NEED TO ADD KEY COMBOS (E.G CTRL + BACKSPACE)
	bool ImGuiLayer::OnKeyPressedEvent(KeyPressEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		ImGuiKey keyCode = (ImGuiKey)VioletKeyToImGuiKey(e.GetKeyCode());
		io.AddKeyEvent(keyCode, true);
		return false;
	}

	int ImGuiLayer::VioletKeyToImGuiKey(int keyCode) {
		switch (keyCode) {
		case GLFW_KEY_SPACE:        return ImGuiKey_Space;
		case GLFW_KEY_A:            return ImGuiKey_A;
		case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
		case GLFW_KEY_BACKSPACE:    return ImGuiKey_Backspace;
		case GLFW_KEY_UP:           return ImGuiKey_UpArrow;
		case GLFW_KEY_DOWN:         return ImGuiKey_DownArrow;
		case GLFW_KEY_RIGHT:        return ImGuiKey_RightArrow;
		case GLFW_KEY_LEFT:         return ImGuiKey_LeftArrow;
		case GLFW_KEY_LEFT_SHIFT:   return ImGuiKey_LeftShift;
		default:                    return ImGuiKey_None;
		}
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleaseEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		ImGuiKey keyCode = (ImGuiKey)VioletKeyToImGuiKey(e.GetKeyCode());
		io.AddKeyEvent(keyCode, false);
		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		int character = e.GetKeyCode();
		if (character > 0 && character < 0x10000)
			io.AddInputCharacter((unsigned int) character);
		return false;
	}

	bool ImGuiLayer::OnWindowResizedEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return false;
	}
}	