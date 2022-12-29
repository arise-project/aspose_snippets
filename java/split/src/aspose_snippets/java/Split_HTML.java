package aspose_snippets.java;

public class Split_HTML {
    public static void Execute() {
        String pathSource = "../../TestData/test.html";
        var doc = com.aspose.pdf.Document(pathSource, new com.aspose.pdf.HtmlLoadOptions());
        //save input html to pdf to file
        doc.Save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
    
        var pdfEditor = new com.aspose.pdf.PdfFileEditor();
        //slit first page
        pdfEditor.SplitFromFirst("test.pdf", 1, "test.pdf");
        var outputDoc = new Document("test.pdf");
        outputDoc.Save("first_page.html", com.aspose.pdf.SaveFormat.Html);
    }
}
