#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SvgLoadOptions.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void svg_to_pdf()
{
	String pathSource1 = u"../../TestData/test.svg";
	String pathSource2 = u"../../TestData/Second/test.svg";

	// Adust pdf page size to svg size
	auto opt1 = MakeObject<SvgLoadOptions>();
	opt1->set_AdjustPageSize(true);
	// SVG files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, opt1);

	// Use default pdf page size
	auto opt2 = MakeObject<SvgLoadOptions>();
	opt1->set_AdjustPageSize(false);
	auto secondDoc = MakeObject<Document>(pathSource2, opt2);

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
	outputDoc->Save(u"Merger_svg_pdf.pdf", SaveFormat::Pdf);
}
