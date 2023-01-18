```cs

//save input text to pdf to file
pdfEditor = new PdfFileEditor();
var doc = new Document("1.txt", new TxtLoadOptions());
doc.Save("test.pdf", SaveFormat.Pdf);

MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");

int index = 1;
foreach(var ms in pages)
{
    page = new Document(ms);
    var textAbsorber = new TextAbsorber();
    page.Pages.Accept(textAbsorber);
    string extractedText = textAbsorber.Text;
    File.WriteAllText("text_"+index+".txt", extractedText);
    index++;
}

```