#include <fstream>
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Text/TextAbsorber.h"

using namespace std;
using namespace System;
using namespace Aspose::Pdf;

void pdf_to_text()
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

	// create text absorber for extract text
	auto textAbsorber = MakeObject<Aspose::Pdf::Text::TextAbsorber>();
	outputDoc->get_Pages()->Accept(textAbsorber);
	auto extractedText = textAbsorber->get_Text();

	fstream file;
	file.open("Merger_pdf_text.txt", ios::out);
	file << extractedText;
	file.close();
}
