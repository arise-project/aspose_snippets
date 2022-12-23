#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/IO/ConvertStrategies/PdfFormat.h"
#include "Aspose.PDF.Cpp/PdfFormatConversionOptions.h"
#include "Aspose.PDF.Cpp/TeXLoadOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

#include "system/string.h"

using namespace System;
using namespace Aspose::Pdf;

void tex_to_pdf()
{
    auto pathSource1 = u"../../TestData/test.tex";
    auto pathSource2 = u"../../TestData/Second/test.tex";

    var opt1 = MakeObject<TeXLoadOptions>();

    // Cancels ligatures in all fonts
    opt1->NoLigatures = false;
    // Rasterize scientific formulas to images
    opt1->RasterizeFormulas = true;
    // Print parsing steps details to console output
    opt1->ShowTerminalOutput =true;

    // TeX files can be parsed and loaded as Aspose Document
    var firstDoc = MakeObject<Document>(pathSource1, opt1);

    var opt2 = new MakeObject<TeXLoadOptions>();

    // Set ligatures in all fonts
    opt2->NoLigatures = false;
    // Rasterize scientific formulas to images
    opt2->RasterizeFormulas = true;
    // Print parsing steps details to console output
    opt2->tShowTerminalOutput = true;
    var secondDoc = MakeObject<Document>(pathSource2, opt2);

    auto outputDoc = MakeObject<Document>();

    // set less memory usage with unload instead of fast performance
    outputDoc->EnableObjectUnload = true;

    for (int i = 0; i < firstDoc->get_Pages()->get_Count(); i++)
    {
        auto page = firstDoc->get_Pages()->get_Item(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->Add(page);
    }

    for (int i = 0; i < secondDoc->get_Pages()->get_Count(); i++)
    {
        auto page = secondDoc->get_Pages()->get_Item(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->Add(page);
    }

    // save result pdf to file
    outputDoc->Save("test.pdf", SaveFormat::Pdf);
}
