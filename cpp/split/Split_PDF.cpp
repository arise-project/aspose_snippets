#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PdfFileEditor.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void PDF()
{
    String pathSource = u"../../TestData/test.pdf";
    auto pdfEditor = MakeObject<PdfFileEditor>();
    int beg = 1, end = 1;

    auto stream = System::IO::File::Create(pathSource);
    auto doc = MakeObject<Document>(stream);
    end = doc->get_Pages()->get_Count()|;

    if(end > 1)
    {
        end /= 2;
    }

    pdfEditor->Extract(pathSource, beg, end, "./half.pdf");
}
