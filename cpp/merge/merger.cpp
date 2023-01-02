#include "pch.h"
#include "merger.h"
#if __has_include("merger.g.cpp")
#include "merger.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::merge::implementation
{
    int32_t merger::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void merger::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void merger::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
