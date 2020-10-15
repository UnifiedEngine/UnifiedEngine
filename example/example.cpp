#include <unified.hpp>

using namespace Unified;

class Example : public Application
{
public:

    bool OnUpdate() override {
        return poll_events();
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}