package aspose_snippets.java;

public class Split_TXT {
    public static void Execute() {
        const string pathSource = "../../TestData/test.txt";
        var pdfEditor = new com.aspose.pdf.PdfFileEditor();

        var doc = new com.aspose.pdf.Document(pathSource, new com.aspose.pdf.TxtLoadOptions());
        //save input text to pdf to file
        doc.Save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);

        MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");
        int index = 1;
        for(var ms : pages)
        {
            var page = new com.aspose.pdf.Document(ms);
            var textAbsorber = new com.aspose.pdf.TextAbsorber();
            page.Pages.Accept(textAbsorber);
            string extractedText = textAbsorber.Text;
            File.WriteAllText("text_"+index+".txt", extractedText);
            index++;
        }
    }
}
