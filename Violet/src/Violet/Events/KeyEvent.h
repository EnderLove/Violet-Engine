#pragma once

#include <sstream>

#include "Event.h"

namespace Violet {
	class VIOLET_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return keyCode_; }
		EVENT_CLASS_CATEGORY(EVENT_CAT_KEYBOARD | EVENT_CAT_INPUT);

	protected:
		KeyEvent(int keyCode) : keyCode_(keyCode) {}
		int keyCode_;
	};

	class VIOLET_API KeyPressEvent : public KeyEvent {
	public:
		KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), repeatCount_(repeatCount) {}

		inline int GetRepeatCount() const { return repeatCount_; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode_ << " (" << repeatCount_ << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KEY_PRESSED)

	private:
		int repeatCount_;
	};

	class VIOLET_API KeyReleaseEvent : public KeyEvent {
	public:
		KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << keyCode_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KEY_RELEASED)
	};
}