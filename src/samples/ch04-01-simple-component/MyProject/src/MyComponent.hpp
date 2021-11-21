#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/System/Acf/ComponentBase.hpp"
#include "Arp/System/Acf/IApplication.hpp"

namespace MyNamespace
{

using namespace Arp;
using namespace Arp::System::Acf;

//#acfcomponent
class MyComponent : public ComponentBase
{
public: // typedefs

public: // construction/destruction
    MyComponent(IApplication& application, const String& name);
    virtual ~MyComponent() = default;

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
    MyComponent(const MyComponent& arg) = delete;
    MyComponent& operator= (const MyComponent& arg) = delete;

public: // static factory operations
    static IComponent::Ptr Create(Arp::System::Acf::IApplication& application, const String& name);

};

inline IComponent::Ptr MyComponent::Create(Arp::System::Acf::IApplication& application, const String& name)
{
    return IComponent::Ptr(new MyComponent(application, name));
}

} // end of namespace MyNamespace
