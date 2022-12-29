package aspose_snippets.java;

public class Split_PDF {
    public static void Execute() {
        String pathSource = "../../TestData/test.pdf";
        var pdfEditor = new com.aspose.pdf.PdfFileEditor();
        int beg = 1, end = 1;
    
        var doc = new com.aspose.pdf.Document(pathSource);
        end = doc.Pages.Count;
    
        if(end > 1)
        {
            end /= 2;
        }
    
        pdfEditor.Extract(pathSource, beg, end, "half.pdf");
    }
}
