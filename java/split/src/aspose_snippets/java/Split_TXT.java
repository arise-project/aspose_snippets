package aspose_snippets.java;

public class Split_TXT {
    public static void Execute() {
        const string pathSource = "../../TestData/test.txt";
        var pdfEditor = new PdfFileEditor();

        var doc = new Document(pathSource, new TxtLoadOptions());
        //save input text to pdf to file
        doc.Save("test.pdf", SaveFormat.Pdf);

        MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");
        int index = 1;
        foreach(var ms in pages)
        {
            var page = new Document(ms);
            var textAbsorber = new TextAbsorber();
            page.Pages.Accept(textAbsorber);
            string extractedText = textAbsorber.Text;
            File.WriteAllText("text_"+index+".txt", extractedText);
            index++;
        }
    }
}
