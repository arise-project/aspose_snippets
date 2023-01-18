```cs

//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//2. read pdf file to Aspose Document
firstDoc = new Aspose.Pdf.Document("1.pdf");
secondDoc = new Aspose.Pdf.Document("2.pdf");

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save pdf to TeX document
//save parsed artifacts, for example images to a directory
opt1 = new Aspose.Pdf.TeXSaveOptions
{
    OutDirectoryPath = "./test"
};
outputDoc.Save("Merger_pdf_tex.tex",opt1);

```