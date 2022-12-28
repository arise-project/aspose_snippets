#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/PsLoadOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void eps_to_pdf()
{
	String pathSource1 = u"../../TestData/test.eps";
	String pathSource2 = u"../../TestData/Second/test.eps";

	// eps files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, MakeObject<PsLoadOptions>());
	System::SharedPtr<Document> secondDoc = MakeObject<Document>(pathSource2, MakeObject<PsLoadOptions>());

	// create empty pdf document
	System::SharedPtr<Document> outputDoc = MakeObject<Document>();

	// set less memory usage with unload instead of fast performance
	outputDoc->set_EnableObjectUnload(true);

	for (int i = 1; i < firstDoc->get_Pages()->get_Count(); i++)
	{
		auto page = firstDoc->get_Pages()->idx_get(i);
		// add page from one document to another directly
		outputDoc->get_Pages()->CopyPage(page);
	}

	for (int i = 1; i < secondDoc->get_Pages()->get_Count(); i++)
	{
		auto page = secondDoc->get_Pages()->idx_get(i);
		// add page from one document to another directly
		outputDoc->get_Pages()->CopyPage(page);
	}

	// save result pdf to file
	outputDoc->Save(u"test.pdf", SaveFormat::Pdf);
}
