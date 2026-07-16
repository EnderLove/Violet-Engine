#pragma once

#include "Violet/Core.h"
#include "Violet/Log.h"

namespace Violet {

	enum class EventType {
		NONE = 0,
		WIN_CLOSE, WIN_RESIZE, WIN_FOCUS, WIN_LOST_FOCUS, WIN_MOVED, // WINDOW EVENT TYPES 
		APP_TICK, APP_UPDATE, APP_RENDER,                            // APPPLICATION EVENT TYPES
		KEY_PRESSED, KEY_RELEASED,                                   // KEYBOARD EVENT TYPES
		MS_BTN_PRESSED, MS_BTN_RELEASED, MS_MOVED, MS_SCROLLED       // MOUSE EVENT TYPES
	};

	enum EventCategory {
		NONE = 0,
		EVENT_CAT_APPLICATION = BIT(0),
		EVENT_CAT_INPUT		  = BIT(1),
		EVENT_CAT_KEYBOARD	  = BIT(2),
		EVENT_CAT_MOUSE		  = BIT(3),
		EVENT_CAT_MOUSE_BTN   = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class VIOLET_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName()    const = 0;
		virtual int GetCategoryFlags()   const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

	protected:
		bool handled_ = false;
	};

	class EventDispatcher {
		template <typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) : event_(event) {}

		template <typename T>
		bool Dispatch(EventFn<T> func) {
			if (event_.GetEventType() == T::GetStaticType()) {
				event_.handled_ = func(static_cast<T&>(event_));
				//event_.handled_ = func(*(T*)&(event_));
				return true;
			}
			return false;
		}

	private:
		Event& event_;
	};

	inline std::ostream& operator << (std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}

template<typename T> // SPDLOG NEW VERSION NEED THIS FOR FORMAT
struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<Violet::Event, T>, char>>
	: fmt::ostream_formatter {
};