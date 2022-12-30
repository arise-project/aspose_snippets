#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include "Aspose.PDF.Cpp/Artifacts/ArtifactCollection.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void remove()
{
    String pathSource = u"../../TestData/test_with_watermark.pdf";
    auto doc = MakeObject<Document>(pathSource);

    if(doc->get_Pages()->idx_get(1)->get_Artifacts()->idx_get(1)->get_Subtype() == Aspose::Pdf::Artifact::ArtifactSubtype::Watermark)
    {
        doc->get_Pages()->idx_get(1)->get_Artifacts()->Delete(doc->get_Pages()->idx_get(1)->get_Artifacts()->idx_get(1));
    }

    //save result pdf to file
    doc->Save(u"test.pdf", SaveFormat::Pdf);
}
