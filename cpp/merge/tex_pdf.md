#include "Aspose.PDF.Cpp/TeXLoadOptions.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void tex_to_pdf()
{
	String pathSource1 = u"../../TestData/test.tex";
	String pathSource2 = u"../../TestData/Second/test.tex";

	auto opt1 = MakeObject<TeXLoadOptions>();

	// Cancels ligatures in all fonts
	opt1->set_NoLigatures(false);
	// Rasterize scientific formulas to images
	opt1->set_RasterizeFormulas(true);
	// Print parsing steps details to console output
	opt1->set_ShowTerminalOutput(true);

	// TeX files can be parsed and loaded as Aspose Document
	System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1, opt1);

	auto opt2 = MakeObject<TeXLoadOptions>();

	// Set ligatures in all fonts
	opt2->set_NoLigatures(true);
	// Rasterize scientific formulas to images
	opt2->set_RasterizeFormulas(true);
	// Print parsing steps details to console output
	opt2->set_ShowTerminalOutput(true);
	auto secondDoc = MakeObject<Document>(pathSource2, opt2);

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
	outputDoc->Save(u"Merger_tex_pdf.pdf", SaveFormat::Pdf);
}
