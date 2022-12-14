#include "Aspose.PDF.Cpp/PclLoadOptions.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void pcl_to_pdf()
{
	String pathSource1 = u"../../TestData/test.pcl";
	String pathSource2 = u"../../TestData/Second/test.pcl";

	auto opt1 = MakeObject<PclLoadOptions>();
	// suspend not critical errors
	opt1->SupressErrors = true;

	// pcl files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, opt1);

	auto opt2 = MakeObject<PclLoadOptions>();
	// suspend not critical errors
	opt2->SupressErrors = true;
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
	outputDoc->Save(u"Merger_pcl_pdf.pdf", SaveFormat::Pdf);
}
