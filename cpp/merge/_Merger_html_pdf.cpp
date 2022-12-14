#include "Aspose.PDF.Cpp/HtmlLoadOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void html_to_pdf()
{
	String pathSource1 = u"../../TestData/test.html";
	String pathSource2 = u"../../TestData/Second/test.html";

	auto opt1 = MakeObject<HtmlLoadOptions>();

	// set html encoding
	opt1->set_InputEncoding(u"UTF-8");
	// render all html to single large pdf page
	opt1->set_IsRenderToSinglePage(true);

	// html files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, opt1);

	auto opt2 = MakeObject<HtmlLoadOptions>();
	// set html encoding
	opt2->set_InputEncoding(u"UTF-8");
	// split html content to pdf pages
	opt2->set_IsRenderToSinglePage(false);

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
	outputDoc->Save(u"Merger_html_pdf.pdf", SaveFormat::Pdf);
}
