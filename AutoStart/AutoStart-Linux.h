#pragma once

#include <string>
#include "AutoStart.h"

class AutoStart: public AutoStartInterface
{
public:
    AutoStart(std::string name);

    bool        DisableAutoStart();
    bool        EnableAutoStart(AutoStartInfo autostart_info);
    bool        IsAutoStartEnabled();
    std::string GetExePath();

private:
    void        InitAutoStart(std::string name);
    std::string GenerateDesktopFile(AutoStartInfo autostart_info);
};
