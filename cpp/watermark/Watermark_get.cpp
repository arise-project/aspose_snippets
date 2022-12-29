#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void get()
{
    const string pathSource = "../../TestData/test_with_watermark.pdf";
    auto doc = MakeObject<Document>(pathSource);

    if(doc->get_Pages()->idx_get(1)->get_Artifact()->idx_get(1)->set_Subtype(Aspose.Pdf.Artifact.ArtifactSubtype.Watermark))
    {
        auto fs = System::IO::FileStream::OpenRead("test.jpg");
        doc->get_Pages->idx_get(1)->get_Artifacts->idx_get(1)->get_Image()->Save(fs);
        fs->Flush();
        fs->Close();
    }
}
