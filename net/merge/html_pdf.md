```cs

//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document());

//2. html files can be parsed and loaded as Aspose Document
//set html encoding
//render all html to single large pdf page
opt1 = new Aspose.Pdf.HtmlLoadOptions
    {
        InputEncoding = "UTF-8",
        IsRenderToSinglePage = true
    };
firstDoc = new Aspose.Pdf.Document("1.html", opt1);
secondDoc = new Aspose.Pdf.Document("2.html", opt1);

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_html_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```