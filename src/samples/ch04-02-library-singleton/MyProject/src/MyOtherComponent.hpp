﻿#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/System/Acf/ComponentBase.hpp"
#include "Arp/System/Acf/IApplication.hpp"
#include "Arp/System/Commons/Logging.h"

namespace MyNamespace
{

using namespace Arp;
using namespace Arp::System::Acf;

//#acfcomponent
class MyOtherComponent : public ComponentBase, private Loggable<MyOtherComponent>
{
public: // typedefs

public: // construction/destruction
    MyOtherComponent(IApplication& application, const String& name);
    virtual ~MyOtherComponent() = default;

public: // IComponent operations
    void Initialize() override;
    void SubscribeServices()override;
    void LoadSettings(const String& settingsPath)override;
    void SetupSettings()override;
    void PublishServices()override;
    void LoadConfig() override;
    void SetupConfig() override;
    void ResetConfig() override;
    void Dispose()override;
    void PowerDown()override;

private: // methods
    MyOtherComponent(const MyOtherComponent& arg) = delete;
    MyOtherComponent& operator= (const MyOtherComponent& arg) = delete;

public: // static factory operations
    static IComponent::Ptr Create(Arp::System::Acf::IApplication& application, const String& name);

};

inline IComponent::Ptr MyOtherComponent::Create(Arp::System::Acf::IApplication& application, const String& name)
{
    return IComponent::Ptr(new MyOtherComponent(application, name));
}

} // end of namespace MyNamespace
