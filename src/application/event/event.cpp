#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

EventDispatcher::EventDispatcher(Event &event) _UNIFIED_NOEXCEPT : _event(event) { }

UNIFIED_END_NAMESPACE
