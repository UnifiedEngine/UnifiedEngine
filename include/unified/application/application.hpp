#include <unified/application/window/window.hpp>

#ifndef UNIFIED_APPLICATION_HPP
#define UNIFIED_APPLICATION_HPP

namespace Unified
{
    class Application : public Window
    {
    public:

        Application(string title = "Unified", VideoMode mode = VideoMode(800, 600), u32 style = Window::Floating);
        virtual ~Application();

        void run();

    protected:

        virtual void OnCreate();
        virtual bool OnUpdate() = 0;
        virtual void OnClose();

    };

    Application *CreateApplication();
}

#endif