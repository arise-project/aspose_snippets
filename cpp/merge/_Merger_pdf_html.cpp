#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/HtmlSaveOptions.h"

using namespace System;
using namespace Aspose::Pdf;

void pdf_to_html()
{
	String pathSource1 = u"../../TestData/test.pdf";
	String pathSource2 = u"../../TestData/Second/test.pdf";

	// read pdf file to Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1);
	auto secondDoc = MakeObject<Document>(pathSource2);

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

	auto opt1 = MakeObject<HtmlSaveOptions>();
	// embed css into a page
	opt1->PartsEmbeddingMode = Aspose::Pdf::HtmlSaveOptions::PartsEmbeddingModes::EmbedAllIntoHtml;
	// embed images into a page
	opt1->RasterImagesSavingMode = Aspose::Pdf::HtmlSaveOptions::RasterImagesSavingModes::AsEmbeddedPartsOfPngPageBackground;
	// enhance conversion of documents with backgrounds
	opt1->AntialiasingProcessing = Aspose::Pdf::HtmlSaveOptions::AntialiasingProcessingType::TryCorrectResultHtml;
	// use fixed layout render
	opt1->set_FixedLayout(true);
	outputDoc->Save(u"Merger_pdf_html.html", opt1);
}
