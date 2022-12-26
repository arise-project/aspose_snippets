#include "Aspose.PDF.Cpp\PdfLicense.h"
#include "Aspose.PDF.Cpp\PdfLicense.h"
#include "Aspose.PDF.Cpp\PdfLicense.h"
#include <iostream>

#include "Aspose.PDF.Cpp/PdfLicense.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void bmp_to_pdf()
{
    auto lic = MakeObject<License>();
    lic->SetLicense(u"../../test.lic");
}

