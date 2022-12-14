package aspose_snippets.java;

public class Split_HTML {
    public void Execute() {
        String pathSource = "../../TestData/test.html";
        var doc = new com.aspose.pdf.Document(pathSource, new com.aspose.pdf.HtmlLoadOptions());
        //save input html to pdf to file
        doc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
    
        var pdfEditor = new com.aspose.pdf.facades.PdfFileEditor();
        //slit first page
        pdfEditor.splitFromFirst("test.pdf", 1, "test.pdf");
        var outputDoc = new com.aspose.pdf.Document();
        outputDoc.save("first_page.html", com.aspose.pdf.SaveFormat.Html);
    }
}
