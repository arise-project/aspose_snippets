
outputDoc = new Aspose.Pdf.Document();

//read pdf file to Aspose Document
firstDoc = new Aspose.Pdf.Document("1.pdf");
secondDoc = new Aspose.Pdf.Document("2.pdf");

//add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//save pdf to Microsoft PowerPoint
//save all content on page as single image
opt1 = new Aspose.Pdf.PptxSaveOptions
{
    lidesAsImages = true
};
outputDoc.Save("Merger_pdf_pptx.pptx",opt1);