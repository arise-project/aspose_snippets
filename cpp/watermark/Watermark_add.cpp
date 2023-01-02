#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include "Aspose.PDF.Cpp/Artifacts/WatermarkArtifact.h"
#include "Aspose.PDF.Cpp/Artifacts/ArtifactCollection.h"
#include "Aspose.PDF.Cpp/HorizontalAlignment.h"
#include "Aspose.PDF.Cpp/VerticalAlignment.h"
#include "Aspose.PDF.Cpp/Text/TextState.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"


using namespace System;
using namespace Aspose::Pdf;

void add()
{
    String pathSource = u"../../TestData/test.pdf";
    String watermarkSource = u"../../TestData/test.jpg";
    auto doc = MakeObject<Document>(pathSource);

    auto artifact = MakeObject<WatermarkArtifact>();
    artifact->SetImage(watermarkSource);

    artifact->set_ArtifactHorizontalAlignment(Aspose::Pdf::HorizontalAlignment::Center);
    artifact->set_ArtifactVerticalAlignment(Aspose::Pdf::VerticalAlignment::Center);
    artifact->set_Rotation(15);
    artifact->set_Opacity(1);
    artifact->set_IsBackground(true);
    doc->get_Pages()->idx_get(1)->get_Artifacts()->Add(artifact);

    //save result pdf to file
    doc->Save(u"add_watermark.pdf",SaveFormat::Pdf);
}
