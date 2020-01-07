#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/System/Core/AppDomain.hpp"
#include "Arp/System/Core/Singleton.hxx"
#include "Arp/System/Core/Library.h"
#include "Arp/System/Acf/LibraryBase.hpp"

namespace MyNamespace
{

using namespace Arp;
using namespace Arp::System::Acf;

class MyLibrary : public LibraryBase, public Singleton<MyLibrary>
{
public: // typedefs
    typedef Singleton<MyLibrary> SingletonBase;

public: // construction/destruction
    MyLibrary(AppDomain& appDomain);
    virtual ~MyLibrary() = default;

public: // static operations (called through reflection)
    static void Main(AppDomain& appDomain);

private: // deleted methods
    MyLibrary(const MyLibrary& arg) = delete;
    MyLibrary& operator= (const MyLibrary& arg) = delete;
};

extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain);

} // end of namespace MyNamespace
