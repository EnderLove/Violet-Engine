#pragma once
		
#include "Event.h"

namespace Violet {
	class VIOLET_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(int x, int y) : mouseX_(x), mouseY_(y) {}

		inline float GetX() const { return mouseX_; }
		inline float GetY() const { return mouseY_; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX_ << ", " << mouseY_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MS_MOVED)
		EVENT_CLASS_CATEGORY(EVENT_CAT_MOUSE | EVENT_CAT_INPUT)

	private:
		float mouseX_, mouseY_;
	};

	class VIOLET_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(float xOffset, float yOffset) : xOffset_(xOffset), yOffset_(yOffset) {}

		inline float GetXOffset() const { return xOffset_; }
		inline float GetYOffset() const { return yOffset_; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent: " << xOffset_ << ", " << yOffset_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MS_SCROLLED)
		EVENT_CLASS_CATEGORY(EVENT_CAT_MOUSE | EVENT_CAT_INPUT)

	private:
		float xOffset_, yOffset_;
	};

	class VIOLET_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return button_; }
		EVENT_CLASS_CATEGORY(EVENT_CAT_MOUSE | EVENT_CAT_INPUT)

	protected:
		MouseButtonEvent(int button) : button_(button) {}
		int button_;
	};

	class VIOLET_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MS_BTN_PRESSED)
	};

	class VIOLET_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MS_BTN_RELEASED)
	};
}