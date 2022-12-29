#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/CgmLoadOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void cgm_to_pdf()
{
	String pathSource1 = u"../../TestData/test.cgm";
	String pathSource2 = u"../../TestData/Second/test.cgm";

	// cgm files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, MakeObject<CgmLoadOptions>());
	auto secondDoc = MakeObject<Document>(pathSource2, MakeObject<CgmLoadOptions>());

	// create empty pdf document
	auto outputDoc = MakeObject<Document>();

	// set less memory usage with unload instead of fast performance
	outputDoc->set_EnableObjectUnload(true);

	for (auto const& page : firstDoc->get_Pages())
	{
		// add page from one document to another directly
		outputDoc->get_Pages()->CopyPage(page);
	}

	for (auto const& page : secondDoc->get_Pages())
	{
		// add page from one document to another directly
		outputDoc->get_Pages()->CopyPage(page);
	}

	// save result pdf to file
	outputDoc->Save(u"Merger_cgm_pdf.pdf", SaveFormat::Pdf);
}
