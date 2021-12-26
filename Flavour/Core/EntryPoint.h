#pragma once
#include "Application.h"
extern Flavour::Application *Flavour::CreateApplication();

int main(int argc, char **argv) {
    Flavour::Application *app = Flavour::CreateApplication();
    app->Run();
    delete app;
}