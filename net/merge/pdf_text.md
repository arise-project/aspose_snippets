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

//4. save content to text file
//create text absorber for extract text
textAbsorber = new Aspose.Pdf.Text.TextAbsorber();
outputDoc.Pages.Accept(textAbsorber);
string extractedText = textAbsorber.Text;
File.WriteAllText("Merger_pdf_text.txt", extractedText);
```