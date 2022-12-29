package aspose_snippets.java;

public class Split_HTML {
    public static void Execute() {
const string pathSource = "../../TestData/test.html";
            using (var doc = new Document(pathSource, new HtmlLoadOptions()))
            {
                //save input html to pdf to file
                doc.Save("test.pdf", SaveFormat.Pdf);
            }

            var pdfEditor = new PdfFileEditor();
            pdfEditor.SplitFromFirst("test.pdf", 1, "test.pdf");
            using (var doc = new Document("test.pdf"))
            {
                doc.Save("first_page.html", SaveFormat.Html);
            }
    }
}
