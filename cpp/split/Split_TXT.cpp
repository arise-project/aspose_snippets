#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include "Aspose.PDF.Cpp/TxtLoadOptions.h"
#include "Aspose.PDF.Cpp/Text/TextAbsorber.h"
#include "Aspose.PDF.Cpp/Facades/PdfFileEditor.h"

#include "system/string.h"
#include "system/io/file.h"
#include "system/io/memory_stream.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void TXT()
{
    String pathSource = u"../../TestData/test.txt";
    auto pdfEditor = MakeObject<Aspose::Pdf::Facades::PdfFileEditor>();

    auto doc = MakeObject<Document>(pathSource, MakeObject<TxtLoadOptions>());
    //save input text to pdf to file
    doc->Save(u"test.pdf", SaveFormat::Pdf);

    System::ArrayPtr<System::SharedPtr<System::IO::MemoryStream>> pages =  pdfEditor->SplitToPages(u"test.pdf");
    int index = 1;
    for(auto ms : pages)
    {
        auto page = MakeObject<Document>(ms);
        auto textAbsorber = MakeObject<Aspose::Pdf::Text::TextAbsorber>();
        page->get_Pages()->Accept(textAbsorber);
        String extractedText = textAbsorber->get_Text();
        System::IO::File::WriteAllText(String::Format(u"text_{0}.txt", index), extractedText);
        index++;
    }
}
