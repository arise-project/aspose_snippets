#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/HtmlLoadOptions.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include "Aspose.PDF.Cpp/Facades/PdfFileEditor.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void HTML()
{
    String pathSource = u"../../TestData/test.html";
    auto doc = MakeObject<Document>(pathSource, MakeObject<HtmlLoadOptions>());
    //save input html to pdf to file
    doc->Save(u"test.pdf", SaveFormat::Pdf);

    auto pdfEditor = MakeObject<Aspose::Pdf::Facades::PdfFileEditor>();
    //slit first page
    pdfEditor->SplitFromFirst(u"test.pdf", 1, u"test.pdf");
    auto doc = MakeObject<Document>(u"test.pdf");
    doc->Save(u"html_first.html", SaveFormat::Html);
}