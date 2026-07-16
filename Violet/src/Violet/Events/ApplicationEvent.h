#pragma once

#include "Event.h"

namespace Violet {
	class VIOLET_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : width_(width), height_(height) {}

		inline unsigned int GetWidth()  const { return width_;  }
		inline unsigned int GetHeight() const { return height_; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width_ << ", " << height_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WIN_RESIZE)
		EVENT_CLASS_CATEGORY(EVENT_CAT_APPLICATION)

	private:
		unsigned int width_, height_;
	};

	class VIOLET_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WIN_CLOSE)
		EVENT_CLASS_CATEGORY(EVENT_CAT_APPLICATION)
	};

	class VIOLET_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(APP_TICK)
		EVENT_CLASS_CATEGORY(EVENT_CAT_APPLICATION)
	};

	class VIOLET_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(APP_UPDATE)
		EVENT_CLASS_CATEGORY(EVENT_CAT_APPLICATION)
	};

	class VIOLET_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(APP_RENDER)
		EVENT_CLASS_CATEGORY(EVENT_CAT_APPLICATION)
	};
}