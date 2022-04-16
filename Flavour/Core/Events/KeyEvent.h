#pragma once

#include "Event.h"
#include <sstream>

/*
KEY EVENTS:
	KeyPressed,
	KeyReleased,
	KeyTyped,
*/

namespace Flavour
{
	typedef struct
	{
		unsigned int KEY_CODE;
		const char* KEY_VALUE;
	} KeyIdentifier;

	// Key Event 
	class API_EXPORTED KeyEvent : public Event
	{
	public:
		inline KeyIdentifier GetKeyIdentifier() const { return _keyIdentifier; }
		SET_EVENT_CATEGORY(KEYBOARD | INPUT)
	protected:
		KeyEvent(const KeyIdentifier keyIdentifier) : _keyIdentifier(keyIdentifier) {}
		KeyIdentifier _keyIdentifier;
	};

	// Key Pressed Event : Key Event
	class API_EXPORTED KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyIdentifier keyIdentifier, const unsigned short pressedTimes)
			: KeyEvent(keyIdentifier), _pressedTimes(pressedTimes) {}

		inline int GetPressedTimes() const { return _pressedTimes; }
		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event for key: " << _keyIdentifier.KEY_CODE << "[" << _pressedTimes << "x times pressed ]";
			return str.str();
		}

		SET_EVENT_TYPE(KeyPressed)
	private:
		unsigned short _pressedTimes;
	};

	// Key Released Event : Key Event
	class API_EXPORTED KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyIdentifier keyIdentifier)
			: KeyEvent(keyIdentifier) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event for key: " << _keyIdentifier.KEY_CODE;
			return str.str();
		}

		SET_EVENT_TYPE(KeyReleased)
	};

	// Key Typed Event : Key Event
	class API_EXPORTED KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyIdentifier keyIdentifier)
			: KeyEvent(keyIdentifier) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event for key: " << _keyIdentifier.KEY_CODE;
			return str.str();
		}

		SET_EVENT_TYPE(KeyTyped)
	};

}
