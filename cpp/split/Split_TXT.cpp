#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include "Aspose.PDF.Cpp/TxtLoadOptions.h"
#include "Aspose.PDF.Cpp/TextAbsorber.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void TXT()
{
    String pathSource = u"../../TestData/test.txt";
    auto pdfEditor = MakeObject<PdfFileEditor>();

    var doc = MakeObject<Document>(pathSource, MakeObject<TxtLoadOptions>());
    //save input text to pdf to file
    doc->Save("test.pdf", SaveFormat::Pdf);

    MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");
    int index = 1;
    foreach(var ms in pages)
    {
        auto page = MakeObject<Document>(ms);
        auto textAbsorber = MakeObject<TextAbsorber>();
        page->get_Pages()->Accept(textAbsorber);
        String extractedText = textAbsorber->Text;
        System::IO::File::WriteAllText(u"text_{index}.txt", extractedText);
        index++;
    }
}
