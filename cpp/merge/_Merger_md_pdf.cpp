#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/MdLoadOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void md_to_pdf()
{
	String pathSource1 = u"../../TestData/test.md";
	String pathSource2 = u"../../TestData/Second/test.md";

	// Markdown files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, MakeObject<MdLoadOptions>());
	auto secondDoc = MakeObject<Document>(pathSource2, MakeObject<MdLoadOptions>());

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
	outputDoc->Save(u"Merger_md_pdf.pdf", SaveFormat::Pdf);
}
